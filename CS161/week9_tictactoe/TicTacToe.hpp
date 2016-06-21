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

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
private:
  Board gameBoard;
  int turnCount;
  char playerOne;
  char playerTwo;
  char player;
public:
  // Default constructor sets the turn count to 0
  TicTacToe()
  {
    turnCount = 0;
  }

  // The constructor receives a char variable
  // Sets which player is X and which is O
  TicTacToe(char player)
  {
    playerOne = player;
    if (playerOne == 'X' || playerOne == 'x')
      playerTwo = 'O';
    if (playerOne == 'O' || playerOne == 'o')
      playerTwo = 'X';
    cout << "Player one is " << playerOne << " and Player two is " << playerTwo << endl;
  }

  // If the turnCount counter is evenly divisible by two, it is the first
  // player's turn. If not, it is the second player's turn.
  char whoseTurn()
  {
    if (turnCount % 2 == 0)
      return playerOne;
    else
      return playerTwo;
  }

  // The play() function determines which player has the current turn,
  // displays the current game board, and then prompts the user to
  // enter the coordinates for their move. It then checks with the gameState()
  // function to determine whether the game has concluded. If neither X or O
  // has won and if the game has not ended in a draw, then the game continues
  // to loop.
  void play()
  {
    int xMove, yMove;
    player = whoseTurn();
    cout << "\n" << player << "'s turn.";
    gameBoard.print();

    cout << "Enter a coordinate: \n";
    cin >> xMove >> yMove;
    while ( gameBoard.makeMove(player, xMove, yMove) == false )
        {
            cout << "That space is occupied, try again: \n";
            cin >> xMove >> yMove;
        }
    
    turnCount++;

    if ( gameBoard.gameState() == UNFINISHED )
        play();
    else if ( gameBoard.gameState() == X_WON )
    {   gameBoard.print();
        cout << "\nX has won!\n";
        exit(0);    }
    else if ( gameBoard.gameState() == O_WON )
    {   gameBoard.print();
        cout << "\nO has won!\n";
        exit(0);    }
    else if ( gameBoard.gameState() == DRAW )
    {   gameBoard.print();
        cout << "\nIt's a draw.\n";
        exit(0);    }

  }

};

#endif
