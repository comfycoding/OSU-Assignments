/*********************************************************************
** Program Filename: Path.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Path class functions
*********************************************************************/

#include "Path.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: Path constructor
 ** Description: Creates the grid by initializing the 2D array of critter
 ** pointers and setting some importCritter variables.
 ** Parameters: Receives the width and height of the grid as set by the
 ** user.
 *********************************************************************/

Path::Path(int a, int b) {
    x = a;
    y = b;
    empty = ' ';
    crit = 'C';				// Critters will be represented on the grid as C
    ant = '*';				// Ants will be represented as A
    doodlebug = '#';		// Doodlebugs will be represented as D

    grid = new Critter**[y];

    for (int i = 0; i < y; i++) {
    	grid[i] = new Critter*[x];
    }									// creates grid[y][x]

    gridSet(grid);						// initializes grid to NULL
}

/*********************************************************************
 ** Function: setCritters
 ** Description: Iterates through a for loop for Ants and Doodlebugs
 ** to be randomly placed on the grid. The Ants get placed first, and
 ** then the Doodlebugs.
 ** Parameters: receives the integer variable set by the user for
 ** number of Ants, as well as number of Doodlebugs.
 *********************************************************************/

void Path::setCritters(int Ants, int Doodlebugs) {
	numA = Ants;
	numD = Doodlebugs;
	srand (time(NULL));

	// Sets the Ants on the grid
	for (int i = 0; i < numA; i++){
		int randX = rand() % x + 1;
		int randY = rand() % y + 1;
		if (grid[randY-1][randX-1] == NULL) {
			grid[randY-1][randX-1] = new Ant(randX, randY, i);
		}
		else
			i--;				// this prevents moving on to the next critter!
	}

	// Sets the Doodlebugs on the grid
	for (int i = 0; i < numD; i++){
		int randX = rand() % x + 1;
		int randY = rand() % y + 1;
		if (grid[randY-1][randX-1] == NULL) {
			grid[randY-1][randX-1] = new Doodlebug(randX, randY, i);
		}
		else
			i--;				// this prevents moving on to the next critter!
	}

	names = numA + numD;
}

/*********************************************************************
 ** Function: gridSet
 ** Description: Initializes the grid as an array that points to NULL 
 ** at every space.
 *********************************************************************/

void Path::gridSet(Critter* **&grid) {
	// Set values of grid to NULL
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			grid[i][j] = NULL;
		}
	}
}

/*********************************************************************
 ** Function: run
 ** Description: Iterates through each turn, and then it iterates through
 ** each space on the 2D array. When the space on the array is not NULL
 ** AND the Critter pointer in that spot has not already made its move
 ** during this iteration, then the critter moves one spot in a random
 ** direction. It then must check whether or not that would move the 
 ** critter off fo the grid or into another critter's spot. If it will do
 ** either of these things, the critter's location is set again so that
 ** it does not move anywhere on the grid.
 ** Parameters: Receives the number of moves, which is set by the user
 ** from the main function
 *********************************************************************/

void Path::run(int numMoves) {
	for (int i = 0; i < numMoves; i++) {
		cout << "\nMaking move " << i + 1 << "." << endl;

		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {

				// Make sure that the it is a space with a critter
				// and that it is a critter that has not yet moved this turn!
				if (grid[j][k] != NULL && grid[j][k]->getMove() == i) {
					
					grid[j][k]->move();

					int tempX = grid[j][k]->getX();
					int tempY = grid[j][k]->getY();

					// Check whether the Doodlebug has starved		
					if (grid[j][k]->starve() == true) {
							grid[j][k] = NULL;
							// cout << "Doodlebug has starved." << endl;
							names--;
					}
					
					// Check that the new space is within the grid boundaries
					else if (tempY < y && tempY > -1 && tempX < x && tempX > -1) {
						
						// Check that the space is empty
						if (grid[tempY][tempX] == NULL) {
							grid[tempY][tempX] = grid[j][k];
							int name = name++;

							checkBreed(j, k, tempY, tempX, i);
						}
						
						// If a doodlebug moves onto a space occupied by an Ant, eat it
						else if (grid[j][k]->getID() == 2 && grid[tempY][tempX]->getID() == 1) {
							grid[j][k]->eat();
							names--;						// Decrease critter counter by 1
							grid[j][k]->setMove(i+1);
							grid[tempY][tempX] = grid[j][k];

							checkBreed(j, k, tempY, tempX, i);	
						}
						
						// If the space is occupied or no one gets eaten, don't move.
						else {
							grid[j][k]->setY(j);
							grid[j][k]->setX(k);
						}
					}
					else {
						grid[j][k]->setY(j);
						grid[j][k]->setX(k);
					}
				}
			}
		}
		gridDisplay();
		
		if ( names >= (x * y)){
		cout << "\nThe critters have filled the grid. Ending at turn " << i + 1 << "." << endl;
		i = numMoves;		// THIS stops the loop.
		}
	}
}

/*********************************************************************
 ** Function: checkBreed
 ** Description: Checks on whether or not a Critter has taken enough
 ** steps to breed.
 *********************************************************************/

void Path::checkBreed(int j, int k, int tempY, int tempX, int i) {
	grid[j][k] = grid[tempY][tempX]->breed(k, j, names);
	if (grid[j][k] != NULL) {
		grid[j][k]->setMove(i+1);
		names++;
	}
}

/*********************************************************************
 ** Function: gridDisplay
 ** Description: Prints the grid.
 ** Prints a border around the grid, and then for each NULL space it 
 ** prints an empty space. It checks the ID of a non-NULL space. Ants
 ** IDs are set to 1, Doodlebugs IDs are set to 2.
 *********************************************************************/

void Path::gridDisplay() {
	char s = '.';

	cout << endl;
	for (int m = 0; m < (x+2); m++)
		cout << s << " ";
	cout << endl;

	for (int i = 0; i < y; i ++) {
		cout << s << " ";
		for (int j =0; j < x; j++) {
			if (grid[i][j] == NULL)
				cout << empty << " ";
			else if (grid[i][j]->getID() == 1)		// checks for Ant
				cout << ant << " ";
			else if (grid[i][j]->getID() == 2)		// checks for Doodlebug
				cout << doodlebug << " ";
			else
				cout << crit << " ";
		}
		cout << s << " " << endl;
	} 

	for (int m = 0; m < (x+2); m++)
		cout << s << " ";
	cout << endl;
} 

/*********************************************************************
 ** Function: remove
 ** Description: Deletes the memory set aside for the dynamic 2d array
 *********************************************************************/

 void Path::remove() {
	delete[] grid;

	cout << "\nGrid memory has been deleted." << endl;
}