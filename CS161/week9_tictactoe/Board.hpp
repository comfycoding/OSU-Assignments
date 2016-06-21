/*********************************************************************
** Author: Darlene Zouras
** Date: February 29, 2016
** Description: TicTacToe.cpp, TicTacToe.hpp, Board.cpp and Board.hpp
** This program initializes a game of Tic Tac Toe by first asking a
** user whether Xs or Os will go first- this defines which player is
** which. The play() function loops while also counting the number
** of turns and determining whose turn it is. at the end of each loop
** of the play() function, the gameState() function is run to check
** whether to end the game or to continue looping.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <cstdlib>
using namespace std;

enum Status {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
	Status state;
	char board[3][3];						// the 3x3 array member
	int moveX, moveY;						// makeMove variables
public:
	Board();								// default constructor
	void print();							// prints the current board
	bool makeMove(char, int, int);			// If a space is taken, returns false
	Status gameState();						// Returns one value of the
											// enumorator
};

#endif
