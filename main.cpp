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
    string dbldashes = std::string(NUMDBLDASH,'=');


    std::cout << "Testing display function on a graph object without any airports..." << std::endl;
    std::cout << dbldashes << std::endl;
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
    std::cout << dbldashes << std::endl;
    bool addedAirport = airportNetwork.addAirport(tempIDs[idCodeCount], &tempCodes[idCodeCount]);
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
    std::cout << dbldashes << std::endl;
    addedAirport = airportNetwork.addAirport(tempIDs[idCodeCount], &tempCodes[idCodeCount]);
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
    std::cout << dbldashes << std::endl;
    bool routeAdded = airportNetwork.addRoute(0, 1, 190);
    if (routeAdded) {
        std::cout << "Route added successfully..." << std::endl;
    }
    else {
        std::cout << "Route not added..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    //Note adding airports 3-5 can be done via a loop since we've proven proof of concept on AUS and DFW.
    std::cout << "\nFilling the remaining Airports based on the graph I created (n = 6)..." << std::endl;
    std::cout << dbldashes << std::endl;
    int arraySize = (sizeof(tempIDs)/sizeof(tempIDs[0]));
    for (int count = idCodeCount; count < arraySize; count++ ) {
        addedAirport = airportNetwork.addAirport(tempIDs[idCodeCount], &tempCodes[idCodeCount]);
        if (addedAirport) {
            std::cout << "Airport added successfully..." << std::endl;
            idCodeCount++;
        }
        else {
            std::cout << "Airport not added..." << std::endl;
        }
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nAttempting to add airports with invalid airportIDs..." << std::endl;
    std::cout << dbldashes << std::endl;
    string badCode = "BAD!";
    for (int count = -5; count < 0; count++ ) {
        addedAirport = airportNetwork.addAirport(count, &badCode);
        if (addedAirport) {
            std::cout << "Airport added successfully..." << std::endl;
        }
        else {
            std::cout << "Airport not added..." << std::endl;
        }
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting find airport function" << std::endl;
    std::cout << dbldashes << std::endl;
    string searchAirport = "";
    for (int count = 0; count < arraySize; count++){
        bool foundAirport = airportNetwork.findAirport(count, &searchAirport);
        if (foundAirport) {
            std::cout << "Airport found: " << searchAirport << std::endl;
        }
        else {
            std::cout << "Airport not found..." << std::endl;
        }
    }
    std::cout << "\nTesting find airport function with bad data..." << std::endl;
    std::cout << dbldashes << std::endl;
    for (int count = -3; count < 0; count++){
        bool foundAirport = airportNetwork.findAirport(count, &searchAirport);
        if (foundAirport) {
            std::cout << "Airport found: " << searchAirport << std::endl;
        }
        else {
            std::cout << "Airport not found..." << std::endl;
        }
    }
    for (int count = (arraySize+1); count < 10; count++){
        bool foundAirport = airportNetwork.findAirport(count, &searchAirport);
        if (foundAirport) {
            std::cout << "Airport found: " << searchAirport << std::endl;
        }
        else {
            std::cout << "Airport not found..." << std::endl;
        }
    }

    std::cout << "\nTesting  addition of a routes that are part of DFW..." << std::endl; //Route Length will be hard-coded or random @ first... but can do a lookup table for Node Pair lookup values.
    std::cout << dbldashes << std::endl;
    int dfwArrivals [] {2, 3, 4};
    int dfwWeights [] {1463, 1387, 1658};
    string dfwCodes [] {"SFO", "LGA", "SEA"};
    int dfwArraySize = (sizeof(dfwArrivals)/sizeof(dfwArrivals[0]));
    for (int dfwCount = 0; dfwCount < dfwArraySize; dfwCount++) {
        routeAdded = airportNetwork.addRoute(tempIDs[1], dfwArrivals[dfwCount], dfwWeights[dfwCount]);
        if (routeAdded) {
            std::cout << "Route added successfully..." << std::endl;
        }
        else {
            std::cout << "Route not added..." << std::endl;
        }
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting displayAirportInfo function on DFW..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.displayAirportInfo(1); // Can change to use random numbers later.
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting new anti-duplicate Airport ID protection..." << std::endl;
    std::cout << dbldashes << std::endl;
    for (int count = 0; count < 5; count++) {
        addedAirport = airportNetwork.addAirport(count, &badCode);
        if (addedAirport) {
            std::cout << "Airport added successfully..." << std::endl;
        }
        else {
            std::cout << "Airport not added..." << std::endl;
        }
    }
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;


    return 0;
};
