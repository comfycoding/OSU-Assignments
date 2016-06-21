/*********************************************************************
** Program Filename: Doodlebug.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Doodlebug class file
** Collection of functions to read or manipulate the data in the 
** doodlebug objects.
*********************************************************************/

#include "Doodlebug.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: Constructor
 ** Description: Developed from what was once the Critter constructor,
 ** it takes in two coordinates and a number for a name and initializes
 ** a count variable to 0.
 *********************************************************************/

Doodlebug::Doodlebug(int x, int y, int name) {
	xCoord = x;
	yCoord = y;
	critName = name;
	count = 0;
	cStarve = 0;
}

/*********************************************************************
 ** Function: getID
 ** Description: Returns the ID for Doodlebugs, which is 2.
 *********************************************************************/

int Doodlebug::getID() {
	return 2;			// all Doodlebugs have ID 2
}

/*********************************************************************
 ** Function: starve
 ** Description: Doodlebugs starve in three moves if they do not 
 ** eat another ant. This function returns a boolean value to the 
 ** run function, it only returns true if the Doodlebug has starved,
 ** and then the space it occupies is set to NULL.
 *********************************************************************/

bool Doodlebug::starve() {
	if (cStarve == 3) {
		return true;
	}

	else {
		// cout << "Doodlebug is on starve count " << cStarve << "." << endl;
		this->cStarve++;
		return false;
	}
}

/*********************************************************************
 ** Function: eat
 ** Description: Resets the starve count.
 *********************************************************************/

void Doodlebug::eat() {
	cStarve = 0;
	// The following line is for testing purposes
	// cout << "Starve count reset." << endl;
}

/*********************************************************************
 ** Function: breed
 ** Description: Doodlebugs breed on their 8th turn, and the counts
 ** only accumulate if they move.
 *********************************************************************/

Doodlebug *Doodlebug::breed(int x, int y, int n) { 
    if (count == 8) {
        this->count = 1;
        // The following line is for testing purposes
        // cout << "New Doodlebug born." << endl;
        return new Doodlebug(x, y, n);
    }
    else {
        this->count++;
        // The following line is for testing purposes
        // cout << "Doodlebug on step count " << count << endl;
        return NULL;
    }
}