/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Implementation file for my graph object that will contain an object that will map airports (vertices) and routes (edges)
**********************/

#include "graph.h"
//Constructor
Graph::Graph () {
    airportCount = 0;
    routeCount = 0;
    airportID = 0;
    // I don't need to pre-setup my vector here because I can dynamically add/remove elements as we go in the add/remove methods.
};
//Destructor
Graph::~Graph() {

}
//Getters
int Graph::numberAirports() {
    return airportCount;
    //return availableAirports.size();
}
int Graph::numberRoutes () {
    return routeCount;
}
string Graph::findAirport (int) {

}

//Vertex add/removal
bool Graph::addAirport (int id, string airportCode) {
    bool airportAdded = false;
    if (id > -1) { // Will ultimately look to set ID randomly and will check for duplicates...Would like a way to create a list of acceptable 3-character codes to validate from at some point...
        Airport *addedAirport = new Airport;
        addedAirport->airportInfo.id = id;
        addedAirport->airportInfo.airportCode = airportCode;
        addedAirport->arrival = nullptr;
        addedAirport->departure = nullptr;
        addedAirport->airportInfo.routeMiles = -1; //Flag that there is no route.
        availableAirports.push_back(addedAirport);
        airportAdded = true;
        airportCount++;
    }
    return airportAdded;
}
bool Graph::removeAirport (int) {

}
void Graph::clearAirports () {

}

bool Graph::addRoute (Airport* newRoute) {

}
bool Graph::removeRoute (Airport* deleteRoute) {

}

//Printing/Traversal methods
void Graph::displayGraph () {
    if (availableAirports.empty()) {
        std::cout << "Graph empty: there are currently no airports available to display" << std::endl;
    }
    else {
        for (int count = 0; count < availableAirports.size(); count++) {
            Airport *currentAirport = availableAirports [count];
            if (currentAirport) {
                std::cout << "\nCurrent Airport (ID: " << currentAirport->airportInfo.id << ") - " << currentAirport->airportInfo.airportCode << std::endl;
                std::cout << "Available flights from this airport: ";
                if (currentAirport->arrival) {
                    while (currentAirport->arrival) {
                        std::cout << currentAirport->airportInfo.airportCode << " - " << currentAirport->arrival->airportInfo.airportCode << ", ";
                        if (currentAirport->arrival->arrival) {
                            currentAirport = currentAirport->arrival;
                        }
                    }
                }
                else {
                    std::cout << "No flights available at this time.";
                }
                std::cout<< "\nEnd of the list of flights departing from " << currentAirport->airportInfo.airportCode << std::endl;
            }
        }
    }
}
void Graph::depthFirstSearch() {

}
void Graph::breadthFirstSearch() {

}