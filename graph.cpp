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
    clearAirports();
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
bool Graph::removeAirport (int airportID) {
    bool removedAirport = false;
    if (airportID > -1) {
       int airportIndex = findAirport(airportID);
       if (airportIndex > -1) {
           //Remove Edges Loop first to remove routes from other Airport vertices
           for (int count = 0; count < availableAirports.size(); count++) {
               removeRoute(count, airportID);
           }
           //Then navigate to the current airport node and do all the edge deletions, vertex deletion and vector resizing
           Airport *currentAirport = availableAirports [airportIndex];
           while (currentAirport->arrival) {
               currentAirport = currentAirport->arrival;
           }
           do {
               if (currentAirport->departure) {
                   Airport *tempAirport = currentAirport->departure;
                   currentAirport->departure->arrival = nullptr;
                   currentAirport->arrival = nullptr;
                   currentAirport->departure = nullptr;
                   delete currentAirport;
                   routeCount--;
                   currentAirport = tempAirport;
               }
               else { // must be at the head node.
                   currentAirport->arrival = nullptr;
                   currentAirport = nullptr;
                   delete currentAirport;
                   availableAirports.erase(availableAirports.begin()+airportIndex); // Should delete the index @ airportIndex.
                   removedAirport = true;
                   airportCount--;
               }
           } while (currentAirport);
       }
    }

    return removedAirport;
}

void Graph::clearAirports () {
    int vectorSize = availableAirports.size();
    for (int count = 0; count <= vectorSize; count++) {
        removeAirport(count);
    }
}

bool Graph::addRoute (int startingID, int destinationID, int routeLength) {
    bool routeAdded = false;
    if ((routeLength > -1) && (startingID > -1) && (destinationID > -1) && (startingID != destinationID)) { //ultimately want to find a way to validate Airports in some sort of lookup list.
        int startingAirportIndex = findAirport(startingID);
        int destinationAirportIndex = findAirport(destinationID);
        if ((startingAirportIndex> -1) && (destinationAirportIndex > -1)) {
           bool routeExists = duplicateEdge(startingID, destinationID);
           if (!routeExists) {
               Airport *startingAirport = availableAirports [startingAirportIndex];
               Airport *temp = availableAirports [destinationAirportIndex];
               Airport *newRoute = new Airport;
               newRoute->arrival = nullptr;
               newRoute->airportInfo.id = temp->airportInfo.id;
               newRoute->airportInfo.airportCode = temp->airportInfo.airportCode;
               int numberRoutes = 0;
               bool found = edgeFound(startingID, destinationID, &numberRoutes);
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
               if ((!found) && (numberRoutes == 0)) {
                   routeCount++;
               }
           }
        }
    }
    return routeAdded;
}

