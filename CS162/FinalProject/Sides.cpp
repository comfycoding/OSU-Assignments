/*********************************************************************
** Program Filename: Sides.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Function information for the Sides class.
*********************************************************************/

#include "Sides.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Sides::welcomeMessage()
{
    if (wRoom == 1)
        cout << "\nYou walk into the East wing of the building." << endl;
    else
        cout << "\nYou walk into the West wing of the building." << endl;
    cout << "Along the South wall there is a huge window, and you can see out of it." << endl;
    cout << "Across from that window is a door on the North wall." << endl;
    cout << "There are big bookshelves lining the single wall without windows or doors." << endl;
    cout << "On that wall there is also a fireplace, which has photos perched on the mantle." << endl;
    cout << "You can also leave the room back into the courtyard." << endl;
}

int Sides::menu()
{
    int pick;

    cout << "\n\t1) Attempt to go through the door on the North wall." << endl;
    // for proper display, check which of the siderooms we are in
    if (wRoom == 1)
        cout << "\t2) Attempt to go through the door on the West wall." << endl;
    else
        cout << "\t2) Attempt to go through the door on the East wall." << endl;
    cout << "\t3) Look out the big window on the South wall." << endl;
    cout << "\t4) Explore the space around the fireplace mantle." << endl;
    cout << "Enter a number from the list:" << endl;

    cin >> pick;

    if (pick == 4)
        if (!special())
            return menu();

    return pick;
}

// Used by the MoveMap class for the side and corner rooms to determine which direction
// a movement needs to be made.
// It is used within the class objects to specialize text.
void Sides::whichRoom(int num)
{
    wRoom = num;
    // if whichRoom is 1, it is the East room.
    // if whichRoom is 2, it is the West room.
}

bool Sides::special()
{
    cout << "\nYou move closer to the fireplace." << endl;
    cout << "The room smells faintly of smoke and there is heat from inside the fireplace." << endl;
    cout << "Perhaps someone else was here recently burning a fire." << endl;
    cout << "What would you like to do?" << endl;

    int specPick;
    cout << "\n\t1) Take a closer look at the painted portrait above the fireplace." << endl;
    cout << "\t2) Examine the old photographs on the mantle." << endl;
    cout << "\t3) Look at some of the books on the bookshelves." << endl;
    cout << "\t4) Return to the menu." << endl;
    cin >> specPick;

    if (specPick == 1)
    {
        cout << "\nThe portrait hanging on the wall shows a man and woman." << endl;
        cout << "They are dressed in contemporary clothes, but quite fancy." << endl;
        cout << "This must have been painted quite recently!" << endl;
        cout << "These must be the owners of this puzzle house." << endl;
        return false;
    }
    else if (specPick == 2)
    {
        cout << "\nYou take a closer look at some of the photos perched on mantle." << endl;
        cout << "By their looks, they must be old family photos. They have faded with age." << endl;
        cout << "There is a folded up piece of paper, you can read the word 'Atbash'." << endl;
        cout << "You pick it up and unfold it. It is a key to the Atbash cipher." << endl;
        cout << "You fold it up and put it into your fanny pack." << endl;
        cout << "(A new door has been unlocked.)" << endl;
        return true;
    }
    else if (specPick == 3)
    {
        cout << "\nThere are way too many books in the library to look through them all." << endl;
        cout << "A small sampling of some of the titles gives a glimpse of the homeowner's interests." << endl;
        cout << "Most of the books refer to codes, keys, ciphers, and cryptography." << endl;
        cout << "There are also some technical books about computers and math as well." << endl;
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

void Sides::message1()
{
    cout << "\nYou reach for the doorknob, but aren't surprised when it holds fast." << endl;
    cout << "You look over to the screen on the wall, and you read:" << endl;
    cout << "\tThe Atbash cipher is a monoalphabetic encryption cipher." << endl;
    cout << "\tUse it to type the word 'key'." << endl;
}
