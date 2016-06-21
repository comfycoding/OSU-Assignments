/*********************************************************************
** Program Filename:
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Courtyard class header file.
*********************************************************************/

#ifndef COURTYARD_HPP
#define COURTYARD_HPP
#include "Spaces.hpp"
#include <cstring>
using std::string;

class Courtyard : public Spaces
{
private:
public:
    Courtyard(string n)
        : Spaces(n) { }
    void welcomeMessage();
    int menu();
    bool special();
    void message1();
    void message2();
    void message3();
};

#endif
