/*********************************************************************
** Program Filename: Ant.hpp
** Author: Darlene Zouras
** Date: 4/29/2016
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
    int getID();
    Ant *breed(int x, int y, int n);
};

#endif