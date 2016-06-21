/*********************************************************************
** Program Filename: BabaYaga.cpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: The Baba Yaga creature class functions
*********************************************************************/

#include "BabaYaga.hpp"
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
 ** Baba Yaga has the Soul ability, which absorbs the damage that she
 ** inflicts on her enemies to increase her own strength points.
 *********************************************************************/

bool BabaYaga::attack(Creature* defender, string def)
{
	int a = 0;

	for (int i = 0; i < 2; i++) {
		a += ((rand() % 6) + 1);
	}

	cout << "\tBaba Yaga does " << a << " hits of damage." << endl;
	
	int dmg = defender->defend(a);
	
	// Soul ability
	if (dmg != 0)
	{
		strengthPoints += dmg;
		cout << "\tBaba Yaga uses Soul ability, her Strength Points are now " << strengthPoints << "." << endl;
	}

	if (defender->getSP() <= 0) 
	{
		cout << "\t" << def << " is at 0 Strength Points and has been defeated." << endl;
		return false;
	}	
	else 
	{
		cout << "\t" << def << " is at " << defender->getSP() << " Strength Points." << endl;
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

int BabaYaga::defend(int att)
{
	int def = ((rand() % 10) + 1);
	
	int total = att - def - armor;
	if (total < 0)
		total = 0;

	cout << "\tBaba Yaga defends against " << (def + armor) << " hits.\n\tReceives " << total << " damage." << endl;
	
	if (total == 0)
		this->strengthPoints -= 0;
	else
		this->strengthPoints -= total;

	return total;
}