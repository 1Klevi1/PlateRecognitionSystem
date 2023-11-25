 /**
 * @file Car.cpp
 * @brief Car method implementation
 */
//
// Created by Klevi on 21/11/2023.
//
#include "Vehicle.h"

 /**
 * @brief Constructor for the Car class.
 * @param vehicleDate The date of the vehicle entry.
 * @param vehicleType The type of the vehicle (e.g., car or van).
 * @param plateNumber The license plate number of the vehicle.
 * @param vehicleAction The action performed by the vehicle (e.g., entry or exit).
 * @param vehicleTime The time of the vehicle entry or exit.
 * @param price The price associated with the car.
 */
Car::Car(std::string vehicleDate, std::string vehicleType, std::string plateNumber,
         std::string vehicleAction, std::string vehicleTime, float price)
        : Vehicle(vehicleDate, vehicleType, plateNumber, vehicleAction, vehicleTime)
{
    this->carPrice = price;
}

 /**
 * @brief Get the price associated with the car.
 * @return The price of the car.
 */
float Car::getPrice() {
    return carPrice;
}

 /**
 * @brief Set the price specific to cars.
 */
 void Car::setPrice(float value) {
     carPrice = value;
 }