/*********************************************************************
** Program Filename: Path.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Path class header file
** Holds variables and function headers for the Path class.
*********************************************************************/

#ifndef PATH_HPP
#define PATH_HPP
#include "Ant.hpp"
#include "Doodlebug.hpp"

class Ant;
class Critter;
class Doodlebug;

class Path {
private:
    Critter* **grid;
    
    char empty, crit, ant, doodlebug;

    int x, y, numMoves;
    int numCritters, numA, numD;
    int critX, critY;
    int names;

public:
    Path(int a, int b);
    void setCritters(int Ants, int Doodlebugs);
    void findCritters();
    void run(int numMoves);
    void gridSet(Critter* **&grid);
    void gridDisplay();
    void checkBreed(int j, int k, int tempY, int tempX, int i);
    void remove();
};

#endif
