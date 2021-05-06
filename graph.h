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

#define NUMDASH 30

class Graph {
public:
    //Constructor
    Graph ();
    //Destructor
    ~Graph(); // calls clearAirports
    //Getters
    int numberAirports();
    int numberRoutes ();
    bool findAirport (int, string*); //Public method that takes an Airport ID and returns the Airport Code if found.
    bool graphEmpty ();

    //Vertex & Edge add/removal
    bool addAirport (int, string*); // Airport ID (protected against negatives and duplicates currently), Airport Code (3 letter string) - not yet validated/constrained to 3 alpha characters. If valid 3 character string, should autoconvert to uppercase.
    bool removeAirport (int);
    void clearAirports ();
    bool addRoute (int, int, int); // Starting Airport ID, Destination Airport ID, Route length in miles.
    bool removeRoute (int, int); // take in a Starting Airport ID and a Destination Airport ID.

    //Printing/Traversal methods
    void displayGraph ();
    void displayAirportInfo (int);
    void depthFirstSearch();
    void breadthFirstSearch();

private:
    int findAirport (int); //Overload of find airport for use in add/remove Airport methods that scraps returning a string for returning the element in the vector that the airport ID was found. -1 means not found.
    bool edgeFound (int, int, int* ); //takes in two airports vertices (start, end), returns (by ref) number of times found (0 = does not exist; 1 = directed; 2 = undirected) If found, does NOT increment/decrement route Count.
    int airportCount; // Increases or decreases with number of vertices (airports)
    int routeCount; // increases or decreases with the number of routes (edges)
    std::vector <Airport*> availableAirports; // Our list of currently available airports
};

#endif //CODE_ASSIGN9_GRAPH_H
