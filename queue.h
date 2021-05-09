/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Interface file for my queue object that be used for BFS as the "position" queue that will keep track of where I am in the traversal of my graph.
**********************/

#ifndef CODE_ASSIGN9_QUEUE_H
#define CODE_ASSIGN9_QUEUE_H
#include <iostream>

class Queue {

public:

    Queue(int);  // constructor
    ~Queue();  // destructor

    bool pull(int*);
    bool peek(int*);
    bool push(int);
    bool isEmpty();

    // this is a programmer debug routine
    // DO NOT LEAVE THIS IN PRODUCTION CODE
    void dumpStack();

private:
    int size; // so we can pass and set this value when doing BFS.
    int back;  //do not initialize here, that's what the constructor is for
    int front;
    int queue[];

};

#endif //CODE_ASSIGN9_QUEUE_H
