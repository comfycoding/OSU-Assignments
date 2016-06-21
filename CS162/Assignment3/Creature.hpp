/*********************************************************************
** Program Filename: Creature.hpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Creature class header file
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;

class Creature
{
protected:
	int armor;
	int strengthPoints;
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
};

#endif