//
// Created by Klevi on 21/11/2023.
//
#include "Vehicle.h"

Van::Van(std::string vehicleDate, std::string vehicleType, std::string plateNumber,
         std::string vehicleAction, std::string vehicleTime, float price)
        : Vehicle(vehicleDate, vehicleType, plateNumber, vehicleAction, vehicleTime)
{
    this->vanPrice = price;
}