bool Graph::removeRoute (int startingID, int destinationID) {
    bool removedRoute = false;
    if ((startingID > -1) && (destinationID > -1) && (startingID != destinationID)) {
        int startingAirportIndex = findAirport(startingID);
        if (startingAirportIndex > -1) {
            Airport *currentAirport = availableAirports [startingAirportIndex];
            while ((currentAirport->arrival) && (currentAirport->airportInfo.id != destinationID)) {
                currentAirport = currentAirport->arrival;
            }
            if ((!currentAirport->arrival) && (currentAirport->airportInfo.id == destinationID)) { //tail case
                currentAirport->departure->arrival = nullptr;
                currentAirport->arrival = nullptr;
                currentAirport->departure = nullptr;
                delete currentAirport;
                removedRoute = true;
                int numberRoutes = 0;
                bool found = edgeFound(startingID, destinationID, &numberRoutes);
                if ((!found) && (numberRoutes == 0)) {
                    routeCount--;
                }
            }
            else if ((currentAirport->arrival) && (currentAirport->airportInfo.id == destinationID)) { //mid-case
                currentAirport->departure -> arrival = currentAirport->arrival;
                currentAirport->arrival->departure = currentAirport->departure;
                currentAirport->arrival = nullptr;
                currentAirport->departure = nullptr;
                delete currentAirport;
                removedRoute = true;
                int numberRoutes = 0;
                bool found = edgeFound(startingID, destinationID, &numberRoutes);
                if ((!found) && (numberRoutes == 0)) {
                    routeCount--;
                }
            }
            else {
                // Not found...could set removedRoute to false, but already done... not sure what to put here.
            }
        }
    }
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

void Graph::depthFirstSearch(int startingVertex) {
    //Start @ Begin Vertex (find element based on ID)  & print. Add ID to a stack of visited numbers (memory stack) and a position stack (temp stack). (push to both)
    Airport *position;
    Airport *end = availableAirports.back();
    bool vectorEnd = false;
    if (availableAirports[startingVertex] == end) {
        vectorEnd = true;
    }
    int startIndex = findAirport(startingVertex);
    if (startIndex > -1) {
        std::vector <int>::iterator iterator;
        iterator = find (memory.begin(), memory.end(), startingVertex);
        if (iterator == memory.end()) { // Means not found...
            position = availableAirports [startingVertex];
            memory.push_back(position->airportInfo.id);
            graphPosition.push_back(position->airportInfo.id);

            std::cout << startingVertex << " -> ";
            while (position->arrival) {
                position = position->arrival;
                int newID = position->airportInfo.id;
                iterator = find (memory.begin(), memory.end(), newID);
                if (iterator == memory.end()) { // Means not found...
                    depthFirstSearch(newID);
                }
            }
        }
    }

    //Look at the ID of the next edge (arrival) and see if it is on the memory stack. If not, push the new ID onto the memory stack and position stack. and set new position ot

    // IF ID is not in stack, print and add the ID to the stack. if the ID is in the stack, don't print, and set the next starting vertex to the next edge on this node.

    //If you hit a node with no edge, thjen pop the last thing  off the stack, and ask what edge is next that is not in the stack. Keep popping as neded

    //Repeat until  all unique airport IDs are marked as visited.
}
void Graph::breadthFirstSearch(int startingVertex) {
    //Start @ begin vertex push all edges onto the memory stack and all except starting node in position queue and print as you push.

    //If arrivals = null pop first item off position queue

}

int Graph::findAirport(int internalSearchAirport) {
    int airportIndex = -1; // this is the default that indicates the airport ID was NOT found in the vector.
    bool Empty = graphEmpty();
    if (!Empty) {
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
    }
    return airportIndex;
}

bool Graph::edgeFound(int startingId, int destinationId, int *numTimesFound ) {
    bool foundEdge = false;
    *numTimesFound = 0; // 0 = Edge does not exist; 1 = directed edge; 2 = undirected edge.
    int startingIndex = findAirport(startingId);
    int destinationIndex = findAirport(destinationId);

    if ((startingId > -1) && (destinationId > -1) && (startingIndex > -1) && (destinationIndex > -1)) {
        Airport *position = availableAirports[startingIndex];
        while ((position->arrival) && (position->arrival->airportInfo.id != destinationId)) {
            position = position->arrival;
        }
        if ((position->arrival) && (position->arrival->airportInfo.id == destinationId)) {
            foundEdge = true;
            (*numTimesFound)++;
        }
        position = availableAirports[destinationIndex];
        while ((position->arrival) && (position->arrival->airportInfo.id != startingId)) {
            position = position->arrival;
        }
        if ((position->arrival) && (position->arrival->airportInfo.id == startingId)) {
            foundEdge = true;
            (*numTimesFound)++;
        }
    }
    return foundEdge;
}

bool Graph::duplicateEdge(int startingId, int destinationId) {
    bool duplicate = false;
    int startingIndex = findAirport(startingId);

    if ((startingId > -1) && (destinationId > -1) && (startingIndex > -1)) {
        Airport *position = availableAirports[startingIndex];
        while ((position->arrival) && (position->arrival->airportInfo.id != destinationId)) {
            position = position->arrival;
        }
        if ((position->arrival) && (position->arrival->airportInfo.id == destinationId)) {
            duplicate = true;
        }
    }
    return duplicate;
}