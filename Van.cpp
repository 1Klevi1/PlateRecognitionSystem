//
// Created by Klevi on 21/11/2023.
//
#include "Vehicle.h"

Van::Van(std::string type, std::string plateNumber, std::string time, std::array<std::string, 20> vanNumber)
        : Vehicle(type, plateNumber, time), vanNumber(vanNumber) {
}