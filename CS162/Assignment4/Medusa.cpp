/*********************************************************************
** Program Filename:
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Medusa creature class functions
*********************************************************************/

#include "Medusa.hpp"
#include <cstring>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

/*********************************************************************
 ** Function: attack()
 ** Description: Medusa's attack has the special ability Glare.
 ** If she rolls a 12 at random, it means that she instantly becomes
 ** the winner of her fight.
 ** The attack function receives a pointer to the defending creature and
 ** their name, and calls their defend function.
 ** The attack function returns true if the defender's strength points
 ** are above 0. It returns false when the defender is at 0 or below.
 *********************************************************************/

bool Medusa::attack(Creature *defender, string def)
{
	int a = 0;

	for (int i = 0; i < 2; i++) {
		a += ((rand() % 6) + 1);
	}

	// Glare ability
	if (a == 12)
	{
		cout << "\t" << def << " has looked in Medusa's eyes and turned to stone!" << endl;
		cout << "\t" << def << " has been defeated." << endl;
		wins++;
		heal();
		if (strengthPoints > 8)
			strengthPoints = 8;			// SP cannot be over original 8
		cout << "Medusa now has " << wins << " wins, and her SP is now at " << strengthPoints << "." << endl;
		return false;
	}

	// cout << "\tMedusa does " << a << " hits of damage." << endl;

	int dmg = defender->defend(a);

	// Determine the outcome
	if (defender->getSP() <= 0) {
		cout << "\t" << def << " is at 0 Strength Points and has been defeated." << endl;
		wins++;
		heal();
		cout << "Medusa now has " << wins << " wins, and her SP is now at " << strengthPoints << "." << endl;
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

int Medusa::defend(int att)
{
	int def = 0;		// defense counter
	def += ((rand() % 6) + 1);

	int total = att - def - armor;
	if (total < 0)
		total = 0;

	// cout << "\tMedusa defends against " << (def + armor) << " hits. \n\tReceives " << total << " damage." << endl;

	if (total < 0)
		strengthPoints -= 0;
	else
		strengthPoints -= total;

	return total;
}
