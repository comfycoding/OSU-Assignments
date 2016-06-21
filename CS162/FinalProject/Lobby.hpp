/*********************************************************************
** Program Filename: Lobby.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Lobby class header file.
*********************************************************************/

#ifndef LOBBY_HPP
#define LOBBY_HPP
#include "Spaces.hpp"
#include <cstring>
using std::string;

class Lobby : public Spaces
{
private:
public:
    Lobby(string n)
        : Spaces(n) { }
    void welcomeMessage();
    int menu();
    bool special();
    void message1();
    void message2();
};

#endif
