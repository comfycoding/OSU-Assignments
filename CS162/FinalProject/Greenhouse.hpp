/*********************************************************************
** Program Filename: Greenhouse.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Header file for the Greenhouse class.
*********************************************************************/

#ifndef GREENHOUSE_HPP
#define GREENHOUSE_HPP
#include "Spaces.hpp"
#include <cstring>
using std::string;

class Greenhouse : public Spaces
{
private:
public:
    Greenhouse(string n)
        : Spaces(n) { }
    void welcomeMessage();
    int menu();
    bool special();
    void message1();
};

#endif
