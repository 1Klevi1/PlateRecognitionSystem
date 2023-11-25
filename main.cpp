/**
* @file Main.cpp
* @brief The main function of the program.
*/
#include <iostream>
#include "Vehicle.h"
/**
 * @brief The main function of the program.
 *
 * This function is the entry point of the program and is responsible for
 * handling command-line arguments and starting the CarPark program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 *
 * @return 0 on successful execution, non-zero on error.
 */
int main(int argc, char *argv[]) {

    /**
     * @brief Check the number of command-line arguments.
     *
     * If the number of command-line arguments is not equal to 2, print a
     * usage message and exit the program with an error code.
     */
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    /**
     * @brief Get the input file name from command-line arguments.
     *
     * The input file name is the second command-line argument (argv[1]).
     */
    std::string inputFileName = argv[1];
    CarPark a;

    /**
    * @brief Start the CarPark program with the specified input file.
    *
    * This method reads data from the input file, processes it, and performs
    * other necessary operations.
    *
    * @param inputFileName The name of the input file.
    */
    a.startProgram(inputFileName);

    return 0;
}