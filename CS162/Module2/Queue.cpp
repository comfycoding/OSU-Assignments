/*********************************************************************
** Program Filename: Queue.cpp
** Author: Darlene Zouras
** Date: 5/11/2016
** Description: Holds the QueueList member functions.
*********************************************************************/

#include "Queue.hpp"
#include <iostream>

/*********************************************************************
 ** Function: add
 ** Description: if front is set to NULL, then the new node is
 ** set to the front pointer. Or it checks if there is only one
 ** node in the list- if that is the case, front->next is set to the
 ** new node and the new node is set to the end pointer.
 ** In a list that has both front and end pointers, the new node
 ** becomes a new end pointer, and the next and previous pointers are
 ** adjusted.
 *********************************************************************/

void QueueList::add(char ch)
{
    if (front == NULL)
    {
        front = new QueueNode(ch);
    }
    else
    {
        QueueNode *newNode, *holdNode;
        newNode = new QueueNode(ch);

        if (front->next == NULL)
        {
            end = newNode;
            front->next = end;
            end->previous = front;
        }
        else
        {
            holdNode = end;
            newNode->previous = holdNode;
            end = newNode;
            holdNode->next = end;
        }
    }
}

/*********************************************************************
 ** Function: remove
 ** Description: The front node's character is returned, but only after
 ** the second node is set as the new front, and the previous pointer
 ** is set correctly to NULL. The old front pointer is deleted.
 *********************************************************************/

char QueueList::remove()
{
    QueueNode *queuePtr;
    queuePtr = front;
    char ch = queuePtr->c;
    front = queuePtr->next;
    // front->previous = NULL;
    delete queuePtr;
    return ch;
}
