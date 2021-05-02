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
}
int Graph::numberRoutes () {
    return routeCount;
}
string Graph::findAirport (int) {

}

//Vertex add/removal
bool Graph::addAirport (int internalID, string airportCode) {

}
bool Graph::removeAirport (int) {

}
void Graph::clearAirports () {

}

//Printing/Traversal methods
void Graph::displayGraph () {
    for (int count = 0; count < availableAirports.size(); count++) {
        if (availableAirports.size() == 0){
            std::cout << "Graph empty: there are currently no airports available to display" << std::endl;
        }
        else {
            Airport *currentAirport = availableAirports [count];
            if (currentAirport) {
                std::cout << "Current Airport (ID: " << currentAirport->airportInfo.id << ") - " << currentAirport->airportInfo.airportCode << std::endl;
                std::cout << "Available flights from this airport: ";
                while (currentAirport->arrival) {
                    std::cout << currentAirport->airportInfo.airportCode << " - " << currentAirport->arrival->airportInfo.airportCode << ", ";
                    if (currentAirport->arrival->arrival) {
                        currentAirport = currentAirport->arrival;
                    }
                    else {
                        std::cout<< "\nEnd of the list of flights departing from " << currentAirport->airportInfo.airportCode << std::endl;
                    }
                }
            }
        }
    }
}
void Graph::depthFirstSearch() {

}
void Graph::breadthFirstSearch() {

}