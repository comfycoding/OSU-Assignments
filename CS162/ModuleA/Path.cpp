#include "Path.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: Constructor
 ** Description: Sets two numbers as the width and height of the grid.
 ** Parameters: Receives two ints 
 ** Pre-Conditions: Path object is created by the main function, sends
 ** two ints as the size of the x and y axes.
 ** Post-Conditions: The size of the array is set.
 *********************************************************************/

Path::Path(int a, int b) {
    x = a;
    y = b;

    grid = new char*[y];

    for (int i = 0; i < y; i++) {
    	grid[i] = new char[x];
    }									// creates grid[y][x]
}

/*********************************************************************
 ** Function: updateLocation
 ** Description: This function accesses information from the Critter
 ** object to be used by this Path object.
 ** Parameters: Receives nothing, returns a boolean value.
 ** Pre-Conditions: It checks the Critter object for what turn it is on.
 ** If it is turn 0, it sets the critter's starting position.
 ** If it is not turn 0, the critter is moved. Then, this function
 ** collects the data regarding where it has moved to. 
 ** Post-Conditions: If the critter is still on 
 ** the grid, it returns true. Otherwise it returns false.
 *********************************************************************/

bool Path::updateLocation() {

	// If it is move 0, place the critter in a random spot on the grid.
	if (critter.getMoves() == 0) {
		critter.setStartX(x);
		critter.setStartY(y);
	}
	else
	{	critter.move();	}

	critX = critter.getX();
	critY = critter.getY();
	if (critX > x || critY > y) 
		return false;
	if (critX < 1 || critY < 1)
		return false;
	else
		return true;
}

/*********************************************************************
 ** Function: gridSet
 ** Description: Sets the values of the grid.
 ** Parameters: Receives nothing, returns nothing.
 ** Pre-Conditions: This function is launched from the gridDisplay function
 ** Post-Conditions: Sets all of the spaces to an empty ' ' character. 
 ** In the spot where the critter is found, the character is set to 'C'.
 *********************************************************************/
void Path::gridSet(char **&grid) {
	// Set values of grid to blanks or the character spot C
	int fixX = (critX - 1);
	int fixY = (critY - 1);

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			grid[i][j] = ' ';

			if (i == fixY && j == fixX)
				grid[i][j] = 'C';
		}
	}

	//if grid[fixY][fixX] = 'C';
	cout << "\nThe grid has been set." << endl;
}

/*********************************************************************
 ** Function: gridDisplay
 ** Description: Displays the grid.
 ** Parameters: Receives nothing, returns nothing.
 ** Pre-Conditions: This function is called from the main function on the
 ** condition that the Critter is still located on the grid (assessed by 
 ** the boolean value returned by the updateLocation function)
 ** Post-Conditions: Every time this function is called the grid is reset
 ** and then each row is printed (as well as a border around it).
 *********************************************************************/
void Path::gridDisplay() {
	cout << "\nThe critter is in spot (" << critX << ", " << critY << ")." << endl;

	gridSet(grid);

	char s = '*';

	// Display the grid
	for (int m = 0; m < (x+2); m++)
		cout << s << " ";
	cout << endl;

	for (int i = 0; i < y; i ++) {
		cout << s << " ";
		for (int j =0; j < x; j++) {
			cout << grid[i][j] << " ";
		}
		cout << s << " " << endl;
	} 

	for (int m = 0; m < (x+2); m++)
		cout << s << " ";
}

/*********************************************************************
 ** Function: squashed
 ** Description: Alerts the user that the critter has moved off of the grid.
 ** Parameters: Receives none, returns none.
 ** Pre-Conditions: This function is called by the main function once the 
 ** updateLocation returns false.
 ** Post-Conditions: Returns the coordinates (located off of the grid) to
 ** where the critter has moved, displays an empty grid, and prints how many
 ** moves it has taken for the critter to randomly leave the grid.
 *********************************************************************/
void Path::squashed() {
	gridDisplay();
	cout << "\nThe critter moved off of the grid. It was squashed in " << (critter.getMoves()) << " moves." << endl;
	remove();
}

/*********************************************************************
 ** Function: remove
 ** Description: Deletes the memory set aside for the 
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

 void Path::remove() {
	for (int i = 0; i < y; i++){
		delete(grid[y]);
	}

	delete(grid);

	cout << "Grid memory has been deleted.";
}