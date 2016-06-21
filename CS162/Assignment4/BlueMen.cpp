/*********************************************************************
** Program Filename: BlueMen.cpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Blue Men creature class functions
*********************************************************************/

#include "BlueMen.hpp"
#include <cstring>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: attack()
 ** Description: The attack function receives a pointer to the
 ** defending creature and their name, and calls their defend function.
 ** The attack function returns true if the defender's strength points
 ** are above 0. It returns false when the defender is at 0 or below.
 *********************************************************************/

bool BlueMen::attack(Creature *defender, string def)
{
	int a = 0;

	for (int i = 0; i < 2; i++) {
		a += ((rand() % 10) + 1);
	}

	// cout << "\tBlue Men does " << a << " hits of damage." << endl;

	int dmg = defender->defend(a);

	// Determine the outcome
	if (defender->getSP() <= 0) {
		cout << "\t" << def << " is at 0 Strength Points and has been defeated." << endl;
        wins++;
        heal();
        if (strengthPoints > 12)
        	strengthPoints = 12;		// SP can't be greater than original 12
        cout << "Blue Men now has " << wins << " wins, and their SP is now at " << strengthPoints << "." << endl;
		return false;
	}
	else {
		// cout << "\t" << def << " is at " << defender->getSP() << " Strength Points." << endl;
		return true;
	}
}

/*********************************************************************
 ** Function: defend
 ** Description: In order to make Baba Yaga's Soul ability functional
 ** within the attack function, the defend function returns the amount
 ** of damage that the defender actually receives after armor and
 ** defending.
 ** The Blue Men have the Mob ability, which determines how many
 ** defense dice they will roll. It decreases for every 4 strength
 ** points they lose.
 *********************************************************************/

int BlueMen::defend(int att)
{
	int def = 0;		// defense counter

	// Mob ability
	if (strengthPoints < 4)
	{
		// cout << "\tBlue Men will roll only one D6 defence die." << endl;
		def += ((rand() % 6) + 1);
	}
	else if (strengthPoints < 8)
	{
		// cout << "\tBlue Men will roll two D6 defence dice." << endl;
		for (int i = 0; i < 2; i++) {
		def += ((rand() % 6) + 1);
		}
	}
	else
	{
		// cout << "\tBlue Men will roll three D6 defense dice." << endl;
		for (int i = 0; i < 3; i++) {
		def += ((rand() % 6) + 1);
		}
	}

	int total = att - def - armor;
	if (total < 0)
		total = 0;

	// cout << "\tBlue Men defends against " << (def + armor) << " hits. \n\tReceives " << total << " damage." << endl;

	if (total < 0)
		strengthPoints -= 0;
	else
		strengthPoints -= total;

	return total;
}
