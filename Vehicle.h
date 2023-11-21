//
// Created by Klevi on 21/11/2023.
//

#ifndef COURSEWORK_VEHICLE_H
#define COURSEWORK_VEHICLE_H
#include <string>
#include <array>

class Vehicle {
private:
    std::string type;
    std::string plateNumber;
    float price;
    std::string time;
public:

    Vehicle(std::string type, std::string plateNumber, float price, std::string time);
    virtual ~Vehicle();
    std::string description();
    virtual void populateArrrays();
    virtual void setPrice(float price);
    virtual int calculateTotalTakingsForDay();
    virtual int getTotalNumberOfEachVehicleType();
    virtual int calculateTotalTakingsForEachVehicleType();
    virtual int getNumberOfEachVehicleTypeTurnedAway();
    virtual std::string getDate();
    virtual void readFileData();
};


class Car : public Vehicle {
private:
    std::array<std::string, 1000> carNumber;

public:
    Car(std::array<std::string, 1000> carNumber);
};


class Van : public Vehicle {
private:
    std::array<std::string, 20> vanNumber;
public:
    Van(std::array<std::string, 20> vanNumber);
};

#endif //COURSEWORK_VEHICLE_H
