/*********************************************************************
** Program Filename: Grid.hpp
** Author: Darlene Zouras
** Date: 4/8/2016
** Description: Public functions that make up the Grid class.
** Input:
** Output: 
*********************************************************************/

#include "Grid.hpp"
#include <iostream>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: Grid constructor
 ** Description: 
 ** Parameters: Receives the height and width of the grid and
 ** the placement of the ant.
 ** Pre-Conditions: The numbers have been set by the user
 ** Post-Conditions: The Ant object is created here in this function
 ** and the grid's dynamic array is created.
 *********************************************************************/

Grid::Grid(int a, int b, int x, int y, int moves) {
 	w = a;
 	h = b;
 	numMoves = moves;
 	black = '#';
	white = ' ';
	ant = '*';

 
 	grid = new char*[h];
 	
 	for (int i = 0; i < h; i++)
 		grid[i] = new char[w];			// grid[x][y]

	fillArray(grid);
 	
 	antX = x;
 	antY = y;
 	ant1.setX(antX);
 	ant1.setY(antY);
 	updateAnt();

 	cout << "The Ant object has been created and grid is initialized." << endl;
 	cout << "The grid's width is " << w << " and its height is " << h << "." << endl;
 	cout << "The ant will make " << numMoves << " steps." << endl;
}

/*********************************************************************
 ** Function: Grid run
 ** Description: For every step the ant is meant to take, the board is
 ** printed, the ant makes a move, and the ant's next step is generated.
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions: If the ant is going to walk off of the board, it 
 ** ends its walk before it does.
 *********************************************************************/

void Grid::run() {
	for (int i = 0; i < numMoves; i++){
		cout << "Now printing turn " << i + 1 << ".";
		cout << endl;
		printArray();
		cout << endl;

		ant1.move(grid[antY][antX]);
		flipCell(grid, antY, antX);

		updateAnt();
		if (antX == -1 || antY == -1) {
			cout << "\n  The ant has hit a wall, it is stopping after " << i << " moves." << endl;
			i = numMoves; 
		}
		if (antX == w || antY == h) {
			cout << "\nThe ant has hit a wall, it is stopping after " << i << " moves." << endl;
			i = numMoves;
		}

	}

	remove(grid);
}

/*********************************************************************
 ** Function:fillArray
 ** Description: Fills the array, it starts off completely white.
 ** Parameters: Receives the array pointer, and the width and height
 ** Pre-Conditions: This is called from the Grid constructor
 ** Post-Conditions: Each space in the array holds a ' ' white space.
 *********************************************************************/

void Grid::fillArray(char **&grid) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			grid[i][j] = white;
		}
	}
}

/*********************************************************************
 ** Function: printArray
 ** Description: Prints the grid, as well as a border. 
 ** Parameters: Receives the array pointer, and height and width ints.
 ** Pre-Conditions: Called from the main function for every turn the ant
 ** will make a move.
 ** Post-Conditions: Prints the grid.
 *********************************************************************/

 void Grid::printArray() {
 	char s = '0';

 	for (int m = 0; m < (w+2); m++)
		cout << s << " ";
	cout << endl;

 	for (int i=0; i < h; i++) {
 		cout << s << " ";

 		for (int j = 0; j < w; j++) {
 			if (i == antY && j == antX)
 				cout << ant << " ";
 			else
 				cout << grid[i][j] << " ";
 		}
 		cout << s << " " << endl;
 	}

 	for (int m = 0; m < (w+2); m++)
		cout << s << " ";
 	cout << endl;
 }

/*********************************************************************
 ** Function: updateAnt
 ** Description: Updates the ant's x and y coordinates. The values
 ** get subtracted by 1 to better fit inside the array
 ** Parameters: 
 ** Pre-Conditions:
 ** Post-Conditions: 
 *********************************************************************/

 void Grid::updateAnt() {
 	antX = (ant1.getX() - 1);
 	antY = (ant1.getY() - 1);
 }

/*********************************************************************
 ** Function: flipCell
 ** Description: This function flips the color of the cell
 ** Parameters: Receives the cell address, returns nothing.
 ** Pre-Conditions: 
 ** Post-Conditions: Flips the char variable held in the cell address.
 *********************************************************************/

void Grid::flipCell(char **&grid, int y, int x) {
	if (grid[y][x] == white) {
		grid[y][x] = black;	}
	else if (grid[y][x] == black) {
		grid[y][x] = white;	}
}

/*********************************************************************
 ** Function: remove
 ** Description: Frees up the memory held by the dynamic array
 ** Parameters: Receives and returns nothing.
 ** Pre-Conditions: Runs at the end of the array.
 ** Post-Conditions: Memory no longer holds space for this array.
 *********************************************************************/

void Grid::remove(char **&grid) {
 	for (int i = 0; i < h; i++) {
 		delete(grid[i]);
 	}

 	delete(grid);
}

