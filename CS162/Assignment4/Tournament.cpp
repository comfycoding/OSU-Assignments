#include <iostream>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::string;
using std::cin;

/*********************************************************************
 ** Function: charOptions
 ** Description: Displays the options for creatures, and it returns
 ** the number selection made by the user.
 *********************************************************************/

int charOptions()
{
	cout << "\t1: Medusa" << endl;
	cout << "\t2: Barbarian" << endl;
	cout << "\t3: Baba Yaga" << endl;
	cout << "\t4: Blue Men" << endl;
	cout << "\t5: Harry Potter" << endl;

	cout << "Enter a number: ";
	int pick = getOne();			// these lines
	if (pick > 5 || pick < 0)		// validate user input
	{
		cout << "That is not one of the options. Enter a number 1 - 5." << endl;
		return charOptions();
	}
	else
		return pick;
}

/*********************************************************************
 ** Function: charPick
 ** Description: Receives the number that the user has selected, and
 ** returns the selected creature object to the main function.
 *********************************************************************/

Creature* charPick(int c)
{
	if (c == 1)
		return new Medusa(3, 8);
	if (c == 2)
		return new Barbarian(0, 12);
	if (c == 3)
		return new BabaYaga(3, 12);
	if (c == 4)
		return new BlueMen(3, 12);
	if (c == 5)
		return new HarryPotter(0, 10);
	else
		return NULL;			// this will never be accessed,
								// the compiler wouldn't allow the possible
								// non-returning function
}

/*********************************************************************
 ** Function: charNames
 ** Description: Receives the number that the user has selected,
 ** returns a string holding the name of the particular character.
 *********************************************************************/

string charNames(int c)
{
	if (c == 1) {
		return "Medusa"; }
	if (c == 2) {
		return "Barbarian"; }
	if (c == 3) {
		return "Baba Yaga"; }
	if (c == 4) {
		return "Blue Men"; }
	if (c == 5) {
		return "Harry Potter"; }
	else
		return "NONE";			// this will never be accessed,
								// the compiler wouldn't allow the possible
								// non-returning function
}

/*********************************************************************
 ** Function: battleSim
 ** Description: A recursive function that receives the pointers to the
 ** attacker, defender, and the string types. This is a recursive variable
 ** that will eventually return the losing Creature pointer.
 *********************************************************************/

Creature* battleSim(Creature *att, string attacker, Creature *def, string defender)
{
	if ( att->attack(def, defender) )
		return battleSim(def, defender, att, attacker);
	else
		return def;
}

/*********************************************************************
 ** Function: playerSelect
 ** Description: This function runs through a picking option three times,
 ** so that each player may select three creatures for their lineup
 ** before the tournament. The creatures, their types, and their unique
 ** names are set as nodes in a CreatureList, which is returned to the
 ** main function.
 *********************************************************************/

CreatureList* playerSelect()
{
	Creature *c1, *c2, *c3;
	string char1, char2, char3;
	string char1n, char2n, char3n;
	CreatureList *playerList = new CreatureList;

	cout << "Pick your first creature: " << endl;
	int charOne = charOptions();
	c1 = charPick(charOne);
	char1 = charNames(charOne);
	clearInput();
	cout << "Name your " << char1 << ": " << endl;
	getline(cin, char1n);
	cout << "Creature one is a " << char1 << "." << endl;
	playerList->add(c1, char1, char1n);

	cout << "\nPick the second creature: " << endl;
	int charTwo = charOptions();
	c2 = charPick(charTwo);
	char2 = charNames(charTwo);
	clearInput();
	cout << "Name your " << char2 << ": " << endl;
	getline(cin, char2n);
	cout << "Creature two is a " << char2 << "." << endl;
	playerList->add(c2, char2, char2n);

	cout << "\nPick your third creature: " << "." << endl;
	int charThree = charOptions();
	c3 = charPick(charThree);
	char3 = charNames(charThree);
	clearInput();
	cout << "Name your " << char3 << ": " << endl;
	getline(cin, char3n);
	cout << "Creature three is a " << char3 << "." << endl;
	playerList->add(c3, char3, char3n);

	return playerList;
}

/*********************************************************************
 ** Function: tournament
 ** Description: Runs through a battlesim with the head of each list,
 ** and then determines which player's creature has lost. The correct
 ** creatures are either sent to the end of their active lists, or they
 ** are removed and held in the loser list.
 ** Returns a boolean value, and it will loop from the main function
 ** until it returns false. It will return false when one of the
 ** CreatureLists becomes empty.
 *********************************************************************/

bool tournament(CreatureList* p1, CreatureList* p2, LoserList *loser1, LoserList *loser2)
{
	cout << "\n---CURRENT LINEUPS---" << endl;
	cout << "These are Player One's active fighters: " << endl;
	p1->printList();
	cout << "\nThese are Player Two's active fighters: " << endl;
	p2->printList();

	cout << "\nPlayer One's ";
	p1->getName();
	cout << " attacks first, " << endl;
	cout << "Player Two's ";
	p2->getName();
	cout << " defends." << endl;

	Creature *lost = battleSim( p1->getCurrent(), p1->getType(), p2->getCurrent(), p2->getType() );

	// If Player One's creature has lost...
	if ( lost == p1->getCurrent() )
	{
		p1->getName();
		loser1->add(p1->getCurrent(), p1->getType(), p1->getID());
		p1->remove();
		cout << " has been moved to the loser list." << endl;
		p2->moveNext();
		cout << "The winner has been placed at the end of Player Two's list." << endl;
	}
	// Otherwise, Player Two's creature must have lost...
	else if ( lost == p2->getCurrent() )
	{
		p2->getName();
		loser2->add(p2->getCurrent(), p2->getType(), p2->getID());
		p2->remove();
		cout << " has been moved to the loser list." << endl;
		p1->moveNext();
		cout << "The winner has been placed at the end of Player One's list." << endl;
	}

	// Will return false when either of the active lists are empty.
	return ( p1->getHead() && p2->getHead() );
}

/*********************************************************************
 ** Function: tallyWins
 ** Description: returns the total wins for each player's creatures.
 ** It runs through the loser holdings to find this information.
 *********************************************************************/

int tallyWins(LoserList* loser)
{
	int wins = 0;
	for (int i = 0; i < 3; i++)		// each losing list has 3 creatures
	{
		wins += loser->getCurrent()->getWins();
		cout << "\n\t";
		loser->getName();
		cout << " had " << loser->getCurrent()->getWins() << " total wins.";
		loser->moveNext();
	}

	return wins;
}
