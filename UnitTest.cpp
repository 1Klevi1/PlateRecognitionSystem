//
// Created by Klevi on 24/11/2023.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Vehicle.h"

TEST_CASE("calculateTotalTakingsForDay", "[calculateTotalTakingsForDay]")
{
    // Create a CarPark object
    CarPark carPark;

    // Create some test data (cars and vans) for the day
     std::vector<Car> cars = {
            Car("11/10/2023", "Car", "ABC123", "Entry", "08:00", 1.0),
            Car("11/10/2023", "Car", "DEF456", "Entry", "10:15", 1.0),
            Car("11/10/2023", "Car", "GHI789", "Entry", "12:30", 1.0),
            // Add more Car instances as needed
    };

    std::vector<Van> vans = {
            Van("11/10/2023", "Van", "XYZ789", "Entry", "09:30", 1.50),
            Van("11/10/2023", "Van", "LMN101", "Entry", "11:45", 1.50),
            Van("11/10/2023", "Van", "OPQ202", "Entry", "14:00", 1.50),
            // Add more Van instances as needed
    };

    SECTION("Empty day") {
        // Test when there are no cars or vans
        std::string result = carPark.calculateTotalTakingsForDay({}, {});
        REQUIRE(result == "Total takings for the day are 0\n");
    }

    SECTION("Cars only") {
        // Test when there are only cars
        // Populate cars vector with some Car objects
        std::string result = carPark.calculateTotalTakingsForDay(cars, {});
        // Calculate expected result based on the prices of Car objects
        float expected = 0;
        for ( auto& car : cars) {
            expected += car.getPrice();
        }
        REQUIRE(result == "Total takings for the day are " + std::to_string(expected) + "\n");
    }

    SECTION("Vans only") {
        // Test when there are only vans
        // Populate vans vector with some Van objects
        std::string result = carPark.calculateTotalTakingsForDay({}, vans);
        // Calculate expected result based on the prices of Van objects
        float expected = 0;
        for ( auto& van : vans) {
            expected += van.getPrice();
        }
        REQUIRE(result == "Total takings for the day are " + std::to_string(expected) + "\n");
    }

    SECTION("Mixed Cars and Vans") {
        // Test when there are both cars and vans
        // Populate cars and vans vectors with some objects
        std::string result = carPark.calculateTotalTakingsForDay(cars, vans);
        // Calculate expected result based on the prices of both Car and Van objects
        float expected = 0;
        for ( auto& car : cars) {
            expected += car.getPrice();
        }
        for ( auto& van : vans) {
            expected += van.getPrice();
        }
        REQUIRE(result == "Total takings for the day are " + std::to_string(expected) + "\n");
    }
}

