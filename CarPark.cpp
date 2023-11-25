 /**
 * @file CarPark.cpp
 * @brief CarPark method implementation
 */
//
// Created by Klevi on 22/11/2023.
//
#include "Vehicle.h"
#include <fstream>
#include <sstream>
#include <iostream>
 /**
 * @brief Populate arrays with vehicle data from the given file.
 *
 * This function reads vehicle data from a file, creates Vehicle instances,
 * and populates arrays based on the date of the vehicles.
 *
 * @param filename The name of the input file containing vehicle data.
 * @return 0 on success, 1 if the input file cannot be opened.
 */
int CarPark::populateArrays(std::string filename) {
    // Open the input file
    std::ifstream inputFile(filename);
    std::string line;

    // Check if the file is open
    if (!inputFile.is_open()) {
        // Print an error message if the file cannot be opened
        std::cerr << "Unable to open the input file." << std::endl;
        return 1;
    }

    // Read each line from the file
    while (std::getline(inputFile, line)) {
        // Parse each line into vehicle information
        std::istringstream iss(line);
        Vehicle vehicle("", "", "","", "");
        std::string type, plate, action, time;

        // Check if the line contains a date or a vehicle entry
        if ((iss >> std::ws).peek() == '0' || std::isdigit(iss.peek())) {
            // Read the date if present
            iss >> date;
        }else{
            // Read vehicle details
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

        // Create a Vehicle instance
        Vehicle* vehicleInstance = new Vehicle(vehicle.getVehicleDate(), vehicle.getType(),
                                               vehicle.getPlateNumber(), vehicle.getAction(),
                                               vehicle.getTime());

        // Check if the date is not empty before adding to the array
        if (vehicleInstance->getVehicleDate() != "") {
            vehicleNumber.push_back(vehicleInstance);
        }

    }

    // Group vehicles by date
    groupVehiclesByDate(vehicleNumber);

    // Close the input file
    inputFile.close();

    // Return success
    return 0;
}

 /**
 * @brief Groups vehicles by their date.
 *
 * This method takes a vector of Vehicle pointers and groups them based on their vehicle date.
 * It populates the 'groupedByDate' member variable with vectors of vehicles, each vector
 * representing a group of vehicles with the same date.
 *
 * @param vehicleNumber A vector of pointers to Vehicle objects.
 */
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

 /**
 * @brief Populates an array with unique dates from grouped vehicle data.
 *
 * This function takes a vector of vectors of Vehicle pointers, where each
 * inner vector represents vehicles grouped by date. It extracts unique dates
 * and populates an array with them.
 *
 * @param groupedByDate A vector of vectors of Vehicle pointers.
 * @return A vector containing unique dates from the grouped vehicle data.
 */
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

 /**
 * @brief Creates output files for each date and writes information about vehicles.
 *
 * This method processes grouped vehicle data by date and creates output files for each date.
 * It writes information about cars, vans, total takings, and turned away vehicles to the files.
 */
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

 /**
 * @brief Start the program by populating arrays from the specified file and creating files.
 *
 * This function initializes the CarPark by populating arrays with data from the specified file
 * and creating necessary files.
 *
 * @param FileName The name of the input file containing data for populating arrays.
 */
void CarPark::startProgram(std::string FileName){
    populateArrays(FileName);
    createFiles();
}

 /**
 * Calculates the total takings for the day based on the provided vectors of cars and vans.
 *
 * If both vectors are empty, the total takings are considered as 0.
 *
 * @param car A vector containing Car objects.
 * @param van A vector containing Van objects.
 * @return A string representing the total takings for the day.
 */
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

 /**
 * @brief Calculates the total number of each vehicle type for the day.
 *
 * This method takes vectors of cars and vans and returns a formatted string
 * containing the total number of cars and vans for the day.
 *
 * @param car Vector of Car objects for the day.
 * @param van Vector of Van objects for the day.
 * @return A string with the total number of Cars and Vans for the day.
 */
std::string CarPark::getTotalNumberOfEachVehicleType(std::vector<Car> car, std::vector<Van> van){

    return "Total number of Cars for the day are " + std::to_string(car.size())
    + " and total of Vans for the day are " + std::to_string(van.size())+ "\n";
}

 /**
 * Calculates the total takings for each vehicle type (Cars and Vans) for a given day.
 *
 * This function takes vectors of Car and Van objects and calculates the total takings
 * for each vehicle type separately. It sums up the prices of all the cars and vans
 * provided in the input vectors.
 *
 * @param car A vector containing Car objects for the day.
 * @param van A vector containing Van objects for the day.
 * @return A formatted string indicating the total takings for Cars and Vans.
 */
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

 /**
 * @brief Get the date of the car park.
 * @return The date of the car park.
 */
std::string CarPark::getDate(){ return date; }

 /**
 * @brief Set the date of the car park.
 * @param value The new date to set.
 */
void CarPark::setDate(std::string value){ date = value; }

 /**
 * @brief Sets the vector of individual vehicles.
 */
void CarPark::setVehicleNumber(std::vector<Vehicle*> vehicles ){ vehicleNumber = vehicles; }

 /**
 * @brief Get the vector containing pointers to all vehicles.
 * @return A reference to the vector of Vehicle pointers.
 */
std::vector<Vehicle *> &CarPark::getVehicleNumber(){ return vehicleNumber; }

 /**
 * @brief Get the vector containing grouped vehicles by date.
 * @return A reference to the vector of vectors of Vehicle pointers.
 */
std::vector<std::vector<Vehicle *>> &CarPark::getGroupedByDate(){ return groupedByDate; }
