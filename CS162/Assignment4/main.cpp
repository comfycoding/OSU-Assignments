/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 5/16/2016
** Description: The main file for Assignment 4
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "CreatureList.hpp"
#include "LoserList.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "BabaYaga.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Menu.cpp"
#include "Tournament.cpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
 ** Function: main()
 ** Description: The main function first leads the user to select
 ** two creature types to do battle. It then launches the recursive
 ** function battleSim which will run through a battle until there is
 ** a winner and a loser.
 *********************************************************************/

int main()
{
	srand (time(NULL));								// random number seed
	LoserList *loser1 = new LoserList;				// initialize list of
	LoserList *loser2 = new LoserList;				// defeated creatures
	int roundCount = 1;								// initialize round counter

	cout << "\nPlayer One, select your creatures!" << endl;
	CreatureList *playerOne = playerSelect();		// returns active list 1
	cout << "\nPlayer Two, select your creatures!" << endl;
	CreatureList *playerTwo = playerSelect();		// returns active list 2
	cout << "The creatures have been selected." << endl;

	// This do while will loop until one of the active lists has
	// become empty.
	do
	{
		cout << "\n--- Round " << roundCount << " ---" << endl;
		roundCount++;
	} while ( tournament(playerOne, playerTwo, loser1, loser2) );

	cout << "\nNow tallying the winners..." << endl;

	// BEFORE WINNING SCORES ARE TOTALED, even victorious creatures
	// need to be sent into the losing lists so that their win
	// counters can be read within the tallyWins function.
	while (playerOne->getHead())
	{
		loser1->add(playerOne->getCurrent(), playerOne->getType(), playerOne->getID());
		playerOne->remove();
	}
	while (playerTwo->getHead())
	{
		loser2->add(playerTwo->getCurrent(), playerTwo->getType(), playerTwo->getID());
		playerTwo->remove();
	}

	// Tally up the total wins for each team, determine who has more wins
	cout << "\nPlayer One's creatures, in order of their wins: " << endl;
	int p1wins = tallyWins(loser1);
	cout << "\nPlayer One's creatures have " << p1wins << " combined wins." << endl;

	cout << "\nPlayer Two's creatures, in order of their wins: " << endl;
	int p2wins = tallyWins(loser2);
	cout << "\nPlayer Two's creatures have " << p2wins << " combined wins." << endl;

	if (p1wins > p2wins)
		cout << "\nPlayer One has won the tournament!" << endl;
	else if (p2wins > p1wins)
		cout << "\nPlayer Two has won the tournament!" << endl;
	else
		cout << "Player One and Two have tied!" << endl;
		// This should not actually be a possible result!

	cout << "\nThese are the top three ranking creatures: " << endl;

	return 0;
}
