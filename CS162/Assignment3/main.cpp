/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: The main file for Assignment 3
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "BabaYaga.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Menu.cpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

// function prototypes
int charOptions();
Creature* charPick(int);
string charNames(int);
void battleSim(string, Creature*, string, Creature*);

/*********************************************************************
 ** Function: main()
 ** Description: The main function first leads the user to select
 ** two creature types to do battle. It then launches the recursive
 ** function battleSim which will run through a battle until there is
 ** a winner and a loser.
 *********************************************************************/

int main()
{
	srand (time(NULL));		// random number seed

	Creature *c1;
	Creature *c2;
	string char1, char2;

	cout << "Pick the first creature: " << endl;
	int charOne = charOptions();
	c1 = charPick(charOne);
	char1 = charNames(charOne);
	cout << "Creature one is " << char1 << "." << endl;

	cout << "\nPick the second creature: " << endl;
	int charTwo = charOptions();
	c2 = charPick(charTwo);
	char2 = charNames(charTwo);
	cout << "Creature two is " << char2 << "." << endl;

	battleSim(char1, c1, char2, c2);

	return 0;
}

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
	if (c == 1) {
		cout << "Medusa starts with 3 Armor and 8 Strength Points." << endl;
		cout << "She rolls two D6s for attack and one D6 for defense." << endl; 
		return new Medusa(3, 8);
	}
	if (c == 2) {
		cout << "Barbarian starts with 0 Armor and 12 Strength Points." << endl;
		cout << "He rolls two D6s for attack and two D6s for defense." << endl; 
		return new Barbarian(0, 12);
	}
	if (c == 3) {
	 	cout << "Baba Yaga starts with 3 Armor and 12 Strength Points." << endl;
		cout << "She rolls two D6s for attack and one D10 for defense." << endl; 
	 	return new BabaYaga(3, 12);
	}
	if (c == 4) {
		cout << "Blue Men starts with 3 Armor and 12 Strength Points." << endl;
		cout << "They roll two D10s for attack and three D6s for defense." << endl; 
		return new BlueMen(3, 12);
	}
	if (c == 5) {
		cout << "Harry Potter starts with 0 Armor and 10 Strength Points." << endl;
		cout << "He rolls two D6s for attack and two D6s for defense." << endl; 
		return new HarryPotter(0, 10);
	}

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
 ** Description: A recursive function that receives the name of the 
 ** attacker, defender, and their pointers. It runs one round of the 
 ** battle simulation. If the attack function returns true, then it means
 ** that there is not yet a winner, and so the attacker and defender are
 ** reversed. When the attack function returns false, it means that
 ** the attacking creature has won the fight.
 *********************************************************************/

void battleSim(string attacker, Creature *att, string defender, Creature *def)
{
	cout << "\n" << attacker << " attacks: " << endl;

	if (att->attack(def, defender) == true)
		battleSim(defender, def, attacker, att);
	else
		cout << "\n" << attacker << " is the victor!" << endl << endl;
}