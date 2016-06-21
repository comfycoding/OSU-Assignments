/*********************************************************************
** Program Filename: 
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Barbarian class headers
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;
using std::endl;

class Barbarian:public Creature
{
public:
	Barbarian(int a, int s)
		: Creature(a, s) {
		}
	virtual bool attack(Creature* defender, std::string def);
	virtual int defend(int att);
};

#endif