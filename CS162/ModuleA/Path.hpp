#ifndef PATH_HPP
#define PATH_HPP
#include "Critter.hpp"

class Path {
private:
    int x;
    int y;
    char **grid;
    Critter critter;
    int critX;
    int critY;

public:
    Path(int a, int b);
    bool updateLocation();
    void gridSet(char **&grid);
    void gridDisplay();
    void squashed();
    void remove(); 
};

#endif
