/**
* @file Van.cpp
* @brief Van method implementation
*/
//
// Created by Klevi on 21/11/2023.
//
#include "Vehicle.h"

 /**
 * @brief Constructor for the Van class.
 * @param vehicleDate The date of the vehicle.
 * @param vehicleType The type of the vehicle (e.g., "Van").
 * @param plateNumber The plate number of the vehicle.
 * @param vehicleAction The action performed by the vehicle (e.g., "Entry" or "Exit").
 * @param vehicleTime The time at which the vehicle performed the action.
 * @param price The price associated with the van.
 */
Van::Van(std::string vehicleDate, std::string vehicleType, std::string plateNumber,
         std::string vehicleAction, std::string vehicleTime, float price)
        : Vehicle(vehicleDate, vehicleType, plateNumber, vehicleAction, vehicleTime)
{
    this->vanPrice = price;
}

 /**
 * @brief Get the price associated with the van.
 * @return The price of the van.
 */
float Van::getPrice(){
    return vanPrice;
}

/**
 * @brief Set the price specific to vans.
 */
void Van::setPrice(float value) {
    vanPrice = value;
}