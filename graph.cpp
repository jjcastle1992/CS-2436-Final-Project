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
bool Graph::findAirport (int searchAirport, string *foundCode) {
    bool foundAirport = false;
    Airport *end = availableAirports.back();
    if (searchAirport > -1) {
        int count = 0;
        while ((availableAirports[count]->airportInfo.id != searchAirport) && (availableAirports[count] != end)) {
            availableAirports[count++];
        }
        if (availableAirports[count]->airportInfo.id == searchAirport) {
            *foundCode = availableAirports[count]->airportInfo.airportCode;
            foundAirport = true;
        }
    }
    return foundAirport;
}

bool Graph::graphEmpty () {
    bool empty = availableAirports.empty();
    return empty;
};

//Vertex add/removal
bool Graph::addAirport (int id, string *airportCode) {
    bool airportAdded = false;
    int duplicateCheck = findAirport(id);
    if ((id > -1) && (duplicateCheck == -1)) { // Will ultimately look to set ID randomly and will check for duplicates...Would like a way to create a list of acceptable 3-character codes to validate from at some point...
        Airport *addedAirport = new Airport;
        addedAirport->airportInfo.id = id;
        addedAirport->airportInfo.airportCode = *airportCode;
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
    bool removedAirport = false;

    return removedAirport;
}

void Graph::clearAirports () {

}

bool Graph::addRoute (int startingID, int destinationID, int routeLength) {
    bool routeAdded = false;
    if ((routeLength > -1) && (startingID > -1) && (destinationID > -1) && (startingID != destinationID)) { //ultimately want to find a way to validate Airports in some sort of lookup list.
        int startingAirportIndex = findAirport(startingID);
        int destinationAirportIndex = findAirport(destinationID);
        if ((startingAirportIndex> -1) && (destinationAirportIndex > -1)) {
            Airport *startingAirport = availableAirports [startingAirportIndex];
            Airport *temp = availableAirports [destinationAirportIndex];
            Airport *newRoute = new Airport;
            newRoute->arrival = nullptr;
            newRoute->airportInfo.id = temp->airportInfo.id;
            newRoute->airportInfo.airportCode = temp->airportInfo.airportCode;
            if (startingAirport->arrival == nullptr) {
                startingAirport->arrival = newRoute;
                newRoute->departure = startingAirport;
            }
            else {
                Airport *position = startingAirport;
                while (position->arrival) {
                    position = position->arrival;
                }
                position->arrival = newRoute;
                newRoute->departure = position;
            }
            newRoute->airportInfo.routeMiles = routeLength;
            routeAdded = true;
            routeCount++;
        }
    }
    return routeAdded;
}

bool Graph::removeRoute (int, int) {
    bool removedRoute = false;

    return removedRoute;
}

//Printing/Traversal methods
void Graph::displayGraph () {
    string dashes = std::string (NUMDASH, '-');
    if (availableAirports.empty()) {
        std::cout << "Graph empty: there are currently no airports available to display" << std::endl;
    }
    else {
        for (int count = 0; count < availableAirports.size(); count++) {
            Airport *currentAirport = availableAirports [count];
            if (currentAirport) {
                std::cout << "\nCurrent Airport (ID: " << currentAirport->airportInfo.id << ") - " << currentAirport->airportInfo.airportCode << std::endl;
                std::cout << "Available destinations from this airport: ";
                if (currentAirport->arrival) {
                    while (currentAirport->arrival) {
                        std::cout << currentAirport->arrival->airportInfo.airportCode << ", ";
                        currentAirport = currentAirport->arrival;
                    }
                    std::cout << "end...";
                }

                else {
                    std::cout << "No flights available at this time.";
                }
                std::cout << "\n" <<dashes;
            }
        }
        std::cout << std::endl;
    }
}

void Graph::displayAirportInfo (int searchAirportId) {
    string dashes = std::string (NUMDASH, '-');
    if (searchAirportId > -1) {
        Airport *currentAirport = availableAirports [searchAirportId]; // This should work because ID should be analogous to element in the vector
        if (currentAirport) {
            std::cout << "Current Airport (ID: " << currentAirport->airportInfo.id << ") - " << currentAirport->airportInfo.airportCode << std::endl;
            std::cout << "Available destinations from this airport: ";
            if (currentAirport->arrival) {
                while (currentAirport->arrival) {
                    std::cout << currentAirport->arrival->airportInfo.airportCode << ", ";
                    currentAirport = currentAirport->arrival;
                }
                std::cout << "end...";
            }
            else {
                std::cout << "No flights available at this time.";
            }
            std::cout << "\n" <<dashes;
        }
        std::cout << std::endl;
    }
}

void Graph::depthFirstSearch() {

}
void Graph::breadthFirstSearch() {

}

int Graph::findAirport(int internalSearchAirport) {
    int airportIndex = -1; // this is the default that indicates the airport ID was NOT found in the vector.
    Airport *end = availableAirports.back();
    if (internalSearchAirport > -1) {
        int count = 0;
        while ((availableAirports[count]->airportInfo.id != internalSearchAirport) && (availableAirports[count] != end)) {
            availableAirports[count++];
        }
        if (availableAirports[count]->airportInfo.id == internalSearchAirport) {
            airportIndex = count;
        }
    }
    return airportIndex;
}

