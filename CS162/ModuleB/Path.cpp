/*********************************************************************
** Program Filename: Path.cpp
** Author: Darlene Zouras
** Date: 4/9/2016
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
 ** pointers and setting some important variables.
 ** Parameters: Receives the width and height of the grid as set by the
 ** user.
 *********************************************************************/

Path::Path(int a, int b) {
    x = a;
    y = b;
    empty = ' ';
    crit = 'C';

    grid = new Critter**[y];

    for (int i = 0; i < y; i++) {
    	grid[i] = new Critter*[x];
    }									// creates grid[y][x]

    gridSet(grid);						// initializes grid to NULL
}

/*********************************************************************
 ** Function: setCritters
 ** Description: Iterates through a for loop for each critter that the
 ** user sets to be in the grid. The critter is placed in a random 
 ** place and given a name (the number iteration where it is created).
 ** It does check that the critter being made is on an empty space.
 ** If not, the loop repeats the iteration.
 ** Parameters: receives the integer variable set by the user for
 ** number of critters to create on the grid.
 *********************************************************************/

void Path::setCritters(int crits) {
	numCritters = crits;
	srand (time(NULL));

	for (int i = 0; i < numCritters; i++){
		int randX = rand() % x + 1;
		int randY = rand() % y + 1;
		if (grid[randY-1][randX-1] == NULL) {
			//critter.setX(randX);
			//critter.setY(randY);
			//critter.setName(i+1);
			grid[randY-1][randX-1] = new Critter(randX, randY, i);
		}
		else
			i--;				// this prevents moving on to the next critter!
	}
}

/*********************************************************************
 ** Function: gridSet
 ** Description: Initializes the grid as an array that points to NULL 
 ** at every space.
 *********************************************************************/

void Path::gridSet(Critter* **&grid) {
	// Set values of grid to blanks

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			grid[i][j] = NULL;
		}
	}
	
	cout << "\nThe empty grid has been set." << endl;
}

/*********************************************************************
 ** Function: findCritters
 ** Description: This function is more for organization and confirmation
 ** that the critters move or stay in their spots. It prints out the 
 ** critter's number as well as its location on the grid. It must
 ** iterate through the 2D array to find the critters.
 *********************************************************************/

void Path::findCritters() {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (grid[i][j] != NULL) {
				cout << "Critter " << grid[i][j]->getName() << " is at " << j << ", " << i << "." << endl;
			}
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
	int k = 0;

	for (int i = 0; i < numMoves; i++) {
		cout << "\nMaking move " << i + 1 << "." << endl;

		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {

				// Make sure that the it is a space with a critter
				// and that it is a critter that has not yet moved this turn!
				if (grid[j][k] != NULL && grid[j][k]->getMove() == i) {
					
					cout << "\nTrying to move critter " << grid[j][k]->getName() << " at " << k << ", " << j << "." << endl;
					grid[j][k]->move();

					int tempX = grid[j][k]->getX();
					cout << "Its new X coordinate is " << tempX << "." << endl;
					int tempY = grid[j][k]->getY();
					cout << "Its new Y coordinate is " << tempY << "." << endl;

					if (tempY < y && tempY > -1 && tempX < x && tempX > -1) {
						if (grid[tempY][tempX] == NULL) {
							cout << "Critter " << grid[j][k]->getName() << " at " << k << ", " << j;
							cout << " moving to " << tempX << ", " << tempY << "." << endl;
							grid[tempY][tempX] = grid[j][k];
							grid[j][k] = NULL;
							
						}
						else {
							cout << "Critter will move onto another critter, keeping critter stationary." << endl;
							
							// Place the X and Y coordinates back in their old places!
							grid[j][k]->setY(j);
							grid[j][k]->setX(k);
						}
					}
					else {
						cout << "Critter will move off of the grid, it will remain in its old position." << endl;
						
						// Place the X and Y coordinates back in their old places!
						grid[j][k]->setY(j);
						grid[j][k]->setX(k);
					}
				}
			}
		}

		gridDisplay();
		findCritters();
	}
}

/*********************************************************************
 ** Function: gridDisplay
 ** Description: Prints the grid.
 ** Prints a border around the grid, and then for each NULL space it 
 ** prints an empty space. If the space holds anything else but NULL, 
 ** it prints a C.
 *********************************************************************/

void Path::gridDisplay() {
	char s = '*';

	// Display the grid
	cout << endl;
	for (int m = 0; m < (x+2); m++)
		cout << s << " ";
	cout << endl;

	for (int i = 0; i < y; i ++) {
		cout << s << " ";
		for (int j =0; j < x; j++) {
			if (grid[i][j] == NULL)
				cout << empty << " ";
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
	for (int i = 0; i < y; i++){
		delete(grid[y]);
	}

	delete(grid);

	cout << "\n\nGrid memory has been deleted." << endl;
}