TEST_CASE("Test getTotalNumberOfEachVehicleType", "[getTotalNumberOfEachVehicleType]") {
    // Create some test data (cars and vans) for the day
    std::vector<Car> cars = {
            Car("11/10/2023", "Car", "ABC123", "Entry", "08:00", 1.0),
            Car("11/10/2023", "Car", "DEF456", "Entry", "10:15", 1.0),
            Car("11/10/2023", "Car", "GHI789", "Entry", "12:30", 1.0),
            // Add more Car instances as needed
    };

    std::vector<Van> vans = {
            Van("11/10/2023", "Van", "XYZ789", "Entry", "09:30", 1.50),
            Van("11/10/2023", "Van", "LMN101", "Entry", "11:45", 1.50),
            Van("11/10/2023", "Van", "OPQ202", "Entry", "14:00", 1.50),
            // Add more Van instances as needed
    };

    // Create a CarPark instance
    CarPark carPark;

    SECTION("Test with non-empty data") {
        // Call the function with the test data
        std::string result = carPark.getTotalNumberOfEachVehicleType(cars, vans);

        // Write assertions to check the result
        REQUIRE(result == "Total number of Cars for the day are " + std::to_string(cars.size()) +
                          " and total of Vans for the day are " + std::to_string(vans.size()) + "\n");
    }
    SECTION("Test vans") {
        // Call the function with the test data
        std::string result = carPark.getTotalNumberOfEachVehicleType({}, vans);

        // Write assertions to check the result
        REQUIRE(result == "Total number of Cars for the day are 0 "
                          "and total of Vans for the day are " + std::to_string(vans.size()) + "\n");
    }
    SECTION("Test cars") {
        // Call the function with the test data
        std::string result = carPark.getTotalNumberOfEachVehicleType(cars, {});

        // Write assertions to check the result
        REQUIRE(result == "Total number of Cars for the day are "+std::to_string(cars.size())+
                          " and total of Vans for the day are 0\n");
    }
    SECTION("Test with empty data") {
        // Call the function with empty vectors
        std::string result = carPark.getTotalNumberOfEachVehicleType({}, {});

        // Write assertions to check the result
        REQUIRE(result == "Total number of Cars for the day are 0 and total of Vans for the day are 0\n");
    }

}
TEST_CASE("calculateTotalTakingsForEachVehicleType", "[calculateTotalTakingsForEachVehicleType]") {
    // Create some test data (cars and vans) for the day
    std::vector<Car> cars = {
            Car("11/10/2023", "Car", "ABC123", "Entry", "08:00", 1.0),
            Car("11/10/2023", "Car", "DEF456", "Entry", "10:15", 1.0),
            Car("11/10/2023", "Car", "GHI789", "Entry", "12:30", 1.0)
            // Add more Car instances as needed
    };

    std::vector<Van> vans = {
            Van("11/10/2023", "Van", "XYZ789", "Entry", "09:30", 1.50),
            Van("11/10/2023", "Van", "LMN101", "Entry", "11:45", 1.50),
            Van("11/10/2023", "Van", "OPQ202", "Entry", "14:00", 1.50)
            // Add more Van instances as needed
    };

    // Create a CarPark instance
    CarPark carPark;

    SECTION("Test with non-empty data") {

        std::string result = carPark.calculateTotalTakingsForEachVehicleType(cars, vans);
        float carExpected = 0;
        float vanExpected = 0;

        for (auto &car: cars) {
            carExpected += car.getPrice();
        }
        for (auto &van: vans) {
            vanExpected += van.getPrice();
        }
        // Assert the expected result
        REQUIRE(result == "Total takings for the Cars are " + std::to_string(carExpected) +
                          " and total takings for the Vans are " + std::to_string(vanExpected) + "\n");
    }
    SECTION("Test with empty data") {
        std::string result = carPark.calculateTotalTakingsForEachVehicleType({}, {});

        REQUIRE(result == "Total takings for the Cars are 0 and total takings for the Vans are 0\n");

    }
    SECTION("Test only cars") {
        std::vector<Van> emptyVans = {};
        std::string result = carPark.calculateTotalTakingsForEachVehicleType(cars, emptyVans);

        float carExpected = 0;
        for (auto &car: cars) {
            carExpected += car.getPrice();
        }
        float vanExpected = 0;
        for (auto &van: emptyVans) {
            vanExpected += van.getPrice();
        }

        REQUIRE(result == "Total takings for the Cars are " + std::to_string(carExpected) +
                          " and total takings for the Vans are "+ std::to_string(vanExpected) +"\n");
    }
    SECTION("Test only vans") {
        std::vector<Car> emptyCars = {};

        std::string result = carPark.calculateTotalTakingsForEachVehicleType(emptyCars, vans);
        float carExpected = 0;
        for (auto &car: emptyCars) {
            carExpected += car.getPrice();
        }
        float vanExpected = 0;
        for (auto &van: vans) {
            vanExpected += van.getPrice();
        }

        REQUIRE(result ==
                "Total takings for the Cars are "+ std::to_string(carExpected)+" and total takings for the Vans are " + std::to_string(vanExpected) +
                "\n");
    }
}
TEST_CASE("Testing all the setters", "[setDate]") {

// Create a CarPark instance with some initial values
    CarPark carPark;
    carPark.setDate("11/10/2023");
    SECTION("getDate") {
        REQUIRE(carPark.getDate() == "11/10/2023");
    }
}
TEST_CASE("CarPark populateArrays", "[CarPark]") {
    // Create a CarPark instance
    CarPark carPark;

    SECTION("Valid Input File") {
        // Provide a valid input file with test data
        std::string validFileName = "valid_input.txt";

        // Create the valid input file with test data
        std::ofstream validInputFile(validFileName);
        validInputFile << "11/10/2023\n";
        validInputFile << "Car ABC123 IN 08:00\n";
        validInputFile << "car DEF456 OUT 10:15\n";
        validInputFile << "van XYZ789 IN 09:30\n";
        validInputFile << "van LMN101 OUT 11:45\n";
        validInputFile << "22/10/2023\n";
        validInputFile << "car ABC123 IN 08:00\n";
        validInputFile << "car DEF456 OUT 10:15\n";
        validInputFile << "van XYZ789 IN 09:30\n";
        validInputFile << "van LMN101 OUT 11:45\n";
        validInputFile.close();

        // Call the populateArrays method
        int result = carPark.populateArrays(validFileName);

        // Assert the result
        REQUIRE(result == 0);

        // Assert that the arrays are populated correctly
        REQUIRE(carPark.getVehicleNumber().size() == 8);
        REQUIRE(carPark.getGroupedByDate().size() == 2);
    }

    SECTION("Invalid Input File") {
        // Provide an invalid input file (non-existent file)
        std::string invalidFileName = "nonexistent_file.txt";

        // Call the populateArrays method with an invalid file
        int result = carPark.populateArrays(invalidFileName);

        // Assert the result
        REQUIRE(result == 1);
    }
}
TEST_CASE("populateDateArray", "[populateDateArray]") {
    SECTION("Test with no vehicles (empty data)") {
        std::vector<std::vector<Vehicle*>> emptyData;
        CarPark carParkEmpty;
        std::vector<std::string> resultEmpty = carParkEmpty.populateDateArray(emptyData);
        REQUIRE(resultEmpty.empty());
    }
    SECTION("Test with a single date and multiple vehicles on that date") {
        std::vector<std::vector<Vehicle*>> singleDateData = {
                {new Vehicle("11/10/2023", "car", "ABC123", "IN", "08:00")},
                {new Vehicle("11/10/2023", "van", "XYZ789", "IN", "09:30")},
                {new Vehicle("11/10/2023", "car", "DEF456", "IN", "10:15")},
        };
        CarPark carParkSingleDate;
        std::vector<std::string> resultSingleDate = carParkSingleDate.populateDateArray(singleDateData);
        REQUIRE(resultSingleDate.size() == 1);  // One unique date in the test data
        REQUIRE(resultSingleDate[0] == "11/10/2023");

        // Clean up - Delete the dynamically allocated Vehicle instances
        for (auto& group : singleDateData) {
            for (auto& vehicle : group) {
                delete vehicle;
            }
        }
    }
    SECTION("Test with multiple dates") {

        std::vector<std::vector<Vehicle*>> multipleDatesData = {
                {new Vehicle("11/10/2023", "car", "ABC123", "IN", "08:00")},
                {new Vehicle("12/10/2023", "van", "XYZ789", "IN", "09:30")},
                {new Vehicle("13/10/2023", "car", "DEF456", "IN", "10:15")},
        };
        CarPark carParkMultipleDates;
        std::vector<std::string> resultMultipleDates = carParkMultipleDates.populateDateArray(multipleDatesData);
        REQUIRE(resultMultipleDates.size() == 3);
        REQUIRE(resultMultipleDates[0] == "11/10/2023");
        REQUIRE(resultMultipleDates[1] == "12/10/2023");
        REQUIRE(resultMultipleDates[2] == "13/10/2023");

        for (auto& group : multipleDatesData) {
            for (auto& vehicle : group) {
                delete vehicle;
            }
        }
    }
}