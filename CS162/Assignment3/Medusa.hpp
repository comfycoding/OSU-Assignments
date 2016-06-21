/*********************************************************************
** Program Filename: 
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Medusa class headers
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;
using std::endl;

class Medusa : public Creature
{
public:
	Medusa(int a, int s)
		: Creature(a, s) {
		}
	virtual bool attack(Creature* defender, std::string def);
	virtual int defend(int att);
};

#endif