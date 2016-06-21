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

#include "TicTacToe.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char pickFirst;
	cout << "Player One: X or O?\n";
	cin >> pickFirst;
	TicTacToe game(pickFirst);
	game.play();

	return 0;
}
