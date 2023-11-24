//
// Created by Klevi on 22/11/2023.
//
#include "Vehicle.h"
#include <fstream>
#include <sstream>
#include <iostream>
int CarPark::populateArrays(std::string filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Vehicle vehicle("", "", "","", "");
        std::string type, plate, action, time;
        if ((iss >> std::ws).peek() == '0' || std::isdigit(iss.peek())) {
            iss >> date;
        }else{
            iss >> type;
            vehicle.setType(type);
            iss >> plate;
            vehicle.setPlateNumber(plate);
            iss >> action;
            vehicle.setAction(action);
            iss >> time;
            vehicle.setTime(time);
            vehicle.setVehicleDate(date);
        }
        Vehicle* vehicleInstance = new Vehicle(vehicle.getVehicleDate(), vehicle.getType(),
                                               vehicle.getPlateNumber(), vehicle.getAction(),
                                               vehicle.getTime());
        vehicleNumber.push_back(vehicleInstance);
    }
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
    inputFile.close();
    return 0;
}

void CarPark::createFiles() {

    std::string prevDate;
    std::ofstream outputFileChanged;
    std::vector<std::string> datesNumber;
    int carTurned = 0;
    int vanTurned = 0;
    for (auto& group : groupedByDate) {
        for (auto& vehicle : group) {
            if(vehicle->getVehicleDate() != prevDate){
                prevDate = vehicle->getVehicleDate();
                datesNumber.push_back(vehicle->getVehicleDate());
            }
        }}

    groupedByDate.erase(groupedByDate.begin());
    for (auto& group : groupedByDate) {
        std::vector<Car> carArray;
        std::vector<Van> vanArray;
        for (auto& date : datesNumber){
            std::string outputFileFormat = date.substr(0, 2) + date.substr(3, 2) + date.substr(6, 4);

            // Close the previous file before opening a new one
            if (outputFileChanged.is_open()) {
                outputFileChanged.close();
            }

            // Open the file
            outputFileChanged.open(outputFileFormat + ".dat");

            for (auto& vehicle : group) {
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
            outputFileChanged<< "Date: " << date<< std::endl;
            outputFileChanged<< calculateTotalTakingsForDay(carArray,vanArray) ;
            outputFileChanged<< getTotalNumberOfEachVehicleType(carArray,vanArray);
            outputFileChanged<< calculateTotalTakingsForEachVehicleType(carArray,vanArray);
            outputFileChanged<< "Cars turned away are: " << carTurned << std::endl;
            outputFileChanged<< "Vans turned away are: " << vanTurned << std::endl;

            datesNumber.erase(datesNumber.begin() + 0);
            outputFileChanged.close();
            break;
            // Close the file after writing all vehicles for the date
        }
    }
}
void CarPark::startProgram(std::string FileName){
    populateArrays(FileName);
    createFiles();

}

 std::string CarPark::calculateTotalTakingsForDay(std::vector<Car> car, std::vector<Van> van){
    float result = 0;
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
    for(auto& car1 : car){
        carResult += car1.getPrice();
    }
    for(auto& van1 : van){
        vanResult += van1.getPrice();
    }
    return "Total takings for the Cars are " + std::to_string(carResult)
           + " and total takings for the Vans are " + std::to_string(vanResult)+ "\n";
}

 int CarPark::getCarSpacesTotal()  { return carSpacesTotal; }
 int CarPark::getVanSpacesTotal()  { return vanSpacesTotal; }
 int CarPark::getCarSpacesAvailable()  { return carSpacesAvailable; }
 int CarPark::getVanSpacesAvailable()  { return vanSpacesAvailable; }
 double CarPark::getCarPricePerHour()  { return carPricePerHour; }
 double CarPark::getVanPricePerHour()  { return vanPricePerHour; }
 std::string CarPark::getDate()   { return date; }

void CarPark::setDate(std::string value) { date = value;}
void CarPark::setCarSpacesTotal(int value) { carSpacesTotal = value; }
void CarPark::setVanSpacesTotal(int value) { vanSpacesTotal = value; }
void CarPark::setCarSpacesAvailable(int value) { carSpacesAvailable = value; }
void CarPark::setVanSpacesAvailable(int value) { vanSpacesAvailable = value; }
void CarPark::setCarPricePerHour(double value) { carPricePerHour = value; }
void CarPark::setVanPricePerHour(double value) { vanPricePerHour = value; }

