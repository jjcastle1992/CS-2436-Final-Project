/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Implementation for my driver file that will be testing my airport/route graph object.
**********************/

#include "main.h"

int main () {

    Graph airportNetwork;

    std::cout << "Testing display function on a graph object without any airports..." << std::endl;
    std::cout << "--------------------------" <<std::endl;
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting simple addition of a single airport to our vector..." << std::endl;
    std::cout << "--------------------------" <<std::endl;
    airportNetwork.addAirport(1, "DFW");
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;




    return 0;
};
