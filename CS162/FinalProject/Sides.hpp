/*********************************************************************
** Program Filename: Sides.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Sides class header file.
*********************************************************************/

#ifndef SIDES_HPP
#define SIDES_HPP
#include "Spaces.hpp"
#include <cstring>
using std::string;

class Sides : public Spaces
{
private:
    int wRoom;
public:
    Sides(string n)
        : Spaces(n) { wRoom = 0; }
    void welcomeMessage();
    int menu();
    void whichRoom(int num);
    bool special();
    void message1();
};

#endif
