#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
private:
    int numMoves;           //Move counter, initialized to 0
    int xCoord;             //Current X coordinate
    int yCoord;             //Current Y coordinate
    class Path;

public:
    Critter();         
    void setStartX(int x);
    void setStartY(int y);
    void move();

    int getX();
    int getY();
    int getMoves();
};

#endif
