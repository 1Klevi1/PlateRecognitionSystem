#include "Vehicle.h"
 /**
 * @file Car.cpp
 * @brief Car method implementation
 */

//
// Created by Klevi on 21/11/2023.
//

Car::Car(std::string vehicleDate, std::string vehicleType, std::string plateNumber,
         std::string vehicleAction, std::string vehicleTime, float price)
        : Vehicle(vehicleDate, vehicleType, plateNumber, vehicleAction, vehicleTime)
{
    this->carPrice = price;
}

float Car::getPrice() {
    return carPrice;
}

 void Car::setPrice(float value) {
     carPrice = value;
 }