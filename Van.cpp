#include "Vehicle.h"
/**
* @file Van.cpp
* @brief Van method implementation
*/
//
// Created by Klevi on 21/11/2023.
//
Van::Van(std::string vehicleDate, std::string vehicleType, std::string plateNumber,
         std::string vehicleAction, std::string vehicleTime, float price)
        : Vehicle(vehicleDate, vehicleType, plateNumber, vehicleAction, vehicleTime)
{
    this->vanPrice = price;
}

float Van::getPrice(){
    return vanPrice;
}

void Van::setPrice(float value) {
    vanPrice = value;
}