/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Interface file for my graph object that will contain an object that will map airports (vertices) and routes (edges)
**********************/


#ifndef CODE_ASSIGN9_GRAPH_H
#define CODE_ASSIGN9_GRAPH_H

#include "vertices.h"
#include <vector>
#include <iostream>

class Graph {
public:
    //Constructor
    Graph ();
    //Destructor
    ~Graph();
    //Getters
    int numberAirports();
    int numberRoutes ();
    string findAirport (int);
    bool graphEmpty ();

    //Vertex add/removal
    bool addAirport (int, string);
    bool removeAirport (int);
    void clearAirports ();
    bool addRoute (Airport*, int);
    bool removeRoute (Airport*);

    //Printing/Traversal methods
    void displayGraph ();
    void depthFirstSearch();
    void breadthFirstSearch();

private:
    int airportCount; // Increases or decreases with number of vertices (airports)
    int routeCount; // increases or decreases with the number of routes (edges)
    int airportID; // always increases as vertices are added. Never decreases.
    std::vector <Airport*> availableAirports; // Our list of currently available airports
};

#endif //CODE_ASSIGN9_GRAPH_H
