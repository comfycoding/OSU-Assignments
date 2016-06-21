/*********************************************************************
** Program Filename: Ant.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Ant class file
** Collection of functions to read or manipulate the data in the 
** ant objects.
*********************************************************************/

#include "Ant.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: Constructor
 ** Description: Developed from what was once the Critter constructor,
 ** it takes in two coordinates and a number for a name and initializes
 ** a count variable to 0.
 *********************************************************************/

Ant::Ant(int x, int y, int name) {
    xCoord = x;
    yCoord = y;
    critName = name;
    this->count = 0;
}

/*********************************************************************
 ** Function: breed
 ** Description: This function first checks the Ant object's step 
 ** counter. If it is 3, a new critter is created.
 ** If it is not 3, add one to the count variable.
 ** Parameters: Receives the coordinates for the new Ant object, as well
 ** as a number to serve as that Ant's name.
 *********************************************************************/

Ant *Ant::breed(int x, int y, int n) { 
    if (count == 3) {
        this->count = 1;
        return new Ant(x, y, n);
    }
    else {
        this->count++;
        return NULL;
    }
}

/*********************************************************************
 ** Function: getID
 ** Description: Returns the ID for all Ants, which is 1.
 *********************************************************************/

int Ant::getID() { 
    return 1;       // all Ants have ID 1
}