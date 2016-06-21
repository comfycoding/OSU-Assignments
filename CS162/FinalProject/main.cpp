/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Main file for the 162 Spring 2016 Final Project.
*********************************************************************/

#include <iostream>
#include <string>
#include "MoveMap.hpp"
#include "Menu.cpp"
using std::cout;
using std::endl;
using std::string;

int pickupPack();

int main()
{
    // build the space
    MoveMap map;

    cout << "\nWelcome, player. This program will guide you through a Code Keeper's home," << endl;
    cout << "which is filled with several ciphers and codes waiting to be cracked." << endl;
    cout << "You will have limited opportunities to move around the spaces within," << endl;
    cout << "but we have faith in your abilities." << endl;

    // And provide a very brief example of how this program will work,
    // which is through numbered menus.
    cout << "\nBefore you go, don't forget to bring along your Fanny Pack! ";
    while ( pickupPack() != 1 )
        cout << "Seriously, you'll need it!" << endl;
    map.bringPack();

    // And then give an option to exit the program early, just in case.
    cout << "\n" << "Player, you have what you need!" << endl;
    cout << "You are now ready to travel through the Code Keeper's home." << endl;
    map.newRoom();

    return 0;
}

// pickupPack
// Used as an example of how the user will make menu selections.
// Also will initialize the fannyPack class object.
int pickupPack()
{
    cout << "It might be empty now, but I bet that it will be useful later!" << endl;
    cout << "\t1) Pick up the Fanny Pack." << endl;
    cout << "\t2) Leave it behind." << endl;
    return getOne();
}
