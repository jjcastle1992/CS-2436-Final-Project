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

    std::cout << "\nTesting addition of routes that are part of DFW..." << std::endl; //Route Length will be hard-coded or random @ first... but can do a lookup table for Node Pair lookup values.
    std::cout << dbldashes << std::endl;
    int dfwArrivals [] {0, 2, 3, 4};
    int dfwWeights [] {190, 1463, 1387, 1658};
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

    std::cout << "\nTesting removeRoute by removing the DFW-LGA route (mid-case)..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.displayAirportInfo(1);
    bool routeRemoved = airportNetwork.removeRoute(1, 3);
    if (routeRemoved) {
        std::cout << "\nRoute removed successfully...\n" << std::endl;
    }
    else {
        std::cout << "\nRoute not removed...\n" << std::endl;
    }
    airportNetwork.displayAirportInfo(1);
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting removeRoute by removing the DFW-SEA route (tail-case)..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.displayAirportInfo(1);
    routeRemoved = airportNetwork.removeRoute(1, 4);
    if (routeRemoved) {
        std::cout << "\nRoute removed successfully...\n" << std::endl;
    }
    else {
        std::cout << "\nRoute not removed...\n" << std::endl;
    }
    airportNetwork.displayAirportInfo(1);
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting removeRoute data validation by attempting to remove an invalid destination from the DFW airport route list..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.displayAirportInfo(1);
    routeRemoved = airportNetwork.removeRoute(1, 1400);
    if (routeRemoved) {
        std::cout << "\nRoute removed successfully...\n" << std::endl;
    }
    else {
        std::cout << "\nRoute not removed...\n" << std::endl;
    }
    airportNetwork.displayAirportInfo(1);
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting removeAirport method by removing LAX (terminal index) ..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.displayAirportInfo(5);
    bool removedAirport = airportNetwork.removeAirport(5);
    if (removedAirport) {
        std::cout << "Airport removed successfully..." << std::endl;
    }
    else {
        std::cout << "Airport not removed..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting removeAirport method by removing DFW..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.displayAirportInfo(1);
    removedAirport = airportNetwork.removeAirport(1);
    if (removedAirport) {
        std::cout << "Airport removed successfully..." << std::endl;
    }
    else {
        std::cout << "Airport not removed..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting clearAirport method..." << std::endl;
    std::cout << dbldashes << std::endl;;
    airportNetwork.clearAirports();
    airportNetwork.graphEmpty();
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nAdding All Airports from Graph Design (n = 6)..." << std::endl;
    std::cout << dbldashes << std::endl;
    arraySize = (sizeof(tempIDs)/sizeof(tempIDs[0]));
    for (int count = 0; count < arraySize; count++ ) {
        addedAirport = airportNetwork.addAirport(tempIDs[count], &tempCodes[count]);
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

    std::cout << "Adding routes as per Adjacency List." << std::endl;
    std::cout << dbldashes << std::endl;
    //AUS
    int ausArrivals [] {1};
    int ausWeights [] {190};
    int ausArraySize = (sizeof(ausArrivals)/sizeof(ausArrivals[0]));
    for (int ausCount = 0; ausCount < ausArraySize; ausCount++) {
        routeAdded = airportNetwork.addRoute(tempIDs[0], ausArrivals[ausCount], ausWeights[ausCount]);
        if (routeAdded) {
            std::cout << "Route added successfully..." << std::endl;
        }
        else {
            std::cout << "Route not added..." << std::endl;
        }
    }
    //DFW
    for (int count = 0; count < dfwArraySize; count++) {
        routeAdded = airportNetwork.addRoute(tempIDs[1], dfwArrivals[count], dfwWeights[count]);
        if (routeAdded) {
            std::cout << "Route added successfully..." << std::endl;
        }
        else {
            std::cout << "Route not added..." << std::endl;
        }
    }
    //SFO
    int sfoArrivals [] {1, 4, 5};
    int sfoWeights [] {1463, 679, 338};
    int sfoArraySize = (sizeof(sfoArrivals)/sizeof(sfoArrivals[0]));
    for (int count = 0; count < sfoArraySize; count++) {
        routeAdded = airportNetwork.addRoute(tempIDs[2], sfoArrivals[count], sfoWeights[count]);
        if (routeAdded) {
            std::cout << "Route added successfully..." << std::endl;
        }
        else {
            std::cout << "Route not added..." << std::endl;
        }
    }
    //LGA
    int lgaArrivals [] {1};
    int lgaWeights [] {1387};
    int lgaArraySize = (sizeof(lgaArrivals)/sizeof(lgaArrivals[0]));
    for (int count = 0; count < lgaArraySize; count++) {
        routeAdded = airportNetwork.addRoute(tempIDs[3], lgaArrivals[count], lgaWeights[count]);
        if (routeAdded) {
            std::cout << "Route added successfully..." << std::endl;
        }
        else {
            std::cout << "Route not added..." << std::endl;
        }
    }
    //SEA
    int seaArrivals [] {1, 2};
    int seaWeights [] {1658, 679};
    int seaArraySize = (sizeof(seaArrivals)/sizeof(seaArrivals[0]));
    for (int count = 0; count < seaArraySize; count++) {
        routeAdded = airportNetwork.addRoute(tempIDs[4], seaArrivals[count], seaWeights[count]);
        if (routeAdded) {
            std::cout << "Route added successfully..." << std::endl;
        }
        else {
            std::cout << "Route not added..." << std::endl;
        }
    }
    //LAX
    int laxArrivals [] {2};
    int laxWeights [] {338};
    int laxArraySize = (sizeof(laxArrivals)/sizeof(laxArrivals[0]));
    for (int count = 0; count < laxArraySize; count++) {
        routeAdded = airportNetwork.addRoute(tempIDs[5], laxArrivals[count], laxWeights[count]);
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

    std::cout << "\nTesting adding a route to an airport that already contains that route (DFW-LGA)..." << std::endl;
    std::cout << dbldashes << std::endl;
    routeAdded = airportNetwork.addRoute(1, 3, 9001);
    if (routeAdded) {
        std::cout << "Route added successfully..." << std::endl;
    }
    else {
        std::cout << "Route not added..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting adding an edge from LAX to AUS...(Route count should go up)" << std::endl;
    std::cout << dbldashes << std::endl;;
    routeAdded = airportNetwork.addRoute(5,0,1568);
    if (routeAdded) {
        std::cout << "Route added successfully..." << std::endl;
    }
    else {
        std::cout << "Route not added..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting making AUS<->LAX (undirected route now...) route count should NOT go up..." << std::endl;
    std::cout << dbldashes << std::endl;
    routeAdded = airportNetwork.addRoute(0,5,1568);
    if (routeAdded) {
        std::cout << "Route added successfully..." << std::endl;
    }
    else {
        std::cout << "Route not added..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    std::cout << "\nTesting making AUS->DFW route directed (previously undirected; Removing DFW->AUS) count should NOT go down..." << std::endl;
    std::cout << dbldashes << std::endl;
    routeRemoved = airportNetwork.removeRoute(1,0);
    if (routeRemoved) {
        std::cout << "Route removed successfully..." << std::endl;
    }
    else {
        std::cout << "Route not removed..." << std::endl;
    }
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    return 0;
};
