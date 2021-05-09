/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Interface file for my stack object that be used for DFS and BFS as the "memory" stack that will keep track of vertices visited. This will also double as the "position" ADT for DFS.
**********************/
#ifndef CODE_ASSIGN9_STACK_H
#define CODE_ASSIGN9_STACK_H

#define STACKSIZE 100

#include <iostream>

class Stack {

public:

    Stack();  // constructor
    ~Stack();  // destructor

    bool pop(int*);
    bool peek(int*);
    bool push(int);
    bool isEmpty();

    // this is a programmer debug routine
    // DO NOT LEAVE THIS IN PRODUCTION CODE
    void dumpStack();

private:

    int top;  //do not initialize here, that's what the constructor is for
    int stack[STACKSIZE];

};

#endif //CODE_ASSIGN9_STACK_H
