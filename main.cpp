#include <iostream>
#include <fstream>
#include <sstream>
#include "Vehicle.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];

    CarPark a;
    a.startProgram(inputFileName);

    return 0;
}