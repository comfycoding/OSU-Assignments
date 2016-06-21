/*********************************************************************
** Program Filename: Ant.cpp
** Author: Darlene Zouras
** Date: 4/13/2016
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
 ** Function: getCount
 ** Description: Returns the count variable
 *********************************************************************/

int Ant::getCount() {
    return count;
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
        // cout << "The critter has left a new critter in its old space." << endl;
        this->count = 0;
        return new Ant(x, y, n);
    }
    else {
        this->count++;
        return NULL;
    }
}