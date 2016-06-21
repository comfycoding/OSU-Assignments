/*********************************************************************
** Program Filename: Path.cpp
** Author: Darlene Zouras
** Date: 4/9/2016
** Description: Path class header file
** Holds variables and function headers for the Path class.
*********************************************************************/

#ifndef PATH_HPP
#define PATH_HPP
#include "Critter.hpp"

class Critter;

class Path {
private:
    int x;
    int y;
    int numMoves;
    char empty;
    char crit;
    Critter* **grid;
    int numCritters;
    int critX;
    int critY;

public:
    Path(int a, int b);
    void setCritters(int crits);
    void findCritters();
    void run(int numMoves);
    void gridSet(Critter* **&grid);
    void gridDisplay();
    void remove(); 
};

#endif
