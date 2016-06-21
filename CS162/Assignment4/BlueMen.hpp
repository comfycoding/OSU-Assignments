/*********************************************************************
** Program Filename: BlueMen.hpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Blue Men class headers
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;
using std::endl;

class BlueMen : public Creature
{
private:
public:
	BlueMen(int a, int s)
		: Creature(a, s) {
		}
	virtual bool attack(Creature* defender, std::string def);
	virtual int defend(int att);
};

#endif