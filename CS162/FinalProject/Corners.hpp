/*********************************************************************
** Program Filename: Corners.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Header file for the Corners class.
*********************************************************************/

#ifndef CORNERS_HPP
#define CORNERS_HPP
#include "Spaces.hpp"
#include <cstring>
using std::string;

class Corners : public Spaces
{
private:
    int wRoom;
public:
    Corners(string n)
        : Spaces(n) { wRoom = 0; }
    void welcomeMessage();
    int menu();
    void whichRoom(int num);
    bool special();
};

#endif
