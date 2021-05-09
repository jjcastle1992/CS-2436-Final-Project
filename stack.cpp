/*********************
Name: James Castle
COSC 2436 Final Project
Purpose: Implementation file for my stack object that be used for DFS and BFS as the "memory" stack that will keep track of vertices visited. This will also double as the "position" ADT for DFS.
**********************/

#include "stack.h"
Stack::Stack() {
    /* the 'this' designation is optional. use it where there
     * is ambiguity or just to be complete and precise. here it
     * is used just to show it's usage for demonstration purposes.
     */
    this->top = -1;
    for (int count = 0; count < STACKSIZE; count++) {
        stack[count] = -1;
    }
}

Stack::~Stack() {
    //there is nothing to do to clean up this object, so this is blank
}

bool Stack::push(int i) {
    bool pushed = false;

    if (top < STACKSIZE - 1) {
        stack[++top] = i;
        pushed = true;
    }

    return pushed;
}

bool Stack::pop(int *ret) {
    bool popped = false;
    if (top > -1) {
        *ret = stack[top--];
        popped = true;
    }
    return popped;
}

bool Stack::peek(int *ret) {
    /* normally peek and pop should have identical in interfaces.
     * this is only different to demonstrate an alternate solution.
     * In a real solution, this technique would be the more
     * appropriate method for both pop() and peek().
     */
    bool popped = false;
    if (top > -1) {
        *ret = stack[top];
        popped = true;
    }
    return popped;
}

bool Stack::isEmpty() {
    return (top < 0);
}

// this is a programmer debug routine
// DO NOT LEAVE THIS IN PRODUCTION CODE
void Stack::dumpStack() {
    std::cout << "dumping whole stack..." << std::endl;
    if (!isEmpty()) {
        for (int i = top; i >= 0; i--) {
            std::cout << stack[i] << std::endl;
        }
    } else {
        std::cout << "\tstack is empty" << std::endl;
    }
    std::cout << std::endl;
}