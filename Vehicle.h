//
// Created by Klevi on 21/11/2023.
//

#ifndef COURSEWORK_VEHICLE_H
#define COURSEWORK_VEHICLE_H
#include <string>
#include <vector>
#include <ostream>

class Vehicle {
private:
    std::string vehicleDate;
    std::string vehicleType;
    std::string plateNumber;
    std::string vehicleAction;
    std::string vehicleTime;
public:

    Vehicle(std::string date,std::string type, std::string plate,
            std::string action, std::string time);
    virtual ~Vehicle();

     std::string& getVehicleDate();
     std::string& getType();
     std::string& getPlateNumber();
     std::string& getTime();
     std::string& getAction();
    void setAction(std::string value);
    void setVehicleDate(std::string value);
    void setPlateNumber( std::string value);
    void setType( std::string value);
    void setTime( std::string value);

//    virtual void setPrice(float price);

//    virtual int getNumberOfEachVehicleTypeTurnedAway();
//    virtual std::string getDate();
//    virtual int readFileData(std::string filename);
//    virtual int checkOutputFileOpen(std::string filename);
};

class Car : public Vehicle {
private:
    float carPrice = 1;
public:
    Car(std::string date, std::string type, std::string plateNumber,
        std::string action, std::string time, float price);
    float getPrice();
};

class Van : public Vehicle {
private:
    float vanPrice = 1.50;
public:
    Van(std::string date, std::string type, std::string plateNumber,
    std::string action, std::string time, float vanPrice);
    float getPrice();

};

class CarPark {
private:
    std::vector<Car> carNumber; // 1000
    std::vector<Van> vanNumber; // 20
    std::vector<Vehicle> vehicleNumber; // TOTAL VEHECLES

    std::string date;
    int carSpacesTotal;
    int vanSpacesTotal;
    int carSpacesAvailable;
    int vanSpacesAvailable;
    double carPricePerHour;
    double vanPricePerHour;
    int carsTurnedAway; // if size full +1
    int vansTurnedAway; // if size full +1

public:
    int populateArrays(std::string fileName);
    int createFiles();
    std::string calculateTotalTakingsForDay(std::vector<Car> car, std::vector<Van> van);
    std::string getTotalNumberOfEachVehicleType(Vehicle temp);
    std::string calculateTotalTakingsForEachVehicleType();
    // Setters for setting values
    void setCarSpacesTotal(int value);
    void setVanSpacesTotal(int value);
    void setCarSpacesAvailable(int value);
    void setVanSpacesAvailable(int value);
    void setCarPricePerHour(double value);
    void setVanPricePerHour(double value);
    void setDate(std::string value);

    // Getters for accessing values
    int getCarArraySize();
    int getVanArraySize();
    std::vector<Car> getCarArray();
    std::vector<Van> getVanArray();
    std::string getCarArrayElements();
    std::string getVanArrayElements();
    std::string getDate();
    int getCarSpacesTotal();
    int getVanSpacesTotal();
    int getCarSpacesAvailable();
    int getVanSpacesAvailable();
    double getCarPricePerHour();
    double getVanPricePerHour();

};
#endif //COURSEWORK_VEHICLE_H
