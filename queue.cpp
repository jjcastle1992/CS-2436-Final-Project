/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Implementation file for my queue object that be used for BFS as the "position" queue that will keep track of where I am in the traversal of my graph.
**********************/

#include "queue.h"
Queue::Queue(int queueSize) {
    this->size = queueSize;
    this->front = -1;
    this->back = -1;
    for (int count = 0; count < queueSize; count++) {
        queue [count] = -1;
    }
}

Queue::~Queue() {
    //there is nothing to do to clean up this object, so this is blank
}

bool Queue::push(int newNumber) {
    bool enqueued = false;

    if (back < MAXSIZE - 1) {
        queue[++back] = newNumber;
        if (front < 0) {
            front++;
        }
        enqueued = true;
    }
    return enqueued;
}

bool Queue::pull(int *dequeuedValue) {
    bool dequeued = false;
    if (back > -1) {
        *dequeuedValue = queue[front];
        for (int count = front; count < back; count++ ){
            queue[count] = queue [count+1];
        }
        queue[back] = -1; // Not really needed, but easier to debug visually...
        back--;
        if (back < 0) {
            front = -1;
        }
        dequeued = true;
    }
    return dequeued;
}

bool Queue::peek(int *peekedNumber) {
    bool peeked = false;
    if (front > -1) {
        *peekedNumber = queue[front];
        peeked = true;
    }
    return peeked;
}

bool Queue::isEmpty() {
    return (front < 0);
}

// this is a programmer debug routine
// DO NOT LEAVE THIS IN PRODUCTION CODE
void Queue::dumpStack() {
    std::cout << "dumping whole queue..." << std::endl;
    if (!isEmpty()) {
        for (int i = front; i <= back; i++) {
            std::cout << queue[i] << std::endl;
        }
    } else {
        std::cout << "\tqueue is empty" << std::endl;
    }
    std::cout << std::endl;
}