/*********************************************************************
** Program Filename: MoveMap.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: The function list of the MoveMap class.
*********************************************************************/

#include "MoveMap.hpp"
#include "Lobby.hpp"
#include "Courtyard.hpp"
#include "Corners.hpp"
#include "Sides.hpp"
#include "Greenhouse.hpp"
#include "FannyPack.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: MoveMap constructor
 ** Description: This function initializes the count variable to 0, and
 ** also initializes each of the class objects. It also sets the first
 ** currentNode to the lobby and sets all of its pointers.
 *********************************************************************/
MoveMap::MoveMap()
{
    count = 0;      // Counts the number of times a space is changed.

    lobby = new Lobby("lobby");
    northEast = new Corners("Northeast room");
    northWest = new Corners("Northwest room");
    courtyard = new Courtyard("courtyard");
    eastRoom = new Sides("east room");
    westRoom = new Sides("west room");
    greenhouse = new Greenhouse("Greenhouse");

    // The lobby is created and set to the initial currentLocation pointer.
    currentNode = new MoveNode(lobby, "lobby");
    // Set the Lobby's node pointers
    currentNode->south = new MoveNode(courtyard, "courtyard", currentNode);
    currentNode->east = new MoveNode(northEast, "northeast room", NULL, NULL, NULL, currentNode);
    currentNode->west = new MoveNode(northWest, "northwest room", NULL, NULL, currentNode, NULL);
}

/*********************************************************************
 ** Function: bringPack
 ** Description: Initializes the FannyPack object, it is called early
 ** in the program mostly as an example of how a user would navigate
 ** and make selections from the menu.
 *********************************************************************/

void MoveMap::bringPack()
{
    pack = new FannyPack();
    cout << "\nYour fannypack is now fastened nice and tight around your waist." << endl;
}

/*********************************************************************
 ** Function: newRoom
 ** Description: The newRoom function refreshes each time the user moves
 ** into a new node in the list. Based on which node is set as the
 ** currentNode (determined by the room's name), it will navigate to the
 ** correct move function.
 *********************************************************************/

void MoveMap::newRoom()
{
    count ++;

    // print a bit of introductory text when you first enter.
    if (count == 1)
    {
        cout << "\nYou step into a dark room. Before you even have a chance to begin searching for a light switch, " << endl;
        cout << "a chandelier hanging from the cieiling is lit, which makes you start." << endl;
        cout << "\tHello, young friend!" << endl;
        cout << "You hear a voice and look around to find its owner, but cannot." << endl;
        cout << "\n\tI see that you have a fanny pack around your waist. That's good!" << endl;
        cout << "\tYou never know when you'll need to carry something with you. I bet it will be quite handy here." << endl;
        cout << "\tIn my home you will find several puzzles." << endl;
        cout << "\tYou see, I love codes and ciphers." << endl;
        cout << "\tThey will be helpful to know as you navigate the grounds." << endl;
        cout << "\tPlease don't hesitate to find the keys, I will only allow you to enter 5 rooms before you lose the challenge." << endl;
        cout << "\tGood luck, and have fun!" << endl;
        cout << "\nThe voice finishes its speech, and you are finally free to explore this room." << endl;
        cout << "(The goal of this game is to find enough ciphers and puzzles to be able to exit the space)" << endl;
    }
    // or quit the game if the user has not made it to the end in time.
    if (count == 10)
    {
        cout << "\nThe bodiless voice returns once you step through the door." << endl;
        cout << "\tWhat a shame, you had made it so far, too!" << endl;
        cout << "\tYou won't be making it out through the end like you had hoped." << endl;
        cout << "\tYou've lost the game this time, but we hope you try again." << endl;
        cout << "\nThe program will now close." << endl;
        exit(0);
    }

    // This indicator helps to establish which of the side rooms we are in.
    if (currentNode->space == northEast || currentNode->space == eastRoom)
        currentSpace()->whichRoom(1);
    else if (currentNode->space == northWest || currentNode->space == westRoom)
        currentSpace()->whichRoom(2);

    currentSpace()->welcomeMessage();
    cout << "\nYou are currently in the " << currentNode->roomName << "." << endl;

    if (currentNode->roomName == "lobby")
        moveLobby();
    else if (currentNode->roomName == "courtyard")
        moveCourtyard();
    else if (currentNode->roomName == "greenhouse")
        moveGreenhouse();
    else if (currentNode->roomName == "northeast room" || currentNode->roomName == "northwest room")
        moveCorners();
    else if (currentNode->roomName == "east room" || currentNode->roomName == "west room")
        moveSides();

    // These lines are called after whichever of the above functions completes its
    // actions. They confirm that the user has not moved onto a node that is set to
    // NULL. This shouldn't happen, but in case it does the program will respond
    // with an error and the program will close.
    if (currentNode)
        newRoom();
    else if (!currentNode)
    {
        cout << "You have somehow stepped outside of the space, so the program will now close.";
        exit(0);
    }
}

