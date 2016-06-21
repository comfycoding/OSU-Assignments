#include "Critter.hpp"
#include <time.h>
#include <cstdlib>

/*********************************************************************
 ** Function: Critter default constructor
 ** Description: Sets the default variables for the Critter class
 ** Parameters: Receives nothing, launches at the creation of a Critter object
 ** Pre-Conditions: Critter object is created.
 ** Post-Conditions: Sets the default xCoord and yCoord of the critter
 ** without necessarily needing the grid information 
 ** srand (time(NULL)) also sets the rand seed based on the time.
 *********************************************************************/
Critter::Critter(){
    srand (time(NULL));
    xCoord = 1;
    yCoord = 1;
    numMoves = 0;
}

/*********************************************************************
 ** Function: setStartX
 ** Description: Initialize the x coordinate of the critter.
 ** Parameters: Receive the number of x spaces on the grid.
 ** Pre-Conditions: The grid and critter objects must have already been
 ** initialized.
 ** Post-Conditions: The starting xCoord is set.
 *********************************************************************/
void Critter::setStartX(int x) {
    xCoord = rand() % x + 1;
}

/*********************************************************************
 ** Function: setStartY
 ** Description: Initialize the y coordinate of the critter.
 ** Parameters: Receive the number of y spaces on the grid.
 ** Pre-Conditions:The grid and critter objects must have already been
 ** initialized.
 ** Post-Conditions: The starting yCoord is set and numMoves is
 ** increased to 1.
 *********************************************************************/

void Critter::setStartY(int y) {
    yCoord = rand() % y + 1;
    numMoves ++;     
}

/*********************************************************************
 ** Function: move
 ** Description: Moves the critter randomly in no more than 4 spaces
 ** in any direction.0
 ** Parameters: Receives nothing.
 ** Pre-Conditions: This function is launched by the Path class after each
 ** turn where the critter is still inside the grid.
 ** Post-Conditions: The critter is moved randomly to a new space, and the 
 ** numMoves variable is increased once.
 *********************************************************************/
void Critter::move() {
    xCoord = xCoord + (rand() % 9 + (-4));
    yCoord = yCoord + (rand() % 9 + (-4));

    numMoves ++;
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
 ** Post-Conditions: The Path object knows th elocation fo the critter,
 ** is able to place it on the grid.
 *********************************************************************/

int Critter::getY() {
    return yCoord;  }

/*********************************************************************
 ** Function: getMoves
 ** Description: Gives reading access to the numMoves variable.
 ** Parameters: Receives nothing, returns the int held in the numMoves variable.
 ** Pre-Conditions: Called by the Path class.
 ** Post-Conditions: Depending on what numMoves holds, it launches different
 ** pieces of the Path object's udpateLocation function. Also, this number is
 ** displayed to the user after the critter is squished.
 *********************************************************************/

int Critter::getMoves() {
    return numMoves;    }
