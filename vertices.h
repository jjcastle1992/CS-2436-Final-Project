/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Interface file for my that contains the struct prototypes for an airport (vertex), and the pointers
 that make up the routes (edges)
**********************/

#ifndef CODE_ASSIGN9_VERTICES_H
#define CODE_ASSIGN9_VERTICES_H

#include <string>
using std::string;

struct Data {
    int id;
    string airportCode;
    int routeMiles;
};

struct DataVertex {
    Data airportInfo;
    DataVertex *departure, *arrival;
};

#endif //CODE_ASSIGN9_VERTICES_H
