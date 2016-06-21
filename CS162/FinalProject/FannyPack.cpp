/*********************************************************************
** Program Filename: FannyPack.cpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Function descriptions of the FannyPack class.
*********************************************************************/

#include "FannyPack.hpp"
#include <iostream>

/*********************************************************************
 ** Function: default constructor
 ** Description: Initializes each of the code indicators to false.
 *********************************************************************/

FannyPack::FannyPack()
{
    caesarCipher = false;
    binaryCode = false;
    transpositionCipher = false;
    rot1Cipher = false;
    atbashCipher = false;
    lobbyLock = false;
    ASCII = false;
}
