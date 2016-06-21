/*********************************************************************
** Program Filename: Critter.cpp
** Author: Darlene Zouras
** Date: 4/13/2016
** Description: Critter class file
** Collection of functions to read or manipulate the data in the 
** critter objects.
*********************************************************************/

#include "Critter.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: Critter default constructor
 ** Description: Sets the starting location of the Critter object, 
 ** as well as its name. Initializes its move count to 0.
 ** Parameters: Receives three integers- one x coordinate, one y 
 ** coordinate, and also its integer name.
 *********************************************************************/
Critter::Critter() {
    moveCount = 0;
}

/*********************************************************************
 ** Function: setX
 ** Description: Sets the X coordinate.
 *********************************************************************/
void Critter::setX(int x) {
    xCoord = x;
}

/*********************************************************************
 ** Function: setY
 ** Description: Sets the Y coordinate.
 *********************************************************************/

void Critter::setY(int y) {
    yCoord = y;    
}

/*********************************************************************
 ** Function: setName
 ** Description: Sets the name of a critter to better identify it from
 ** other critters that move around the grid.
 ** It is named by a number.
 *********************************************************************/

void Critter::setName(int name) {
    critName = name;
}

/*********************************************************************
 ** Function: getName
 ** Description: Returns the critter's integer name to the Path 
 ** class that calls it.
 *********************************************************************/

int Critter::getName() {
    return critName;
}

/*********************************************************************
 ** Function: move
 ** Description: Moves the critter one space in a random
 ** direction.
 *********************************************************************/
void Critter::move() {
    direction = (rand() % 4) + 1;
    if (direction == 1)
        xCoord++;
    if (direction == 2)
        xCoord--;
    if (direction == 3)
        yCoord++;
    if (direction == 4)
        yCoord--;

    moveCount++;
}

/*********************************************************************
 ** Function: getMove
 ** Description: Returns the integer held in the move counter variable.
 *********************************************************************/

int Critter::getMove() {
    return moveCount;
}

/*********************************************************************
 ** Function: setMove
 ** Description: Sets the movecount of the critter. This function is 
 ** used only in the instance that a new Critter has been initiated
 ** after the run() function in the Path class has already begun.
 *********************************************************************/

void Critter::setMove(int m) {
    moveCount = m;
}

/*********************************************************************
 ** Function: getX
 ** Description: Gives reading access to the x coordinate of the
 ** critter.
 ** Parameters: Receives nothing, returns the int held in the x variable
 ** Pre-Conditions: Called by the Path class
 ** Post-Conditions: The Path object knows the location of the critter, 
 ** is able to tell where to place it on the grid.
 *********************************************************************/
int Critter::getX() {
    return xCoord;  }

/*********************************************************************
 ** Function: getY
 ** Description: Gives reading access to the x coordinate of the critter.
 ** Parameters: Receives nothing, returns the int held in the y variable
 ** Pre-Conditions: Called by the Path class
 ** Post-Conditions: The Path object knows the location fo the critter,
 ** is able to place it on the grid.
 *********************************************************************/

int Critter::getY() {
    return yCoord;  }