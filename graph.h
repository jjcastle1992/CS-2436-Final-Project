/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Interface file for my graph object that will contain an object that will map airports (vertices) and routes (edges)
**********************/


#ifndef CODE_ASSIGN9_GRAPH_H
#define CODE_ASSIGN9_GRAPH_H

#include "vertices.h" // For housing my index of Airports in my adjacency list. Also used for DFS position tracking and DFS/BFS "memory".
#include <deque> // for BFS position tracking since my queue ADT does not allow for dynamic growth/decay
#include <vector>
#include <iostream>
#include <algorithm> //find

#define NUMDASH 30

class Graph {
public:
    //Constructor
    Graph ();
    //Destructor
    ~Graph(); // calls clearAirports
    //Getters
    int numberAirports(); // Returns the number of airports (vertices) in the current graph.
    int numberRoutes (); // Returns the number of routes (edges) in the current graph
    bool findAirport (int, string*); //Public method that takes an Airport ID and returns the Airport Code if found.
    bool graphEmpty (); // Tests to see if graph is empty. Returns true if empty.

    //Vertex & Edge add/removal
    bool addAirport (int, string*); // Airport ID (protected against negatives and duplicates currently), Airport Code (3 letter string) - not yet validated/constrained to 3 alpha characters. If valid 3 character string, should autoconvert to uppercase.
    bool removeAirport (int); //Pass the internal ID of the airport you'd like to remove from the graph.
    void clearAirports (); // Clears all airports from the graph
    bool addRoute (int, int, int); // Starting Airport ID, Destination Airport ID, Route length in miles.
    bool removeRoute (int, int); // take in a Starting Airport ID and a Destination Airport ID.

    //Printing/Traversal methods
    void displayGraph (); // Displays the entire graph in adjacency list format.
    void displayAirportInfo (int); // Takes in an airport ID. Returns info about the airport including its internal ID and the routes the airport flies to (it's adjacencies)
    void depthFirstSearch(int); // Takes in a starting airport ID. Uses stack ADT to track position and memorize vertices visited.
    void breadthFirstSearch(int); // Takes in a starting airport ID. Uses stack ADT to memorize vertices visited. Uses queue ADT to track position in the graph.

private:
    int findAirport (int); //Overload of find airport for use in add/remove Airport methods that scraps returning a string for returning the element in the vector that the airport ID was found. -1 means not found.
    bool edgeFound (int, int, int* ); //takes in two airports vertices (start, end), returns (by ref) number of times found (0 = does not exist; 1 = directed; 2 = undirected) If found, does NOT increment/decrement route Count. Number of times useful if want to track directed vs. undirected edges (not doing yet).
    bool duplicateEdge (int, int); //Take in a starting airport ID and a destination airport ID. Only cares if it finds the destination ID as an edge in the starting Airport IDs Vertex.
    bool dfs (int, Airport*); // private method doing the bulk of the DFS work...
    bool bfs (int); // private method doing the bulk of the BFS work...
    int airportCount; // Increases or decreases with number of vertices (airports)
    int routeCount; // increases or decreases with the number of unique routes (edges). Undirected routes only get counted the first time.
    std::vector <Airport*> availableAirports; // Our list of currently available airports
    std::vector <int> memory;  // Support structure for DFS and BFS that tracks the nodes that have been visited.
    std::vector <int> dfsPosition; // Support structure only for DFS positional tracking due to LIFO popping capability.
    std::deque <int> bfsPosition; // Support structure only for BFS positional tracking due to FIFO dequeing capability.
};

#endif //CODE_ASSIGN9_GRAPH_H
