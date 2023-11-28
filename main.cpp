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
int main(){
    CarPark carPark;

    /**
    * @brief Start the CarPark program with the specified input file.
    *
    * This method reads data from the input file, processes it, and performs
    * other necessary operations.
    *
    * @param inputFileName The name of the input file.
    */
    carPark.startProgram("valid_input.txt");

    return 0;
}