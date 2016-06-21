/*********************************************************************
** Program Filename: CarQueue.cpp
** Author: Darlene Zouras
** Date: 5/17/2016
** Description: The CarQueue class functions.
*********************************************************************/


#include "CarQueue.hpp"
#include <iostream>

/*********************************************************************
 ** Function: add
 ** Description: Adds a node to the carNode queue. The value it holds
 ** is the iteration in which the car arrives.
 ** It places the cars at the end of the queue.
 *********************************************************************/

void carQueue::add(int c)
{
    carNode *newNode = new carNode(c);

    if (front == NULL)
    {
        front = newNode;
        end = front;
    }
    if (front->next == NULL)
    {
        end = newNode;
        front->next = end;
    }
    else
    {
        end->next = newNode;
        end = end->next;
    }
}

/*********************************************************************
 ** Function: remove
 ** Description: Removes a node in the queue, and returns the integer
 ** value held in the node to be used by the State class.
 ** It removes the first node of the queue.
 *********************************************************************/

int carQueue::remove(int n)
{
    if (front == NULL)
        return 0;
    else
    {
        carNode *temp;
        int carTime;
        temp = front;
        carTime = temp->car;
        front = front->next;
        delete temp;
        return (n - carTime);
    }
}
