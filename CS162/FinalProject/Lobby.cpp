/*********************************************************************
** Program Filename: Lobby.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Lobby class function information.
*********************************************************************/

#include "Lobby.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Lobby::welcomeMessage()
{
    cout << "\nYou step into the lobby of the home. You better make sure your fanny pack is fastened tight!" << endl;
    cout << "As you look around the room you can't help but notice the two sculpted busts on each side of the door on the opposite wall." << endl;
    cout << "There is a single door along each of the walls, and each has a touch screen stationed to the right of the doorknob on the wall." << endl;
}

int Lobby::menu()
{
    int pick;
    cout << endl;
    cout << "\t1) Back out- the door hasn't closed behind you yet!" << endl;
    cout << "\t2) Attempt to go through the door on the East wall" << endl;
    cout << "\t3) Attempt to go through the door on the West wall" << endl;
    cout << "\t4) Attempt to go through the door on the South wall" << endl;
    cout << "\t5) Take a closer look at the sculptures on either side of the South door." << endl;
    cout << "Enter a number from the list: " << endl;
    cin >> pick;

    if (pick == 5)
        if (!special())
            return menu();

    return pick;
}

bool Lobby::special()
{
    cout << "\nYou decided to take a closer look at the two sculptures." << endl;
    cout << "Beneath each sculpture on their pedestal there is a metal placard." << endl;
    cout << "The one of the left reads Julius Caesar, the one on the right reads Augustus Caesar." << endl;

    int specPick;
    cout << "Would you like to take a closer look?" << endl;
    cout << "\t1) Yes, examine the Julius Caesar bust." << endl;
    cout << "\t2) Yes, examine the Augustus Caesar bust." << endl;
    cout << "\t3) No, return to the menu." << endl;
    cout << "Enter a number from the list: " << endl;
    cin >> specPick;
    if (specPick == 1)
    {
        cout << "\nJulius Caesar's bust has a little rolled up scroll behind the ear." << endl;
        cout << "You take it. The top reads 'Caesar Cipher'." << endl;
        cout << "Beneat that, there is a circular decoder." << endl;
        cout << "You roll the piece of paper back up and put it in your fanny pack." << endl;
        cout << "(You have learned about the Caesar Cipher, a new door can be opened.)" << endl;
        return true;
    }
    else if (specPick == 2)
    {
        cout << "\nAugustus Caesar's bust seems to be nothing more than an average statue." << endl;
        return false;
    }
    else if (specPick == 3)
        return false;
    else
    {
        cout << "That is not one of the options." << endl;
        cin.clear();
        cin.ignore();
        return special();
    }
}

void Lobby::message1()
{
    cout << "\nYou take a look at the screen next to the door." << endl;
    cout << "You read the text on the screen: " << endl;
    cout << "\tThis is just the first puzzle, so it should be easy for you." << endl;
    cout << "\tA cipher shares a name with two great Roman emperors." << endl;
    cout << "\tUse it to write the word 'key'." << endl;
    cout << "A blinking cursor appears underneath, and there is a keyboard displayed on the touch screen." << endl;
    cout << "You refer to the Caesar Cipher decoder from your pack and type in 'xrl'." << endl;
    cout << "When you try to turn the doorknob it turns easily, and you progress through the door." << endl;
}

void Lobby::message2()
{
    cout << "\nDespite your attempts, the door seems to be locked." << endl;
    cout << "You take a look at the screen next to the door." << endl;
    cout << "You read the text on the screen: " << endl;
    cout << "\tThis is just the first puzzle, so it should be easy for you." << endl;
    cout << "\tA cipher shares a name with two great Roman emperors." << endl;
    cout << "\tUse it to write the word 'key'." << endl;
    cout << "A blinking cursor appears underneath, and there is a keyboard displayed on the touch screen." << endl;
    cout << "Maybe there is a clue somewhere in the room that will help to open the door." << endl;
}
