/*********************************************************************
** Program Filename: CarQueue.hpp
** Author: Darlene Zouras
** Date: 5/17/2016
** Description: The CarQueue class header files.
*********************************************************************/

#ifndef CARQUEUE_HPP
#define CARQUEUE_HPP
#include <iostream>

class carQueue
{
protected:

    // carNode
    // Holds the queue of cars as they arrive at each direction's light.
    // The value held is the iteration number where the car arrives.
    // There is a front and end, and a next pointer.
    struct carNode
    {
        int car;
        carNode *next;
        carNode(int c, carNode *next1 = NULL)
        {
            car = c;
            next = next1;
        }
    };
    carNode *front;
    carNode *end;
public:

    /*********************************************************************
    ** Function: constructor
    ** Description: Initializes the front and end variables to NULL.
    *********************************************************************/

    carQueue() { front = NULL; end = NULL; }

    void add(int c);        // will place the cars at the end of the list
    int remove(int n);           // will return the int held at the head, and
                            // also remove the node from the list.
};

#endif
