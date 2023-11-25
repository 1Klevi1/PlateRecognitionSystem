/**
* @file Vehicle.h
* @brief Vehicle header file containing all the classes.
*/
//
// Created by Klevi on 21/11/2023.
//

#ifndef COURSEWORK_VEHICLE_H
#define COURSEWORK_VEHICLE_H
#include <string>
#include <vector>
#include <ostream>
/**
 * @class Vehicle
 * @brief Represents a vehicle with information about its date, type, plate number, action, and time.
 */
class Vehicle
{
private:
    std::string vehicleDate;    ///< Date of the vehicle.
    std::string vehicleType;    ///< Type of the vehicle.
    std::string plateNumber;    ///< Plate number of the vehicle.
    std::string vehicleAction;  ///< Action performed by the vehicle (e.g., entry or exit).
    std::string vehicleTime;    ///< Time at which the vehicle action occurred.
public:
    /**
     * @brief Constructor for the Vehicle class.
     * @param date The date of the vehicle.
     * @param type The type of the vehicle.
     * @param plate The plate number of the vehicle.
     * @param action The action performed by the vehicle.
     * @param time The time at which the vehicle action occurred.
     */
    Vehicle(std::string date,std::string type, std::string plate,
            std::string action, std::string time);

    /**
     * @brief Destructor for the Vehicle class.
     */
    virtual ~Vehicle();

    /**
     * @brief Getter for the vehicle date.
     * @return Reference to the vehicle date.
     */
     std::string& getVehicleDate();

    /**
    * @brief Getter for the vehicle type.
    * @return Reference to the vehicle type.
    */
     std::string& getType();

     /**
     * @brief Getter for the plate number.
     * @return Reference to the plate number.
     */
     std::string& getPlateNumber();

    /**
    * @brief Getter for the vehicle time.
    * @return Reference to the vehicle time.
    */
     std::string& getTime();

    /**
    * @brief Getter for the vehicle action.
    * @return Reference to the vehicle action.
    */
     std::string& getAction();

    /**
    * @brief Setter for the vehicle action.
    * @param value The new value for the vehicle action.
    */
    void setAction(std::string value);

    /**
     * @brief Setter for the vehicle date.
     * @param value The new value for the vehicle date.
     */
    void setVehicleDate(std::string value);

    /**
     * @brief Setter for the plate number.
     * @param value The new value for the plate number.
     */
    void setPlateNumber( std::string value);

    /**
     * @brief Setter for the vehicle type.
     * @param value The new value for the vehicle type.
     */
    void setType( std::string value);

    /**
     * @brief Setter for the vehicle time.
     * @param value The new value for the vehicle time.
     */
    void setTime( std::string value);
};

/**
 * @class Car
 * @brief Represents a car, inheriting from the Vehicle class.
 */
class Car : public Vehicle
{
private:
    float carPrice = 1;    ///< Price specific to cars.
public:
     /**
     * @brief Constructor for the Car class.
     * @param date Date of the vehicle action.
     * @param type Type of the vehicle (Car).
     * @param plateNumber License plate number of the car.
     * @param action Action performed by the car.
     * @param time Time of the car action.
     * @param price Price specific to cars.
     */
    Car(std::string date, std::string type, std::string plateNumber,
        std::string action, std::string time, float price);

    /**
     * @brief Get the price specific to cars.
     * @return Price specific to cars.
     */
    float getPrice() ;

    /**
     * @brief Set the price specific to cars.
     */
    void setPrice(float value) ;
};

/**
 * @class Van
 * @brief Represents a van, inheriting from the Vehicle class.
 */
class Van : public Vehicle
{
private:
    float vanPrice = 1.50;    ///< Price specific to vans.
public:
    /**
    * @brief Constructor for the Van class.
    * @param date Date of the vehicle action.
    * @param type Type of the vehicle (Van).
    * @param plateNumber License plate number of the van.
    * @param action Action performed by the van.
    * @param time Time of the van action.
    * @param price Price specific to vans.
    */
    Van(std::string date, std::string type, std::string plateNumber,
    std::string action, std::string time, float vanPrice);

    /**
     * @brief Get the price specific to vans.
     * @return Price specific to vans.
     */
    float getPrice() ;

    /**
     * @brief Set the price specific to vans.
     */
    void setPrice(float value) ;
};

/**
 * @brief The CarPark class represents a parking system.
 */
class CarPark
{
private:
    std::vector<Vehicle*> vehicleNumber;    ///<  Vector to store pointers to individual vehicles.
    std::vector<std::vector<Vehicle*>> groupedByDate;   ///<  Vector to store grouped vehicles based on date.
    std::string date;   ///<  Date associated with the vehicles in the car park.
public:
    /**
     * @brief Populates the arrays of vehicles based on the information provided in the input file.
     * @param fileName The name of the input file.
     * @return Returns 0 on success, 1 if unable to open the input file.
     */
    int populateArrays(std::string fileName);

    /**
     * @brief Creates files based on the populated arrays.
     */
    void createFiles();

    /**
     * @brief Calculates the total takings for a given day.
     * @param car Vector of Car objects for the day.
     * @param van Vector of Van objects for the day.
     * @return Returns a string containing the total takings for the day.
     */
    std::string calculateTotalTakingsForDay(std::vector<Car> car, std::vector<Van> van);

    /**
     * @brief Gets the total number of each vehicle type for the day.
     * @param car Vector of Car objects for the day.
     * @param van Vector of Van objects for the day.
     * @return Returns a string containing the total number of Cars and Vans for the day.
     */
    std::string getTotalNumberOfEachVehicleType(std::vector<Car> car, std::vector<Van> van);

    /**
     * @brief Calculates the total takings for each vehicle type for the day.
     * @param car Vector of Car objects for the day.
     * @param van Vector of Van objects for the day.
     * @return Returns a string containing the total takings for Cars and Vans separately.
     */
    std::string calculateTotalTakingsForEachVehicleType(std::vector<Car> car, std::vector<Van> van);

    /**
     * @brief Starts the car park program.
     * @param FileName The name of the input file.
     */
    void startProgram(std::string FileName);

    /**
     * @brief Sets the date for the vehicles in the car park.
     * @param value The date to be set.
     */
    void setDate(std::string value);


    /**
     * @brief Gets the vector of individual vehicles.
     * @return Reference to the vector of individual vehicles.
     */
    std::vector<Vehicle *> &getVehicleNumber();

    /**
     * @brief Gets the vector of grouped vehicles based on date.
     * @return Reference to the vector of grouped vehicles based on date.
     */
    std::vector<std::vector<Vehicle *>> &getGroupedByDate();

    /**
    * @brief Populates an array with unique dates based on grouped vehicles.
    * @param groupedByDate Vector of vectors containing grouped vehicles based on date.
    * @return Vector of unique dates.
    */
    std::vector<std::string> populateDateArray(std::vector<std::vector<Vehicle*>> groupedByDate);

    /**
     * @brief Gets the date associated with the vehicles in the car park.
     * @return The date associated with the vehicles.
     */
    std::string getDate();

     /**
     * @brief Groups vehicles by their date.
     *
     * This function takes a vector of Vehicle pointers and groups them based on their dates.
     * It creates a new vector for each unique date and organizes the vehicles accordingly.
     *
     * @param vehicleNumber The vector of Vehicle pointers to be grouped.
     */
    void groupVehiclesByDate(std::vector<Vehicle*> vehicleNumber);

    /**
      * @brief Sets the vector of individual vehicles.
      */
    void setVehicleNumber(std::vector<Vehicle*> vehicleNumber);
    };
#endif //COURSEWORK_VEHICLE_H
