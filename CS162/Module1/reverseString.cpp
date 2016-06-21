/*********************************************************************
** Program Filename: reverseString.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Completes the second task of the Module 1 assignment.
** Receives any string from the user, then prints it in reverse through
** a recursive function.
*********************************************************************/

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::string;

/*********************************************************************
 ** Function: reverseString
 ** Description: The recursive function. It reverses the string by
 ** printing each character of the string starting from the last until
 ** it reaches the base case, which is the first letter.
 *********************************************************************/

void reverseString(string str, int length) {
    if (length == 0)            // base case
        cout << str[0] << '\n';

    else {
        cout << str[length];
        reverseString(str, (length - 1));
    }
}

/*********************************************************************
 ** Function: reverseMain
 ** Description: Receives the string input from the user and calls
 ** the reverseString function by sending the string and its length-1.
 *********************************************************************/

void reverseMain() {
    cin.clear();
    cin.ignore();

    string s;

    cout << "\nPlease enter a sring to reverse: ";
    getline(cin, s);

    reverseString(s, (s.size() - 1) );
}
