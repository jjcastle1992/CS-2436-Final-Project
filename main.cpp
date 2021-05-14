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

    std::cout << "\nTesting DFS...(Reflects Map)" << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.depthFirstSearch(0);
    airportNetwork.depthFirstSearch(1);
    airportNetwork.depthFirstSearch(3);
    airportNetwork.depthFirstSearch(55);
    airportNetwork.depthFirstSearch(-1);

    std::cout << "\nTesting BFS...(Reflects Map)" << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.breadthFirstSearch(0);
    airportNetwork.breadthFirstSearch(1);
    airportNetwork.breadthFirstSearch(3);
    airportNetwork.breadthFirstSearch(66);
    airportNetwork.breadthFirstSearch(-1);

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

    std::cout << "\nClearing airportNetwork using clearAirports (should leave no airports OR routes)..." << std::endl;
    std::cout << dbldashes << std::endl;
    airportNetwork.clearAirports();
    airportNetwork.displayGraph();
    std::cout << "Number of airports: " << airportNetwork.numberAirports() << std::endl;
    std::cout << "Number of routes: " << airportNetwork.numberRoutes() << std::endl;

    Graph fig20_22;
    int fig20_22Nodes[] {0,1,2,3,4,5};
    string fig20_22Labels [] {"0", "1", "2", "3", "4", "5"};

    std::cout << "\nAdding All Vertices from Figure 20-22 (n = 6)..." << std::endl;
    std::cout << dbldashes << std::endl;
    arraySize = (sizeof(fig20_22Nodes)/sizeof(fig20_22Nodes[0]));
    for (int count = 0; count < arraySize; count++ ) {
        bool addedVertex = fig20_22.addAirport(fig20_22Nodes[count], &fig20_22Labels[count]);
        if (addedVertex) {
            std::cout << "Vertex added successfully..." << std::endl;
        }
        else {
            std::cout << "Vertex not added..." << std::endl;
        }
    }
    fig20_22.displayGraph();
    std::cout << "Number of Vertices: " << fig20_22.numberAirports() << std::endl;
    std::cout << "Number of Edges: " << fig20_22.numberRoutes() << std::endl;

    std::cout << "\nTesting addition of undirected edges so that graph matches Fig-20-22..." << std::endl;
    std::cout << dbldashes << std::endl;
    int fig20_22Count = 0;
    int node0Adj [] {1, 4};
    int node0Weight [] {9,1};
    int node0AdjArraySize = (sizeof(node0Adj)/sizeof(node0Adj[0]));
    for (int count = 0; count < node0AdjArraySize; count++) {
        bool edgeAdded = fig20_22.addRoute(tempIDs[fig20_22Count], node0Adj[count], node0Weight [count]);
        if (edgeAdded) {
            std::cout << "Edge added successfully..." << std::endl;
        }
        else {
            std::cout << "Edge not added..." << std::endl;
        }
    }
    fig20_22Count++;

    int node1Adj [] {0, 2, 4};
    int node1Weight [] {9, 8, 6};
    int node1AdjArraySize = (sizeof(node1Adj)/sizeof(node1Adj[0]));
    for (int count = 0; count < node1AdjArraySize; count++) {
        bool edgeAdded = fig20_22.addRoute(tempIDs[fig20_22Count], node1Adj[count], node1Weight [count]);
        if (edgeAdded) {
            std::cout << "Edge added successfully..." << std::endl;
        }
        else {
            std::cout << "Edge not added..." << std::endl;
        }
    }
    fig20_22Count++;

    int node2Adj [] {1, 3, 5};
    int node2Weight [] {8, 5, 2};
    int node2AdjArraySize = (sizeof(node2Adj)/sizeof(node2Adj[0]));
    for (int count = 0; count < node2AdjArraySize; count++) {
        bool edgeAdded = fig20_22.addRoute(tempIDs[fig20_22Count], node2Adj[count], node2Weight [count]);
        if (edgeAdded) {
            std::cout << "Edge added successfully..." << std::endl;
        }
        else {
            std::cout << "Edge not added..." << std::endl;
        }
    }
    fig20_22Count++;

    int node3Adj [] {2};
    int node3Weight [] {5};
    int node3AdjArraySize = (sizeof(node3Adj)/sizeof(node3Adj[0]));
    for (int count = 0; count < node3AdjArraySize; count++) {
        bool edgeAdded = fig20_22.addRoute(tempIDs[fig20_22Count], node3Adj[count], node3Weight [count]);
        if (edgeAdded) {
            std::cout << "Edge added successfully..." << std::endl;
        }
        else {
            std::cout << "Edge not added..." << std::endl;
        }
    }
    fig20_22Count++;

    int node4Adj [] {0, 1, 5};
    int node4Weight [] {1, 6, 7};
    int node4AdjArraySize = (sizeof(node4Adj)/sizeof(node4Adj[0]));
    for (int count = 0; count < node4AdjArraySize; count++) {
        bool edgeAdded = fig20_22.addRoute(tempIDs[fig20_22Count], node4Adj[count], node4Weight [count]);
        if (edgeAdded) {
            std::cout << "Edge added successfully..." << std::endl;
        }
        else {
            std::cout << "Edge not added..." << std::endl;
        }
    }
    fig20_22Count++;

    int node5Adj [] {2, 4};
    int node5Weight [] {2, 7};
    int node5AdjArraySize = (sizeof(node5Adj)/sizeof(node5Adj[0]));
    for (int count = 0; count < node5AdjArraySize; count++) {
        bool edgeAdded = fig20_22.addRoute(tempIDs[fig20_22Count], node5Adj[count], node5Weight [count]);
        if (edgeAdded) {
            std::cout << "Edge added successfully..." << std::endl;
        }
        else {
            std::cout << "Edge not added..." << std::endl;
        }
    }
    fig20_22Count++;

    fig20_22.displayGraph();
    std::cout << "Number of Vertices: " << fig20_22.numberAirports() << std::endl;
    std::cout << "Number of Edges: " << fig20_22.numberRoutes() << std::endl;

    std::cout << "\nTesting DFS...(Fig 20-22)" << std::endl;
    std::cout << dbldashes << std::endl;
    fig20_22.depthFirstSearch(0);
    fig20_22.depthFirstSearch(1);
    fig20_22.depthFirstSearch(3);
    fig20_22.depthFirstSearch(55);
    fig20_22.depthFirstSearch(-1);

    std::cout << "\nTesting BFS...(Fig 20-22)" << std::endl;
    std::cout << dbldashes << std::endl;
    fig20_22.breadthFirstSearch(0);
    fig20_22.breadthFirstSearch(1);
    fig20_22.breadthFirstSearch(3);
    fig20_22.breadthFirstSearch(66);
    fig20_22.breadthFirstSearch(-1);
    fig20_22.displayGraph();
    std::cout << "Number of Vertices: " << fig20_22.numberAirports() << std::endl;
    std::cout << "Number of Edges: " << fig20_22.numberRoutes() << std::endl;
    fig20_22.clearAirports();
    fig20_22.displayGraph();
    std::cout << "\nClearing Graph...(Fig 20-22)" << std::endl;
    std::cout << dbldashes << std::endl;
    std::cout << "Number of Vertices: " << fig20_22.numberAirports() << std::endl;
    std::cout << "Number of Edges: " << fig20_22.numberRoutes() << std::endl;

    return 0;
};