/*********************************************************************
 ** Function: moveLobby
 ** Description: Calls the lobby object Menu function, and based on
 ** user input will navigate their options using if/else statements.
 ** The user selection description is described in a comment with each
 ** if/else tag.
 *********************************************************************/

void MoveMap::moveLobby()
{
    int lobbyPick = currentSpace()->menu();

    if (lobbyPick == 1)    // exit the program through the front door
    {
        cout << "You have chosen to exit through the door you came through." << endl;
        cout << "The program will close, we hope that you try again next time!" << endl;
        exit(0);
    }
    else if (lobbyPick == 2)    // attempt to move to the NorthEast room
    {
        // check on this door's locks
        if (pack->backtoLobby())
        {
            cout << "The door had been unlocked from elsewhere, the door opens easily into the next room." << endl;
            delete currentNode->west;
            delete currentNode->south;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->east;
            currentNode->south = new MoveNode(eastRoom, "east room");
            currentNode->west = tempNode;
        }
        else
        {
            cout << "You reach for the handle and give it a push- it doesn't budge." << endl;
            cout << "Unlike the door along the South wall, this door does not have a touch screen besides it." << endl;
            cout << "Perhaps you have to open it from the other side..." << endl;
            moveLobby();
        }
    }
    else if (lobbyPick == 3)    // attempt to move to the NorthWest room
    {
        if (pack->backtoLobby())
        {
            cout << "The door had been unlocked from elsewhere, the door opens easily into the next room." << endl;
            delete currentNode->east;
            delete currentNode->south;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->west;
            currentNode->south = new MoveNode(westRoom, "west room");
            currentNode->east = tempNode;
        }
        else
        {
            cout << "You reach for the handle and give it a push- it doesn't budge." << endl;
            cout << "Unlike the door along the South wall, this door does not have a touch screen besides it." << endl;
            cout << "Perhaps you have to open it from the other side..." << endl;
            moveLobby();
        }
    }
    else if (lobbyPick == 4) // Attempt to move to the Courtyard
    {
        cout << "\nYou wiggle the handle of the door, fearing that it may be locked." << endl;
        if (pack->getCaesarCipher())
        {
            currentSpace()->message1();

            // reconfigure the current accessible space.
            delete currentNode->east;
            delete currentNode->west;
            MoveNode *tempNode = currentNode;
            currentNode = tempNode->south;
            currentNode->north = tempNode;
            currentNode->east = new MoveNode(eastRoom, "east room");
            currentNode->west = new MoveNode(westRoom, "west room");
            currentNode->south = new MoveNode(greenhouse, "greenhouse");
            cout << "You have successfully opened the door to the courtyard." << endl;
        }
        else
        {
            currentSpace()->message2();
            moveLobby();
        }
    }
    else if (lobbyPick == 5)
    {
        pack->flipCaesar();
        moveLobby();
    }
    else {
        cout << "\nThat was not one of the options, please try again." << endl;
        cin.clear(); cin.ignore();
        moveLobby();
    }
}

/*********************************************************************
 ** Function: moveCourtyard
 ** Description: Calls the Courtyard object menu function, and based
 ** on user input will navigate their options using if/else statements.
 *********************************************************************/

