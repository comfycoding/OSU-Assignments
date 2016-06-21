/*********************************************************************
** Program Filename: Critter.hpp
** Author: Darlene Zouras
** Date: 4/9/2016
** Description: Critter class header file.
** Holds and manipulates the information for each critter object
** created by the Grid class.
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
private:
    int xCoord;             //Current X coordinate
    int yCoord;             //Current Y coordinate
    int direction;
    int moveCount;
    int critName;
    class Path;

public:
    Critter(int x, int y, int name);         
    void setX(int x);
    void setY(int y);
    void setName(int name);
    void move();
    int getMove();
    int getName();
    int getX();
    int getY();
};

#endif
