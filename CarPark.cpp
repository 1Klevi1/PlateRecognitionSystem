#include "Vehicle.h"
#include <fstream>
#include <sstream>
#include <iostream>
 /**
 * @file CarPark.cpp
 * @brief CarPark method implementation
 */

//
// Created by Klevi on 22/11/2023.
//

int CarPark::populateArrays(std::string filename) {
    // Open the input file
    std::ifstream inputFile(filename);
    std::string line;

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the input file." << std::endl;
        return 1;
    }

    // Read each line from the file
    while (std::getline(inputFile, line)) {
        // Parse each line into vehicle information
        std::istringstream iss(line);
        std::string type, plate, action, time;

        // Check if the line contains a date or a vehicle entry
        if ((iss >> std::ws).peek() == '0' || std::isdigit(iss.peek())) {
            iss >> date;
        }else{
            iss >> type;
            iss >> plate;
            iss >> action;
            iss >> time;

        }
        Vehicle* vehicleInstance = new Vehicle(date, type, plate, action, time);

        // Check if the date is not empty before adding to the array
        if (vehicleInstance->getVehicleDate() != "") {
            vehicleNumber.push_back(vehicleInstance);
        }

    }
    // Group vehicles by date
    groupVehiclesByDate(vehicleNumber);
    inputFile.close();
    return 0;
}

void CarPark::groupVehiclesByDate(std::vector<Vehicle*> vehicleNumber){
    for ( auto* vehicle : vehicleNumber) {
        bool foundGroup = false;
        for (auto &group: groupedByDate) {
            if (!group.empty() && group[0]->getVehicleDate() == vehicle->getVehicleDate()) {
                group.push_back(vehicle);
                foundGroup = true;
                break;
            }
        }
        if (!foundGroup) {
            groupedByDate.push_back({vehicle});
        }
    }
}

std::vector<std::string> CarPark::populateDateArray(std::vector<std::vector<Vehicle*>> groupedByDate){
    std::string prevDate;
    std::vector<std::string> datesArray;
    for (auto& group : groupedByDate) {
        for (auto& vehicle : group) {
            if(vehicle->getVehicleDate() != prevDate){
                prevDate = vehicle->getVehicleDate();
                datesArray.push_back(vehicle->getVehicleDate());
            }
        }
    }
    return datesArray;
}

void CarPark::createFiles() {

    std::string prevDate;   ///< Variable to store the previous date processed.
    std::ofstream outputFileChanged;     ///< Output file stream for writing data.
    std::vector<std::string> datesNumber = populateDateArray(groupedByDate);    ///< Vector to store unique dates.

    // Process each group of vehicles by date
    for (auto& group : groupedByDate) {
        std::vector<Car> carArray;  ///< Vector to store car instances for a specific date.
        std::vector<Van> vanArray;  ///< Vector to store van instances for a specific date.

        // Process each unique date
        for (auto& date : datesNumber){
            std::string outputFileFormat = date.substr(0, 2) + date.substr(3, 2) + date.substr(6, 4);

            // Close the previous file before opening a new one
            if (outputFileChanged.is_open()) {
                outputFileChanged.close();
            }

            // Open the file
            outputFileChanged.open(outputFileFormat + ".dat");

            int carTurned = 0;  ///< Variable to count turned away cars.
            int vanTurned = 0;  ///< Variable to count turned away vans.

            // Process each vehicle in the group
            for (auto& vehicle : group) {
                // Check vehicle type and add to corresponding array
                if (vehicle->getType() == "car") {
                    if(carArray.size() < 1000){
                        Car carInstance(vehicle->getVehicleDate(), vehicle->getType(),
                                        vehicle->getPlateNumber(), vehicle->getAction(),
                                        vehicle->getTime(), 1.0);
                        carArray.push_back(carInstance);
                    }else{
                        carTurned++;
                    }
                } else if (vehicle->getType() == "van") {
                    if(vanArray.size()< 20){
                        Van vanInstance(vehicle->getVehicleDate(), vehicle->getType(),
                                        vehicle->getPlateNumber(), vehicle->getAction(),
                                        vehicle->getTime(), 1.50);
                        vanArray.push_back(vanInstance);
                    }else{
                        vanTurned++;
                    }
                }
            }

            // Write information to the file
            outputFileChanged<< "Date: " << date<< std::endl;
            outputFileChanged<< calculateTotalTakingsForDay(carArray,vanArray) ;
            outputFileChanged<< getTotalNumberOfEachVehicleType(carArray,vanArray);
            outputFileChanged<< calculateTotalTakingsForEachVehicleType(carArray,vanArray);
            outputFileChanged<< "Cars turned away are: " << carTurned << std::endl;
            outputFileChanged<< "Vans turned away are: " << vanTurned << std::endl;

            // Remove the processed date from the vector
            datesNumber.erase(datesNumber.begin() + 0);
            outputFileChanged.close();
            break;  // Exit after processing the first date
        }
    }
}

void CarPark::startProgram(std::string FileName){
    populateArrays(FileName);
    createFiles();
}

 std::string CarPark::calculateTotalTakingsForDay(std::vector<Car> car, std::vector<Van> van){
    float result = 0;
    if(car.empty() && van.empty()){
        return "Total takings for the day are 0\n";
    }
    for(auto& car1 : car){
            result += car1.getPrice();
    }
     for(auto& van1 : van){
             result += van1.getPrice();
     }
     return "Total takings for the day are " + std::to_string(result) + "\n";
}

std::string CarPark::getTotalNumberOfEachVehicleType(std::vector<Car> car, std::vector<Van> van){

    return "Total number of Cars for the day are " + std::to_string(car.size())
    + " and total of Vans for the day are " + std::to_string(van.size())+ "\n";
}

std::string CarPark::calculateTotalTakingsForEachVehicleType(std::vector<Car> car, std::vector<Van> van){
    float carResult = 0;
    float vanResult = 0;
    if (car.empty() && van.empty()){
        return "Total takings for the Cars are 0"
               " and total takings for the Vans are 0\n";
    }
    for(auto& car1 : car){
        carResult += car1.getPrice();
    }
    for(auto& van1 : van){
        vanResult += van1.getPrice();
    }
    return "Total takings for the Cars are " + std::to_string(carResult)
           + " and total takings for the Vans are " + std::to_string(vanResult)+ "\n";
}

std::string CarPark::getDate(){ return date; }

void CarPark::setDate(std::string value){ date = value; }

void CarPark::setVehicleNumber(std::vector<Vehicle*> vehicles ){ vehicleNumber = vehicles; }

std::vector<Vehicle *> &CarPark::getVehicleNumber(){ return vehicleNumber; }

std::vector<std::vector<Vehicle *>> &CarPark::getGroupedByDate(){ return groupedByDate; }
