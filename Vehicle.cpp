/**
* @file Vehicle.cpp
* @brief Vehicle method implementation
*/
//
// Created by Klevi on 21/11/2023.
//

#include "Vehicle.h"
#include <iostream>

 /**
 * @brief Constructor for the Vehicle class.
 * @param date The date of the vehicle.
 * @param type The type of the vehicle.
 * @param plate The plate number of the vehicle.
 * @param action The action performed by the vehicle.
 * @param time The time of the vehicle action.
 */
Vehicle::Vehicle(std::string date, std::string type, std::string plate,
                 std::string action, std::string time)
{
    this->vehicleDate = date;
    this->plateNumber = plate;
    this->vehicleType = type;
    this->vehicleAction = action;
    this->vehicleTime = time;
}

 /**
 * @brief Destructor for the Vehicle class.
 */
Vehicle::~Vehicle()
{
}

 /**
 * @brief Get the date of the vehicle.
 * @return A reference to the date of the vehicle.
 */
 std::string& Vehicle::getVehicleDate(){
    return vehicleDate;
}

 /**
 * @brief Get the type of the vehicle.
 * @return A reference to the type of the vehicle.
 */
 std::string& Vehicle::getType(){
    return vehicleType;
}

 /**
 * @brief Get the plate number of the vehicle.
 * @return A reference to the plate number of the vehicle.
 */
 std::string& Vehicle::getPlateNumber(){
    return plateNumber;
}

 /**
 * @brief Get the time of the vehicle action.
 * @return A reference to the time of the vehicle action.
 */
 std::string& Vehicle::getTime(){
    return vehicleTime;
}

 /**
 * @brief Get the action performed by the vehicle.
 * @return A reference to the action performed by the vehicle.
 */
 std::string& Vehicle::getAction(){
    return vehicleAction;
}

 /**
 * @brief Set the action performed by the vehicle.
 * @param value The new value for the action.
 */
void Vehicle::setAction(std::string value){
    vehicleAction = value;
}

 /**
 * @brief Set the date of the vehicle.
 * @param value The new value for the date.
 */
void Vehicle::setVehicleDate(std::string value){
    vehicleDate = value;
}

 /**
 * @brief Set the type of the vehicle.
 * @param value The new value for the type.
 */
void Vehicle::setType( std::string value){
    vehicleType = value;
}

 /**
 * @brief Set the plate number of the vehicle.
 * @param value The new value for the plate number.
 */
void Vehicle::setPlateNumber( std::string value){
    plateNumber = value;
}

 /**
 * @brief Set the time of the vehicle action.
 * @param value The new value for the time.
 */
void Vehicle::setTime( std::string value){
    vehicleTime = value;
}