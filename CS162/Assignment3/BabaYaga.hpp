/*********************************************************************
** Program Filename: BabaYaga.hpp
** Author: Darlene Zouras
** Date: 5/6/2016
** Description: Baba Yaga class headers
*********************************************************************/

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP
#include <iostream>
#include <cstring>
#include "Creature.hpp"
using std::string;
using std::cout;
using std::endl;

class BabaYaga : public Creature
{
public:
	BabaYaga(int a, int s)
		: Creature(a, s) {
		}
	virtual bool attack(Creature* defender, std::string def);
	virtual int defend(int att);
};

#endif