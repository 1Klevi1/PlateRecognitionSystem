//
// Created by Klevi on 21/11/2023.
//

#include "Vehicle.h"
#include <fstream>
#include <sstream>
#include <iostream>
Vehicle::Vehicle(std::string date, std::string type, std::string plate,
                 std::string action, std::string time)
{
    this->vehicleDate = date;
    this->plateNumber = plate;
    this->vehicleType = type;
    this->vehicleAction = action;
    this->vehicleTime = time;
}
Vehicle::~Vehicle()
{
}
 std::string& Vehicle::getVehicleDate(){
    return vehicleDate;
}

 std::string& Vehicle::getType(){
    return vehicleType;
}
 std::string& Vehicle::getPlateNumber(){
    return plateNumber;
}
 std::string& Vehicle::getTime(){
    return vehicleTime;
}
 std::string& Vehicle::getAction(){
    return vehicleAction;
}

void Vehicle::setAction(std::string value){
    vehicleAction = value;
}
void Vehicle::setVehicleDate(std::string value){
    vehicleDate = value;
}
void Vehicle::setType( std::string value){
    vehicleType = value;
}

void Vehicle::setPlateNumber( std::string value){
    plateNumber = value;
}

void Vehicle::setTime( std::string value){
    vehicleTime = value;
}