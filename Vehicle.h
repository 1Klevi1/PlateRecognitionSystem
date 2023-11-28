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
     * @brief Constructor for the Car class.
     * @param date Date of the vehicle action.
     * @param type Type of the vehicle (Car).
     * @param plateNumber License plate number of the car.
     * @param action Action performed by the car.
     * @param time Time of the car action.
     */
    Car(std::string date, std::string type, std::string plateNumber,
        std::string action, std::string time);
    /**
     * @brief Get the price specific to cars.
     * @return Price specific to cars.
     */
    float getPrice() ;
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
    * @brief Constructor for the Van class.
    * @param date Date of the vehicle action.
    * @param type Type of the vehicle (Van).
    * @param plateNumber License plate number of the van.
    * @param action Action performed by the van.
    * @param time Time of the van action.
    */
    Van(std::string date, std::string type, std::string plateNumber,
        std::string action, std::string time);
    /**
     * @brief Get the price specific to vans.
     * @return Price specific to vans.
     */
    float getPrice() ;
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
    * @brief Populate arrays with vehicle data from the given file.
    *
    * This function reads vehicle data from a file, creates Vehicle instances,
    * and populates arrays based on the date of the vehicles.
    *
    * @param filename The name of the input file containing vehicle data.
    * @return 0 on success, 1 if the input file cannot be opened.
    */
    int populateArrays(std::string fileName);

    /**
    * @brief Creates output files for each date and writes information about vehicles.
    *
    * This method processes grouped vehicle data by date and creates output files for each date.
    * It writes information about cars, vans, total takings, and turned away vehicles to the files.
    */
    void createFiles();

    /**
    * Calculates the total takings for the day based on the provided vectors of cars and vans.
    *
    * If both vectors are empty, the total takings are considered as 0.
    *
    * @param car A vector containing Car objects.
    * @param van A vector containing Van objects.
    * @return A string representing the total takings for the day.
    */
    std::string calculateTotalTakingsForDay(std::vector<Car> car, std::vector<Van> van);

    /**
    * @brief Calculates the total number of each vehicle type for the day.
    *
    * This method takes vectors of cars and vans and returns a formatted string
    * containing the total number of cars and vans for the day.
    *
    * @param car Vector of Car objects for the day.
    * @param van Vector of Van objects for the day.
    * @return A string with the total number of Cars and Vans for the day.
    */
    std::string getTotalNumberOfEachVehicleType(std::vector<Car> car, std::vector<Van> van);

    /**
    * Calculates the total takings for each vehicle type (Cars and Vans) for a given day.
    *
    * This function takes vectors of Car and Van objects and calculates the total takings
    * for each vehicle type separately. It sums up the prices of all the cars and vans
    * provided in the input vectors.
    *
    * @param car A vector containing Car objects for the day.
    * @param van A vector containing Van objects for the day.
    * @return A formatted string indicating the total takings for Cars and Vans.
    */
    std::string calculateTotalTakingsForEachVehicleType(std::vector<Car> car, std::vector<Van> van);

    /**
    * @brief Start the program by populating arrays from the specified file and creating files.
    *
    * This function initializes the CarPark by populating arrays with data from the specified file
    * and creating necessary files.
    *
    * @param FileName The name of the input file containing data for populating arrays.
    */
    void startProgram(std::string FileName);

    /**
    * @brief Set the date of the car park.
    * @param value The new date to set.
    */
    void setDate(std::string value);


    /**
    * @brief Get the vector containing pointers to all vehicles.
    * @return A reference to the vector of Vehicle pointers.
    */
    std::vector<Vehicle *> &getVehicleNumber();

    /**
    * @brief Get the vector containing grouped vehicles by date.
    * @return A reference to the vector of vectors of Vehicle pointers.
    */
    std::vector<std::vector<Vehicle *>> &getGroupedByDate();

    /**
    * @brief Populates an array with unique dates from grouped vehicle data.
    *
    * This function takes a vector of vectors of Vehicle pointers, where each
    * inner vector represents vehicles grouped by date. It extracts unique dates
    * and populates an array with them.
    *
    * @param groupedByDate A vector of vectors of Vehicle pointers.
    * @return A vector containing unique dates from the grouped vehicle data.
    */
    std::vector<std::string> populateDateArray(std::vector<std::vector<Vehicle*>> groupedByDate);

    /**
    * @brief Get the date of the car park.
    * @return The date of the car park.
    */
    std::string getDate();

    /**
    * @brief Groups vehicles by their date.
    *
    * This method takes a vector of Vehicle pointers and groups them based on their vehicle date.
    * It populates the 'groupedByDate' member variable with vectors of vehicles, each vector
    * representing a group of vehicles with the same date.
    *
    * @param vehicleNumber A vector of pointers to Vehicle objects.
    */
    void groupVehiclesByDate(std::vector<Vehicle*> vehicleNumber);

    /**
    * @brief Sets the vector of individual vehicles.
    */
    void setVehicleNumber(std::vector<Vehicle*> vehicleNumber);
    };
#endif //COURSEWORK_VEHICLE_H
