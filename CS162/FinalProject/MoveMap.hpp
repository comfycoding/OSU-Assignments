/*********************************************************************
** Program Filename: MoveMap.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: The header files of the MoveMap class.
*********************************************************************/

#ifndef MOVEMAP_HPP
#define MOVEMAP_HPP
#include "Spaces.hpp"
#include "FannyPack.hpp"
#include <cstring>
#include <iostream>
using std::string;

class MoveMap
{
private:
    FannyPack *pack;
    Spaces *lobby;
    Spaces *northEast;
    Spaces *northWest;
    Spaces *eastRoom;
    Spaces *westRoom;
    Spaces *courtyard;
    Spaces *greenhouse;

    /*********************************************************************
     ** MoveNode struct
     ** A linked list that holds together the spaces that make up the
     ** space explored in the program. Each node has four pointers.
     *********************************************************************/
    struct MoveNode
    {
        Spaces *space;
        MoveNode *north;
        MoveNode *south;
        MoveNode *east;
        MoveNode *west;
        string roomName;
        MoveNode(Spaces *sp, string n, MoveNode *no = NULL, MoveNode *so = NULL, MoveNode *ea = NULL, MoveNode *we = NULL)
        {
            space = sp;
            roomName = n;
            north = no;
            south = so;
            east = ea;
            west = we;
        }
    };
    MoveNode *currentNode;
    MoveNode *exitNode;
    int count;
public:
    MoveMap();
    void bringPack();
        // The currentSpace function returns the space pointer held in the current node.
    Spaces* currentSpace() { return currentNode->space; };
    void newRoom();
    void moveLobby();
    void moveCourtyard();
    void moveGreenhouse();
    void moveCorners();
    void moveSides();
};

#endif
