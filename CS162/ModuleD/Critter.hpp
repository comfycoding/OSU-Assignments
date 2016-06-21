/*********************************************************************
** Program Filename: Critter.hpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Critter class header file.
** Holds and manipulates the information for each critter object
** created by the Grid class.
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
protected:
    int xCoord;             //Current X coordinate
    int yCoord;             //Current Y coordinate
    int direction;
    int moveCount;
    int critName;
    class Path;

public:
    Critter();         
    void setX(int x);
    void setY(int y);
    void setName(int name);
    void move();
    int getMove();
    void setMove(int m);
    int getName();
    int getX();
    int getY();

    // Virtual functions
    virtual int getID();
    virtual Critter *breed(int x, int y, int n);

    /*********************************************************************
    ** Function: virtual eat
    ** Description: An empty function, as generic critters and Ants don't 
    ** eat.
    *********************************************************************/

    virtual void eat() { };

    /*********************************************************************
    ** Function: virtual starve
    ** Description: As default critters (and Ants) do not starve, they return
    ** false and therefore remain safely in their spot on the grid.
    *********************************************************************/

    virtual bool starve() { return false; };
};

#endif
