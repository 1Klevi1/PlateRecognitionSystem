//
// Created by Klevi on 22/11/2023.
//
#include "Vehicle.h"
#include <fstream>
#include <sstream>
#include <iostream>
int CarPark::populateArrays(std::string filename){
    std::ifstream inputFile(filename);
    std::cout << "running the code  1" << std::endl;

    if (!inputFile.is_open()) {
         std::cerr << "Unable to open the input file." << std::endl;
         return 1;
    }
    std::cout << "running the code  2" << std::endl;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Vehicle vehicle("", "", "","", ""); // Provide default values or modify the constructor as needed
        std::string dateNumber, type, plate, action, time;
        // Read the date and type
        if((iss >> std::ws).peek() == '0'){
            iss >> date;
            dateNumber = date;
            vehicle.setVehicleDate(date);
        }else{
            iss >> type;
            vehicle.setType(type);
            vehicle.setVehicleDate(dateNumber);
            iss >> plate;
            vehicle.setPlateNumber(plate);
            iss >> action;
            vehicle.setAction(action);
            iss >> time;
            vehicle.setTime(time);
        }
        std::cout << "carNumber size " <<carNumber.size()<< std::endl;
        std::cout << "vanNumber size " <<vanNumber.size()<< std::endl;
        std::cout << "vehcle date: " << vehicle.getVehicleDate()<< std::endl;
        std::cout << "date general: " <<date << " "<< dateNumber<< std::endl;

        // Create a new Vehicle object based on the type
        if (vehicle.getType() == "car" && carNumber.size()<1000) {
            // Your car-specific code here
            Car carInstance(date, vehicle.getType(),
                            vehicle.getPlateNumber(), vehicle.getAction(),
                            vehicle.getTime(), 1.0);

            carNumber.push_back(carInstance);
            std::cout << "This is a car." << std::endl;

        } else if (vehicle.getType() == "van" && vanNumber.size()<20) {
            // Your van-specific code here
            Van vanInstance(date, vehicle.getType(),
                            vehicle.getPlateNumber(), vehicle.getAction(),
                            vehicle.getTime(), 1.50);
            vanNumber.push_back(vanInstance);
            std::cout << "This is a van." << std::endl;
        }

////         Print for debugging
//        std::cout << "vehicle: " << vehicle.getVehicleDate() << " " << vehicle.getType()
//                  << " " << vehicle.getPlateNumber() << " " << vehicle.getAction()
//                  << " "<< vehicle.getTime() << std::endl;
    }
    inputFile.close();

    return 0;
}

  std::string CarPark::getCarArray()  {
    std::string s;
    for ( auto& car : carNumber) {
        // Print information about each Car
        s+= "Date: " + car.getVehicleDate()+" type: "
                + car.getType()+ " plate: " + car.getPlateNumber() +" action: "
                + car.getAction()+" time: " + car.getTime() + "\n";
    }
    return s;
}
  std::string CarPark::getVanArray()  {
    std::string s = "";
    for ( auto& van : vanNumber) {
        // Print information about each Car
        s+= "Date: " + van.getVehicleDate() +" type: " + van.getType()+" plate: "
                + van.getPlateNumber()+ " action: " + van.getAction()+" time: "
                + van.getTime() +"\n";
    }
    return s;
}
const int& CarPark::getCarSpacesTotal()  { return carSpacesTotal; }
const int& CarPark::getVanSpacesTotal()  { return vanSpacesTotal; }
const int& CarPark::getCarSpacesAvailable()  { return carSpacesAvailable; }
const int& CarPark::getVanSpacesAvailable()  { return vanSpacesAvailable; }
const double& CarPark::getCarPricePerHour()  { return carPricePerHour; }
const double& CarPark::getVanPricePerHour()  { return vanPricePerHour; }
const std::string& CarPark::getDate()   { return date; }

void CarPark::setDate(std::string value) { date = value;}
void CarPark::setCarSpacesTotal(int value) { carSpacesTotal = value; }
void CarPark::setVanSpacesTotal(int value) { vanSpacesTotal = value; }
void CarPark::setCarSpacesAvailable(int value) { carSpacesAvailable = value; }
void CarPark::setVanSpacesAvailable(int value) { vanSpacesAvailable = value; }
void CarPark::setCarPricePerHour(double value) { carPricePerHour = value; }
void CarPark::setVanPricePerHour(double value) { vanPricePerHour = value; }

