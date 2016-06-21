/*********************************************************************
** Program Filename: FannyPack.hpp
** Author: Darlene Zouras
** Date: 5/30/2016
** Description: Header file of the FannyPack class.
** This class is used to indicate whether or not a user holds the
** information about certain codes and ciphers which act as keys
** to navigate around the space.
*********************************************************************/

#ifndef FANNYPACK_HPP
#define FANNYPACK_HPP
#include <string>
using std::string;

class FannyPack
{
private:
    // The bool switches to determine locked doors
    bool caesarCipher;
    bool binaryCode;
    bool transpositionCipher;
    bool rot1Cipher;
    bool atbashCipher;
    bool lobbyLock;
    bool ASCII;
public:
    FannyPack();

    /*********************************************************************
     ** Function: get(Cipher name)
     ** Description: Returns a boolean value. It is false if the user has
     ** not activated that lock or obtained certain items / information.
     *********************************************************************/

     /*********************************************************************
      ** Function: flip(Cipher name)
      ** Description: It sets the boolean value for particular values to true
      ** to indicate that the user has learned about certain codes or ciphers
      ** , which manifests in the game as carrying physical copies of the
      ** code information. 
      *********************************************************************/

    bool getCaesarCipher() { return caesarCipher; } // check the lock to the courtyard
    void flipCaesar() { caesarCipher = true; }

    bool getBinary() { return binaryCode; } // check the locks to the greenhouse
    void flipBinary() { binaryCode = true; }

    bool getTranspositionCipher() { return transpositionCipher; } // check the locks to the west room
    void flipTransposition() { transpositionCipher = true; }

    bool getRot1() { return rot1Cipher; } // check the locks to the east room
    void flipRot1() { rot1Cipher = true; }

    bool getAtbash() { return atbashCipher; } // check the locks back into the lobby
    void flipAtbash() { atbashCipher = true;}

    bool backtoLobby() { return lobbyLock; } // unlock the door from inside the Corner rooms
    void flipLobby() { lobbyLock = true; }

    bool getASCII() { return ASCII; }
    void flipASCII() { ASCII = true; }
};

#endif
