/*********************************************************************
** Program Filename: Doodlebug.hpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Header file for Doodlebug class,
** a derived class of the Critter class.
*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug: public Critter {
private: 
	int cStarve;				// counts steps since the DB has eaten
	int count;					// step counter (for breeding purposes)
	int ID;
public:
	Doodlebug(int x, int y, int name);
	int getID();
	bool starve();
	void eat();
	Doodlebug *breed(int x, int y, int n);
};

#endif