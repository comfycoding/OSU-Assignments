/*********************************************************************
** Program Filename: Ant.cpp
** Author: Darlene Zouras
** Date: 4/8/2016
** Description: Public functions that make up the Ant class.
** Input:
** Output: 
*********************************************************************/

#include "Ant.hpp"
#include <iostream>

/*********************************************************************
 ** Function: Ant constructor
 ** Description: Initializes the starting coordinates of the ant
 ** Parameters:
 ** Pre-Conditions: Initialized by a Grid object
 ** Post-Conditions: The direction of the Ant object is set to start
 ** facing left.
 *********************************************************************/

Ant::Ant() {
	direction = 1;		// ant starts facing left
}

/*********************************************************************
 ** Function: setX
 ** Description: Sets the xCoord variable for the Ant object.
 ** Parameters: Receives one integer
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void Ant::setX(int x) {
	xCoord = x;
}

/*********************************************************************
 ** Function: setY
 ** Description: Sets the yCoord variable for the Ant object.
 ** Parameters: Receives one integer
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void Ant::setY(int y) {
	yCoord = y;
}

/*********************************************************************
 ** Function: getX
 ** Description: Allows reading access to the ant's current X coordinate.
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

int Ant::getX() {
	return xCoord;
}

/*********************************************************************
 ** Function: getY
 ** Description: Allows reading access to the ant's current Y coordinate.
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

int Ant::getY() {
	return yCoord;
}

/*********************************************************************
 ** Function: move
 ** Description: Based on the cell color and ant direction, the ant
 ** updates its coordinates and then updates its direction.
 ** Parameters: Receives the character held in the grid at the ant's
 ** current spot.
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void Ant::move(char cellColor) {
	if (cellColor == '#'){
		if (direction == 1)
			yCoord++;
		if (direction == 2)
			xCoord++;
		if (direction == 3)
			yCoord--;
		if (direction ==4)
			xCoord--;

		direction++;
		if (direction == 5)
			direction = 1;
	}
	else {
		if (direction == 1)
			yCoord--;
		if (direction == 2)
			xCoord--;
		if (direction == 3)
			yCoord++;
		if (direction == 4)
			xCoord++;

		direction--;
		if (direction == 0)
			direction = 4;
	}

}