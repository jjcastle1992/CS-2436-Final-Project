/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Implementation for my driver file that will be testing my airport/route graph object.
**********************/

#include "main.h"

int main () {

    Graph airportNetwork;
    int tempIDs [] = {0, 1, 2, 3, 4, 5};
    string tempCodes [] = {"AUS","DFW", "SFO", "LGA", "SEA", "LAX"};
    int idCodeCount = 0;

    std::cout << "Testing display function on a graph object without any airports..." << std::endl;
    std::cout << "--------------------------" <<std::endl;
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;
    bool isEmpty = airportNetwork.graphEmpty();
    if (isEmpty) {
        std::cout << "The graph is empty..." << std::endl;
    }
    else {
        std::cout << "The graph is not empty..." << std::endl;
    }

    std::cout << "\nTesting simple addition of a single airport to our vector..." << std::endl;
    std::cout << "--------------------------" <<std::endl;
    bool addedAirport = airportNetwork.addAirport(tempIDs[idCodeCount], tempCodes[idCodeCount]);
    if (addedAirport) {
        std::cout << "Airport added successfully..." << std::endl;
        idCodeCount++;
    }
    else {
        std::cout << "Airport not added..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;
    isEmpty = airportNetwork.graphEmpty();
    if (isEmpty) {
        std::cout << "The graph is empty..." << std::endl;
    }
    else {
        std::cout << "The graph is not empty..." << std::endl;
    }

    std::cout << "\nTesting  addition of a second airport (precursor to adding first route)..." << std::endl;
    std::cout << "--------------------------" <<std::endl;
    addedAirport = airportNetwork.addAirport(tempIDs[idCodeCount], tempCodes[idCodeCount]);
    if (addedAirport) {
        std::cout << "Airport added successfully..." << std::endl;
        idCodeCount++;
    }
    else {
        std::cout << "Airport not added..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting  addition of a first route..." << std::endl; //Route Length will be hard-coded or random @ first... but can do a lookup table for Node Pair lookup values.
    std::cout << "--------------------------" <<std::endl;
    bool routeAdded = airportNetwork.addRoute(0, 1, 190);
    if (routeAdded) {
        std::cout << "Route added successfully..." << std::endl;
    }
    else {
        std::cout << "Route not added..." << std::endl;
    }
    airportNetwork.displayGraph();

    //Note adding airports 3-5 can be done via a loop since we've proven proof of concept on AUS and DFW.

    return 0;
};
