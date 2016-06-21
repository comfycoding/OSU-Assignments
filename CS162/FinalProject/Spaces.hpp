/*********************************************************************
** Program Filename: Spaces.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: The header and function files of the abstract
** Spaces class.
** !!! The pure virtual functions used in derived classes are explained here !!!
*********************************************************************/

#ifndef SPACES_HPP
#define SPACES_HPP
#include <iostream>
#include <cstring>
using std::string;

class Spaces
{
protected:
    string name;

public:
    Spaces(string n) { n = name; }

    /*********************************************************************
     ** Function: welcomeMessage
     ** Description: This pure virtual function is called each time a
     ** room is entered intitially. It prints text to describe the space
     ** to the user.
     *********************************************************************/
    virtual void welcomeMessage() = 0;

    /*********************************************************************
     ** Function: menu
     ** Description: This pure virtual function is called by the move functions
     ** inside the MoveMap class. It displays the options available to the
     ** user, and also receives input and returns it to the function from
     ** where it is called.
     *********************************************************************/
    virtual int menu() = 0;

    /*********************************************************************
     ** Function: special
     ** Description: This pure virtual function is also unique to each
     ** space child class. It is in these functions where most of the
     ** exploring happens.
     ** They return a boolean to let the function that calls them know
     ** that the a certain activity has been completed.
     *********************************************************************/
    virtual bool special() = 0;

    // The getName function returns the name of the space.
    string getName() { return name; }

    // The whichRoom function is used by the side and corner rooms, so that
    // directional movement can be accurately made.
    virtual void whichRoom(int) { };

    /*********************************************************************
     ** Function: message1, 2, 3
     ** Description: Theses functions serve as space savers for the MoveMap
     ** class, and only hold printed text significant to the space and
     ** situation. These are not pure virtual functions because not all
     ** of the derived classes necessarily have 3 message functions.
     *********************************************************************/
    virtual void message1() { };
    virtual void message2() { };
    virtual void message3() { };
    // virtual void special() = 0;
};

#endif
