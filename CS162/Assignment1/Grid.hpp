/*********************************************************************
** Program Filename: Grid.hpp
** Author: Darlene Zouras
** Date: 4/8/2016
** Description: Grid class header file.
** Input:
** Output: 
*********************************************************************/

#ifndef GRID_HPP
#define GRID_HPP
#include "Ant.hpp"

class Grid {
private:
	int h, w, antX, antY, numMoves;
	char **grid;
	char black, white, ant;
	Ant ant1;

public:
	Grid(int a, int b, int x, int y, int moves);
	void run();

	void fillArray(char **&grid);
	void printArray();
	
	void updateAnt();
	void flipCell(char **&grid, int y, int x);

	void remove(char **&grid);
};

#endif