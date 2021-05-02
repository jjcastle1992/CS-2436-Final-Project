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
bool Graph::addAirport (int, string) {

}
bool Graph::removeAirport (int) {

}
void Graph::clearAirports () {

}

//Printing/Traversal methods
void Graph::displayGraph () {

}
void Graph::depthFirstSearch() {

}
void Graph::breadthFirstSearch() {

}