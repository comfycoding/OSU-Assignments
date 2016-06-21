/*********************************************************************
** Program Filename: Greenhouse.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Function information for the Greenhouse class.
*********************************************************************/

#include "Greenhouse.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Greenhouse::welcomeMessage()
{
    cout << "\nThe door of the greenhouse gently glides open now that the key is unlocked." << endl;
    cout << "The smokey glass prevents you from seeing clearly outside, but since the time ";
    cout << "you entered the Code Keeper's home it has become quite dark." << endl;
    cout << "You have a feeling that the exit must be close, ";
    cout << "as there is a single door on the opposite wall..." << endl;
    cout << "You'll just need to get past all of the giant plants and ferns in the dark first." << endl;
    cout << "Something is glowing in a corner of the room." << endl;
}

int Greenhouse::menu()
{
    int pick;
    cout << "\n\t1) Go out through the door that you came through." << endl;
    cout << "\t2) Attempt to go through the door on the South wall." << endl;
    cout << "\t3) Examine the faint light." << endl;
    cout << "Enter a number from the list: " <<endl;
    cin >> pick;

    if (pick == 3)
        if (!special())
            return menu();

    return pick;
}

bool Greenhouse::special()
{
    cout << "\nYou move carefully through the plants towards the faint light." << endl;
    cout << "You pull back one huge palm leaf to reveal a patio chair and side table." << endl;
    cout << "The side table has a small lamp on it, which is lit." << endl;
    cout << "A notebook is open on the table, it has something written inside." << endl;

    int specPick;
    cout << "\n\t1) Take a look at what is written in the notebook." << endl;
    cout << "\t2) Return to the menu." << endl;
    cin >> specPick;

    if (specPick == 1)
    {
        cout << "You take a look. It is a list of ASCII codes." << endl;
        cout << "You figure it's safe to tear the sheet out, so you do." << endl;
        cout << "(You have learned about ASCII, a new door has been unlocked.)" << endl;
        return true;
    }
    else if (specPick == 2)
        return false;
    else
    {
        cout << "\nThat is not one of the options." << endl;
        cin.clear();
        cin.ignore();
        return special();
    }
}

void Greenhouse::message1()
{
    cout << "\nYou reach for the metal handle of the greehnhouse door." << endl;
    cout << "Although it jiggles slightly you can tell that it is definitely locked." << endl;
    cout << "Another screen is mounted on the wall to the right of the handle." << endl;
    cout << "\tYou are so close yet so far!" << endl;
    cout << "\tThere's just one more code to crack: " << endl;
    cout << "\tUse ASCII to write the word 'key': " << endl;
}
