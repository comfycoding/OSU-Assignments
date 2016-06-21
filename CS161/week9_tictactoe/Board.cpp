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

#include "Board.hpp"

// The default constructor sets every part of the 3x3 array
// to a '-' character which will represent an empty space.
Board::Board()
{
  char empty = '-';
  for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      { board[x][y] = empty; }
    }
}

// Prints each value of the 3x3 array onto the board
void Board::print()
{
  cout << "\n  0 1 2" << endl;
  cout << "0 " << board[0][0] << " " << board[1][0] << " " << board[2][0] << endl;
  cout << "1 " << board[0][1] << " " << board[1][1] << " " << board[2][1] << endl;
  cout << "2 " << board[0][2] << " " << board[1][2] << " " << board[2][2] << endl;
}

// If the space is free, changes the char variable for the space and returns true.
// If the sapce is taken, returns false.
bool Board::makeMove(char player, int y, int x)
{
  if (board[x][y] == '-')
    { board[x][y] = player;
    return true; }
  else
    return false;
}

// gameState() checks the char variables across the board for whether either
// player has lined up a win or whether the board is completely full.
// If neither is the case, it returns UNFINISHED and play() will continue to
// loop from the TicTacToe.hpp file.
Status Board::gameState()
{
    // All 8 instances where X wins
    // ... I am not convinced that this is the most efficient way to check!!!
    if (board[0][0] == 'X' && board[0][0] == board[0][1] && board[0][0] == board[0][2])
        return state = X_WON;
    if (board[0][0] == 'X' && board[0][0] == board[1][0] && board[0][0] == board[2][0])
        return state = X_WON;
    if (board[0][0] == 'X' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return state = X_WON;
    if (board[0][1] == 'X' && board[0][1] == board[1][1] && board[0][1] == board[2][1])
        return state = X_WON;
    if (board[0][2] == 'X' && board[0][2] == board[1][2] && board[0][2] == board[2][2])
        return state = X_WON;
    if (board[1][0] == 'X' && board[1][0] == board[1][1] && board[1][0] == board[1][2])
        return state = X_WON;
    if (board[2][0] == 'X' && board[2][0] == board[2][1] && board[2][0] == board[2][2])
        return state = X_WON;
    if (board[2][0] == 'X' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
        return state = X_WON;

    // All 8 instances where O wins
    if (board[0][0] == 'O' && board[0][0] == board[0][1] && board[0][0] == board[0][2])
        return state = O_WON;
    if (board[0][0] == 'O' && board[0][0] == board[1][0] && board[0][0] == board[2][0])
        return state = O_WON;
    if (board[0][0] == 'O' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return state = O_WON;
    if (board[0][1] == 'O' && board[0][1] == board[1][1] && board[0][1] == board[2][1])
        return state = O_WON;
    if (board[0][2] == 'O' && board[0][2] == board[1][2] && board[0][2] == board[2][2])
        return state = O_WON;
    if (board[1][0] == 'O' && board[1][0] == board[1][1] && board[1][0] == board[1][2])
        return state = O_WON;
    if (board[2][0] == 'O' && board[2][0] == board[2][1] && board[2][0] == board[2][2])
        return state = O_WON;
    if (board[2][0] == 'O' && board[2][0] == board[1][1] && board[2][0] == board[0][2])
        return state = O_WON;

    // This loop counts the number of taken spots.
    // If there is even one empty spot, it returns UNFINISHED
    // and the game will progress.
    // If not, a counter will be added (mostly to give it something to do)
    int count = 0;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y] == 'X' || board[x][y] == 'O')
                count ++;
            else
                return state = UNFINISHED;
        }
    }
    return state = DRAW;
}
