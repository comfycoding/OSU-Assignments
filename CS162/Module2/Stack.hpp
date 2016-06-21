/*********************************************************************
** Program Filename: Stack.hpp
** Author: Darlene Zouras
** Date: 5/11/2016
** Description: holds the StackList class header information.
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>

class StackList
{
protected:
    // the list!
    struct StackNode
    {
        char c;
        StackNode *next;
        StackNode(char ch, StackNode *nextC = NULL)
        {
            c = ch;
            next = nextC;
        }
    };
    StackNode *top;
public:
    /*********************************************************************
     ** Function: StackList constructor
     ** Description: sets the pointer "top" to NULL.
     *********************************************************************/
    StackList() { top = NULL; };    // Constructor

    void add (char ch);
    char remove();
};

#endif
