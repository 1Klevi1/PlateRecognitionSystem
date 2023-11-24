//
// Created by Klevi on 24/11/2023.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp" // Make sure to include the Catch2 header
#include "Vehicle.h" // Adjust the header file name based on your implementation

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