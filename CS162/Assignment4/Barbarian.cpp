/*********************************************************************
** Program Filename:
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Barbarian creature class functions
*********************************************************************/

#include "Barbarian.hpp"
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

bool Barbarian::attack(Creature *defender, string def)
{
	int a = 0;

	for (int i = 0; i < 2; i++) {
		a += ((rand() % 6) + 1);
	}

	// cout << "\tBarbarian does " << a << " hits of damage." << endl;

	int dmg = defender->defend(a);

	// Determine the outcome
	if (defender->getSP() <= 0) {
		cout << "\t" << def << " is at 0 Strength Points and has been defeated." << endl;
        wins++;
        heal();
        if (strengthPoints > 12)
        	strengthPoints = 12;			// SP can't be over original 12
        cout << "Barbarian now has " << wins << " wins, and his SP is now at " << strengthPoints << "." << endl;
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
 *********************************************************************/

int Barbarian::defend(int att)
{
	int def = 0;		// defense counter
	for (int i = 0; i < 2; i++) {
		def += ((rand() % 6) + 1);
	}

	int total = att - def;
	if (total < 0)
		total = 0;

	// cout << "\tBarbarian defends against " << def << " hits. \n\tReceives " << total << " damage." << endl;

	if (total < 0)
		strengthPoints -= 0;
	else
		strengthPoints -= total;

	return total;
}