void MoveMap::moveCourtyard()
{
    int courtyardPick = currentSpace()->menu();

    if (courtyardPick == 1) // return to the lobby
    {
        cout << "\nYou decide to return to the Lobby." << endl;
        delete currentNode->south;
        delete currentNode->east;
        delete currentNode->west;
        MoveNode *tempNode = currentNode;
        currentNode = currentNode->north;
        currentNode->south = tempNode;
        currentNode->east = new MoveNode(northEast, "northeast room");
        currentNode->west = new MoveNode(northWest, "northwest room");
    }
    else if (courtyardPick == 2)    // attempt to move into the East room
    {
        cout << "\nYou attempt to turn the handle of the door along the East wall." << endl;
        if (pack->getRot1())
        {
            currentSpace()->message1();
            delete currentNode->west;
            delete currentNode->south;
            delete currentNode->north;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->east;
            currentNode->west = tempNode;
            currentNode->north = new MoveNode(northEast, "northeast room");
        }
        else
        {
            cout << "The handle refuses to turn, so you investigate the panel to the right on the wall." << endl;
            cout << "\tThis door leads back inside." << endl;
            cout << "\tThere is a key to the ROT1 cipher in this courtyard." << endl;
            cout << "\tUse it to write 'key'." << endl;
            cout << "The code to unlock this door must be somewhere nearby..." << endl;
            moveCourtyard();
        }
    }
    else if (courtyardPick == 3)    // attempt to move into the West room
    {
        cout << "\nYou attempt to open the door along the West wall." << endl;
        if (pack->getTranspositionCipher())
        {
            currentSpace()->message2();
            cout << "You retrieve the rolled paper from your pack and enter 'yek'." << endl;
            cout << "You turn the handle again, the door easily opens." << endl;
            delete currentNode->east;
            delete currentNode->south;
            delete currentNode->north;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->west;
            currentNode->east = tempNode;
            currentNode->north = new MoveNode(northWest, "northwest room");
        }
        else
        {
            currentSpace()->message2();
            cout << "The code to unlock this door must be somewhere nearby..." << endl;
            moveCourtyard();
        }
    }
    else if (courtyardPick == 4)    // atempt to move into the greenhouse
    {
        cout << "The greenhouse door is cold in your hands, but you grasp it firm and try." << endl;
        if (pack->getBinary())
        {
            currentSpace()->message3();
            cout << "You found the list of Binary codes inside the study." << endl;
            cout << "You pull it from your pack and enter '01001011 01100101 0111101'." << endl;
            cout << "You take the handle again and push open the door." << endl;
            delete currentNode->north;
            delete currentNode->west;
            delete currentNode->east;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->south;
            currentNode->north = tempNode;
        }
        else
        {
            currentSpace()->message3();
            cout << "The code must be found inside the house. Better find it and then come back." << endl;
            moveCourtyard();
        }
    }
    else if (courtyardPick == 5)
    {
        pack->flipTransposition();
        moveCourtyard();
    }
    else if (courtyardPick == 6)
    {
        if (pack->getRot1())
        {
            cout << "\nThe sundial only serves as a reminder that the clock is slowly ticking." << endl;
            cout << "There is nothing new to learn here." << endl;
            moveCourtyard();
        }
        else
        {
            cout << "\nYou have decided to investigate the sun dial." << endl;
            cout << "There are flowers and green leafy plants growing all around it." << endl;
            cout << "The stone slab has a triangular dial, which casts a shadow on the face." << endl;
            cout << "Interestingly, there are small holes carved into the face to mark each hour." << endl;
            cout << "Not surprisingly, there is a small piece of paper fit into one of the holes." << endl;
            cout << "You take it, unravel it, and read 'ROT1 cipher' at the top." << endl;
            cout << "The key explains that you rotate each character one forward." << endl;
            cout << "You roll it back up and put it in your fanny pack." << endl;
            cout << "(You have learned about the ROT1 cipher, a new door has opened.)" << endl;
            pack->flipRot1();
            moveCourtyard();
        }
    }
    else
    {
        cout << "\nThat was not one of the options, please try again." << endl;
        cin.clear(); cin.ignore();
        moveCourtyard();
    }
}

/*********************************************************************
 ** Function: moveGreenhouse
 ** Description: Calls the Greenhouse object menu function, collects user
 ** input and then navigates the options using if/else statements.
 *********************************************************************/

void MoveMap::moveGreenhouse()
{
    int greenhousePick = currentSpace()->menu();

    if (greenhousePick == 1)    // return to the courtyard
    {
        cout << "\nYou decide to return back through the door that you came through." << endl;
        MoveNode *tempNode = currentNode;
        currentNode = currentNode->north;
        currentNode->south = tempNode;
        currentNode->north = new MoveNode(lobby, "lobby");
        currentNode->east = new MoveNode(eastRoom, "east room");
        currentNode->west = new MoveNode(westRoom, "west room");
    }
    else if (greenhousePick == 2)   // exit through the door to the south
    {
        if (pack->getASCII())
        {
            currentSpace()->message1();
            cout << "You remove the ASCII code from your pack, and type into the program: " << endl;
            cout << "75 101 121" << endl;
            cout << "You grasp the handle of the door again, and this time it pushes open." << endl;
            cout << "\nYou have successfully made it off of the grounds, congratulations!" << endl;
            cout << "You moved through " << count << " rooms before you were able to successfully make it through." << endl;
            cout << "This game will now close." << endl;
            exit(0);
        }
        else
        {
            currentSpace()->message1();
            cout << "Beneath that there is a familiar blinking cursor above the keyboard." << endl;
            cout << "You don't know enough about this code yet, but the key must be here somewhere." << endl;
            moveGreenhouse();
        }
    }
    else if (greenhousePick == 3)
    {
        pack->flipASCII();
        moveGreenhouse();
    }
    else
    {
        cout << "\nThat was not one of the options, please try again." << endl;
        cin.clear(); cin.ignore();
        moveGreenhouse();
    }
}

/*********************************************************************
 ** Function: moveCorners
 ** Description: Calls the Corners object menu function, collects user
 ** input, and navigates the options using if/else statements.
 *********************************************************************/

