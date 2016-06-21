/*********************************************************************
** Program Filename: Ant.hpp
** Author: Darlene Zouras
** Date: 4/13/2016
** Description: Header file for Ant class,
** a derived class of the Critter class.
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant: public Critter {
private:
    int count;
public:
    Ant(int x, int y, int name);
    int getCount();
    Ant *breed(int x, int y, int n);
};

#endif