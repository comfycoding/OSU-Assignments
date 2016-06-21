/*********************************************************************
** Program Filename: Creature.hpp
** Author: Darlene Zouras
** Date: 5/13/2016
** Description: Creature class header file
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cstring>
using std::string;

class Creature
{
protected:
	int armor;
	int strengthPoints;
	int wins;
public:

	/*********************************************************************
	 ** Function: Creature constructor
	 ** Description: Sets the variables for the armor and strength points
	 ** for any creature.
	 *********************************************************************/

	Creature(int a, int s)
	{
		armor = a;
		strengthPoints = s;
		wins = 0;
	}
	virtual bool attack(Creature* defender, std::string def) = 0;
	virtual int defend(int) = 0;

	/*********************************************************************
	 ** Function: getSP
	 ** Description: This function was added in order to make it so the
	 ** defend function would be suitable for Baba Yaga's skill, this
	 ** get function is only ever used to check whether a defender has
	 ** reached 0 strength points.
	 *********************************************************************/

	int getSP() { return strengthPoints; }

	/*********************************************************************
	 ** Function: getWins
	 ** Description: Returns the number of wins that a creature has.
	 *********************************************************************/

	int getWins() { return wins; }

	/*********************************************************************
	 ** Function: heal
	 ** Description: When a creature wins a match, their strength points
	 ** increase by 25%.
	 *********************************************************************/

	void heal() { strengthPoints += (strengthPoints * .25); }
};

#endif