void MoveMap::moveCorners()
{
    int cornerPick = currentSpace()->menu();

    if (cornerPick == 1) // Return to the lobby
    {
        if (!pack->backtoLobby())
        {
            cout << "Weird, there is no screen next to this door." << endl;
            cout << "You test the doorknob- it's locked." << endl;
            cout << "But it looks like there's just a simple lock on the door." << endl;
            cout << "You flip that lock." << endl;
            pack->flipLobby();
        }
        cout << "You push the door open and return again to the Lobby." << endl;
        // This move needs to be directed.
        if (currentNode->space == northEast)
        {
            delete currentNode->south;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->west;
            currentNode->east = tempNode;
            currentNode->west = new MoveNode(northWest, "northwest room");
            currentNode->south = new MoveNode(courtyard, "courtyard");
        }
        else
        {
            delete currentNode->south;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->east;
            currentNode->west = tempNode;
            currentNode->east = new MoveNode(northEast, "northeast room");
            currentNode->south = new MoveNode(courtyard, "courtyard");
        }
    }
    else if (cornerPick == 2) // move to one of the side rooms
    {
        cout << "The handle on the door turns and you are able to push it open." << endl;
        if (currentNode->space == northEast)
        {
            delete currentNode->west;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->south;
            currentNode->north = tempNode;
            currentNode->west = new MoveNode(courtyard, "courtyard");
        }
        else
        {
            delete currentNode->east;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->south;
            currentNode->north = tempNode;
            currentNode->east = new MoveNode(courtyard, "courtyard");
        }
    }
    else if (cornerPick == 3)
    {
        pack->flipBinary();
        moveCorners();
    }
    else
    {
        cout << "That was not one of the options, please try again." << endl;
        cin.clear(); cin.ignore();
        moveCorners();
    }
}

/*********************************************************************
 ** Function: moveSides
 ** Description: Calls the Sides object menu funciton, collects user
 ** input, then navigates the options using if/else statements.
 *********************************************************************/

void MoveMap::moveSides()
{
    int sidePick = currentSpace()->menu();

    if (sidePick == 1)  // attempt to move into the corner rooms.
    {
        if (pack->getAtbash())
        {
            currentSpace()->message1();
            cout << "You look around for the slip of paper in your fanny pack." << endl;
            cout << "You've learned about this cipher already, and you type in 'pvb'." << endl;
            cout << "You grasp the doorknob again, this time, it turns easily." << endl;
            // regardless of which room we are in, we should move to the correct corner room
            if (currentSpace() == eastRoom)
            {
                delete currentNode->west;
                MoveNode *tempNode = currentNode;
                currentNode = currentNode->north;
                currentNode->south = tempNode;
                currentNode->west = new MoveNode(lobby, "lobby");
            }
            else
            {
                delete currentNode->east;
                MoveNode *tempNode = currentNode;
                currentNode = currentNode->north;
                currentNode->south = tempNode;
                currentNode->east = new MoveNode(lobby, "lobby");
            }
        }
        else
        {
            currentSpace()->message1();
            cout << "You aren't surprised at all for the request." << endl;
            cout << "It seems that you still have to do a little more exploring." << endl;
            moveSides();
        }
    }
    else if (sidePick == 2) // go back to the courtyard
    {
        cout << "You decide that it's about time to return to the courtyard and explore a little more." << endl;
        // moving back to the courtyard will have to be directed.
        if (currentNode->space == eastRoom)
        {
            delete currentNode->north;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->west;
            currentNode->east = tempNode;
            currentNode->west = new MoveNode(westRoom, "west room");
            currentNode->north = new MoveNode(lobby, "lobby");
            currentNode->south = new MoveNode(greenhouse, "greenhouse");
        }
        else
        {
            delete currentNode->north;
            MoveNode *tempNode = currentNode;
            currentNode = currentNode->east;
            currentNode->west = tempNode;
            currentNode->east = new MoveNode(eastRoom, "east room");
            currentNode->north = new MoveNode(lobby, "lobby");
            currentNode->south = new MoveNode(greenhouse, "greenhouse");
        }
    }
    else if (sidePick == 3)
    {
        // This action serves as a simple way to determine how many more moves you have left.
        cout << "\nYou step up to the large window, which spans most of the wall." << endl;
        cout << "It's already getting dark out, you wonder how long you have already spent in this house." << endl;
        cout << "(You have moved through " << count << " rooms so far. Be mindful of the limit.)" << endl;
        moveSides();
    }
    else if (sidePick == 4)
    {
        pack->flipAtbash();
        moveSides();
    }
    else
    {
        cout << "That was not one of the options, please try again." << endl;
        cin.clear(); cin.ignore();
        moveSides();
    }
}
