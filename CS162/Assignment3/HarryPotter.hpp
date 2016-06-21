/*********************************************************************
** Program Filename: HarryPotter.hpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Harry Potter class headers
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;
using std::endl;

class HarryPotter : public Creature
{
	private:
		bool Hogwarts;
	public:
	HarryPotter(int a, int s)
		: Creature(a, s) {
		}
	virtual bool attack(Creature* defender, std::string def);
	virtual int defend(int att);
};

#endif