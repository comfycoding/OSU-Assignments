/*********************************************************************
** Program Filename: Corners.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Function information for the Corners class.
*********************************************************************/

#include "Corners.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Corners::welcomeMessage()
{
    if (wRoom == 1)
        cout << "\nYou enter into the North East room." << endl;
    else
        cout << "\nYou enter into the North West room." << endl;

    cout << "If you had to guess, this room must have served as a study." << endl;
    cout << "A desk sits in front of a window, opposite to a wall with yet another door." << endl;
    cout << "A laptop computer sits open on the desk." << endl;
    cout << "Tall bookshelves line the wall across from you." << endl;
}

int Corners::menu()
{
    int pick;
    if (wRoom == 1)
        cout << "\n\t1) Attempt to go through the door on the West" << endl;
    else
        cout << "\n\t1) Attempt to go through the door on the East" << endl;
    cout << "\t2) Attempt to go through the door on the South wall" << endl;
    cout << "\t3) Sit at the desk." << endl;
    cout << "Enter a number from the list: " << endl;
    cin >> pick;

    if (pick == 3)
        if (!special())
            return menu();

    return pick;
}

void Corners::whichRoom(int num)
{
    wRoom = num;
    // if whichRoom is 1, it is the NorhtEast room.
    // if it is 2, it is the NorthWest room.
}

bool Corners::special()
{
    cout << "\nYou move to the desk, thinking that you'll only sit down for a moment." << endl;
    cout << "You have been standing and moving around the grounds for a while, after all." << endl;
    cout << "There are a few interesting things on this desk that catch your eye." << endl;

    int specPick;
    cout << "\n\t1) Flip through the open notepad." << endl;
    cout << "\t2) Take a closer look at the laptop screen." << endl;
    cout << "\t3) Open the drawer." << endl;
    cout << "\t4) Get up and return to the menu." << endl;
    cout << "Enter a number from the list: " << endl;
    cin >> specPick;

    if (specPick == 1)
    {
        cout << "\nYou flip through a few leaves of the open notepad." << endl;
        cout << "You're a little disappointed to find that it actually is completely blank." << endl;
        return false;
    }
    else if (specPick == 2)
    {
        cout << "\nYou can't help but catch a glimpse of the open laptop screen" << endl;
        cout << "It is open up to a browser window that has the title 'Binary Code'." << endl;
        cout << "It looks like a description of all of the letters in binary code." << endl;
        cout << "... You can guess what one of the locks will ask next, and reach for the notepad sitting on the desk." << endl;
        cout << "You jot down the binary for 'key' on the pad, tear off the page, and fold it into your fanny pack." << endl;
        cout << "(You have learned about Binary code, a new door has become unlocked.)" << endl;
        return true;
    }
    else if (specPick == 3)
    {
        cout << "\nYou take the handle of desk drawer. Maybe this is locked just like the doors?" << endl;
        cout << "That doesn't appear to be the case- it opens easily." << endl;
        cout << "You're impressed by how neatly organized it is inside." << endl;
        cout << "There are a few fountain pens, as well as some envelopes and stationary." << endl;
        cout << "Doesn't look like there could be anything helpful to you from inside here." << endl;
        return false;
    }
    else if (specPick == 4)
        return false;
    else
    {
        cout << "That is not one of the options." << endl;
        cin.clear();
        cin.ignore();
        return special();
    }
}
