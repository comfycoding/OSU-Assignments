/*********************************************************************
** Program Filename: Courtyard.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Function information for the Courtyard class.
*********************************************************************/

#include "Courtyard.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Courtyard::welcomeMessage()
{
    cout << "\nThe door leads you outside, and you realize that you have stepped into a courtyard." << endl;
    cout << "There is a stone walkway that leads to several interesting things: " << endl;
    cout << "A koi pond underneath a bonzai tree is at the far corner of the courtyard." << endl;
    cout << "There are also several greco-roman style statues scattered around the grounds " << endl;
    cout << "as well as a large stone sundial." << endl;
}

int Courtyard::menu()
{
    int pick;
    cout << "\n\t1) Attempt to go through the door on the North wall" << endl;
    cout << "\t2) Attempt to go through the door on the East wall" << endl;
    cout << "\t3) Attempt to go through the door on the West wall" << endl;
    cout << "\t4) Attempt to go through the door on the South wall" << endl;
    cout << "\t5) Investigate the koi pond" << endl;
    cout << "\t6) Investigate the sun dial" << endl;
    cout << "Enter a number from the list: " << endl;
    cin >> pick;

    if (pick == 5)
        if (!special())
            return menu();

    return pick;
}


bool Courtyard::special()
{
    cout << "\nYou have decided to investigate the koi pond." << endl;

    int specPick;
    cout << "\n\t1) Get a closer look at the fish in the pond." << endl;
    cout << "\t2) Feed the fish." << endl;
    cout << "\t3) Return to the menu." << endl;
    cin >> specPick;

    if (specPick == 1)
    {
        cout << "You find that there are only two koi swimming in this pond." << endl;
        cout << "One is has a black head and white tail, and the other has a white head and black tail." << endl;
        return false;
    }
    else if (specPick == 2)
    {
        cout << "There is a basket with small bags of koi food, and you pick one up to feed the koi." << endl;
        cout << "That's weird, amidst the feed is a small rolled up piece of paper." << endl;
        cout << "This has become familiar by now, and you unravel it." << endl;
        cout << "The top of the paper reads 'Transposition cipher'." << endl;
        cout << "Beneath is a description, and you find that all that is needed is to reverse a message." << endl;
        cout << "You roll the piece of paper back up and place it in your fanny pack." << endl;
        cout << "(You have learned about the Transcription cipher, a new door can be opened.)" << endl;
        return true;
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


void Courtyard::message1()
{
    cout << "The handle refuses to turn, so you investigate the panel to the right on the wall." << endl;
    cout << "\tThis door leads back inside." << endl;
    cout << "\tThere is a key to the ROT1 cipher in this courtyard." << endl;
    cout << "\tUse it to write 'key'." << endl;
    cout << "You pull out the ROT1 key from your pack." << endl;
    cout << "You use the touch pad to enter 'lfz'." << endl;
    cout << "You turn the handle again, the door easily opens." << endl;
}

void Courtyard::message2()
{
    cout << "The handle to the door does not budge, you read the panel to the right." << endl;
    cout << "\tThis door leads back inside." << endl;
    cout << "\tThere is a key to the Transposition in this courtyard." << endl;
    cout << "\tUse it to write 'key'." << endl;
}

void Courtyard::message3()
{
    cout << "The handle doesn't budge." << endl;
    cout << "There is yet again another panel stationed to the side of this door." << endl;
    cout << "\tThis door leads into the greenhouse." << endl;
    cout << "\tThere is a Binary cipher somewhere within the main house." << endl;
    cout << "\tUse it to write 'key' in 0s and 1s." << endl;
}
