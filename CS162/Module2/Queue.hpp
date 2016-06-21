/*********************************************************************
** Program Filename: Queue.hpp
** Author: Darlene Zouras
** Date: 5/11/2016
** Description: Holds the QueueList header information.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

class QueueList
{
protected:
    struct QueueNode
    {
        char c;
        QueueNode *next;
        QueueNode *previous;
        QueueNode(char ch, QueueNode *n = NULL, QueueNode *p = NULL)
        {
            c = ch;
            next = n;
            previous = p;
        }
    };
    QueueNode *front;
    QueueNode *end;
public:
    /*********************************************************************
     ** Function: QueueList constructor
     ** Description: sets the front and end pointers to NULL
     *********************************************************************/
    QueueList() { front = NULL; end = NULL; };      // constructor

    void add(char ch);
    char remove();
};

#endif
