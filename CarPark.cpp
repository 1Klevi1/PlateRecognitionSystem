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
        if((iss >> std::ws).peek() == '0'){
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

//        std::cout<<vehicle.getVehicleDate()<<" "<<vehicle.getType()<<" "<<
//                 vehicle.getPlateNumber()<<" "<< vehicle.getAction()<<" "<<
//                 vehicle.getTime() << std::endl;
        // Create a new Vehicle object based on the type

        Vehicle vehicleInstance(vehicle.getVehicleDate(), vehicle.getType(),
                        vehicle.getPlateNumber(), vehicle.getAction(),
                        vehicle.getTime());
        vehicleNumber.push_back(vehicleInstance);

        if (vehicle.getType() == "car") {
            Car carInstance(vehicle.getVehicleDate(), vehicle.getType(),
                            vehicle.getPlateNumber(), vehicle.getAction(),
                            vehicle.getTime(), 1.0);
            carNumber.push_back(carInstance);

        } else if (vehicle.getType() == "van") {
            // Your van-specific code here
            Van vanInstance(vehicle.getVehicleDate(), vehicle.getType(),
                            vehicle.getPlateNumber(), vehicle.getAction(),
                            vehicle.getTime(), 1.50);
            vanNumber.push_back(vanInstance);
        }
    }
    inputFile.close();
    return 0;
}
int CarPark::createFiles() {
    std::string prevDate;
    std::ofstream outputFileChanged;
    std::vector<Car> cars;
    std::vector<Van> vans;

    for (auto &vehicle : vehicleNumber) {
        if (vehicle.getVehicleDate() != prevDate) {
            prevDate = vehicle.getVehicleDate();
            if (!vehicle.getVehicleDate().empty()) {
                std::string outputFileFormat = vehicle.getVehicleDate().substr(0, 2) +
                                               vehicle.getVehicleDate().substr(3, 2) +
                                               vehicle.getVehicleDate().substr(6, 4);
                // Close the previous file before opening a new one
                if (outputFileChanged.is_open()) {
                    outputFileChanged.close();
                }
                outputFileChanged.open(outputFileFormat + ".dat");
            }
        }

        if (outputFileChanged.is_open() && !vehicle.getVehicleDate().empty()) {

            outputFileChanged << vehicle.getVehicleDate() << " " << vehicle.getType() << " " <<
                              vehicle.getPlateNumber() << " " << vehicle.getAction() << " " <<
                              vehicle.getTime() << std::endl;
//            if(vehicle.getType() == "car"){
//                Car carInstance(vehicle.getVehicleDate(),vehicle.getType(),
//                             vehicle.getPlateNumber() , vehicle.getAction() ,
//                                                         vehicle.getTime(), 1.0);
//                cars.push_back(carInstance);
//            }
//            if(vehicle.getType() == "van"){
//                Van vanInstance(vehicle.getVehicleDate(),vehicle.getType(),
//                                vehicle.getPlateNumber() , vehicle.getAction() ,
//                                vehicle.getTime(), 1.0);
//                vans.push_back(vanInstance);
//            }
//            outputFileChanged << calculateTotalTakingsForDay(cars,vans) << std::endl;

//            outputFileChanged << "Date: " << vehicle.getVehicleDate() << std::endl;
//            outputFileChanged << calculateTotalTakingsForDay(cars,vans) << std::endl;
//            outputFileChanged << getTotalNumberOfEachVehicleType(vehicle) << std::endl;
//            outputFileChanged << calculateTotalTakingsForEachVehicleType() << std::endl;
//            outputFileChanged << "Cars turned away: " << carsTurnedAway
//            <<"- Vans turned away: " << vansTurnedAway<< std::endl;
        }
    }

    // Close the last file after the loop
    if (outputFileChanged.is_open()) {
        outputFileChanged.close();
    }

    return 0;
}

int CarPark::getCarArraySize(){
    return getCarArray().size();
}
int CarPark::getVanArraySize(){
    return getVanArray().size();
}

std::vector<Car> CarPark::getCarArray(){
    return carNumber;
}
std::vector<Van> CarPark::getVanArray(){
    return vanNumber;
}
  std::string CarPark::getCarArrayElements()  {
    std::string s="";
    for ( auto& car : carNumber) {
        // Print information about each Car
        s+= "Date: " + car.getVehicleDate()+" type: "
                + car.getType()+ " plate: " + car.getPlateNumber() +" action: "
                + car.getAction()+" time: " + car.getTime() + "\n";
    }
    return s;
}
  std::string CarPark::getVanArrayElements()  {
    std::string s = "";
    for ( auto& van : vanNumber) {
        // Print information about each Car
        s+= "Date: " + van.getVehicleDate() +" type: " + van.getType()+" plate: "
                + van.getPlateNumber()+ " action: " + van.getAction()+" time: "
                + van.getTime() +"\n";
    }
    return s;
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
std::string CarPark::getTotalNumberOfEachVehicleType(Vehicle temp){
    int carTotal = 0;
    int vanTotal = 0;
    for(auto& car : carNumber){
        if(car.getPlateNumber() == temp.getPlateNumber()){
            carTotal += 1;
        }
    }
    for(auto& van : vanNumber){
        if(van.getPlateNumber() == temp.getPlateNumber()){
            vanTotal += 1;
        }
    }

    return "Total number of Cars for the day are " + std::to_string(carTotal)
    + " and total of Vans for the day are " + std::to_string(vanTotal)+ "\n";
}
std::string CarPark::calculateTotalTakingsForEachVehicleType(){
    float carResult = 0;
    float vanResult = 0;
    for(auto& car : carNumber){
        carResult += car.getPrice();
    }
    for(auto& van : vanNumber){
        vanResult += van.getPrice();
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

