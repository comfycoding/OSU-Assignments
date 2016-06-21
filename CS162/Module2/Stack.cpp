/*********************************************************************
** Program Filename: Stack.cpp
** Author: Darlene Zouras
** Date: 5/11/2016
** Description: Holds the StackList class member functions.
*********************************************************************/

#include "Stack.hpp"
#include <iostream>

/*********************************************************************
 ** Function: add
 ** Description: Receives a character, if the top pointer is set to NULL,
 ** then top gets set to the new node. Otherwise, the new node is
 ** created as a new top, and the old one is set as the next node.
 *********************************************************************/

void StackList::add(char ch)
{
    if (top == NULL)
        top = new StackNode(ch);
    else
        top = new StackNode(ch, top);
}

/*********************************************************************
 ** Function: remove
 ** Description: Returns the character held in the top node, but first
 ** sets the next node as a new top and then deletes the original top
 ** node.
 *********************************************************************/

char StackList::remove()
{
    StackNode *stackPtr;
    stackPtr = top;
    char ch = top->c;
    top = stackPtr->next;
    delete stackPtr;
    return ch;
}
