//
// Created by Klevi on 21/11/2023.
//
#include "Vehicle.h"

Car::Car(std::string type, std::string plateNumber, std::string time, std::array<std::string, 1000> carNumbers)
        : Vehicle(type, plateNumber, time), carNumber(carNumbers) {
}