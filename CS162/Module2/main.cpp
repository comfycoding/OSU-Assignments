/*********************************************************************
** Program Filename: main.cpp
** Author: Darlene Zouras
** Date: 5/11/2016
** Description: Main file of the Module 2 Assignment
*********************************************************************/

#include <iostream>
#include <cstring>
#include "Menu.cpp"
#include "Stack.hpp"
#include "Queue.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;

int menu();
void accessStack();
void accessQueue();

/*********************************************************************
 ** Function: main
 ** Description: Requests input, either 1 or 2, from the user, and
 ** depending on the number received will either run the Stack program
 ** or the Queue program.
 *********************************************************************/

int main()
{
    int pick = menu();

    while (pick != 3)
    {
        if (pick == 1)
            accessStack();
        else if (pick == 2)
            accessQueue();
        else
            cout << "Sorry, that is not one of the options. Try again!" << endl;

        pick = menu();
    }

    return 0;
}

/*********************************************************************
 ** Function: menu
 ** Description: Displays the options to the user and also receives the
 ** input and returns it to the main function.
 *********************************************************************/
 
int menu()
{
    cout << "\nEnter 1 to work with a Stack." << endl;
    cout << "Enter 2 to work with a Queue." << endl;
    cout << "Enter 3 to end the program." << endl;
    int num = getOne();
    return num;
}

/*********************************************************************
 ** Function: accessStack
 ** Description: This function requests input from the user, and then
 ** adds each character of that input into the Stack list. It then
 ** calls the Stack's remove function, which returns the characters
 ** from the first node to the last- which appears as the characters
 ** in reverse.
 *********************************************************************/

void accessStack()
{
    cin.clear();
    cin.ignore();
    StackList stack;
    string str;
    cout << "You have selected to work with a Stack!" << endl;
    cout << "Enter a series of characters, followed by ENTER." << endl;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        stack.add(ch);
    }

    cout << "The characters have been entered into the stack." << endl;
    cout << "From the last character to the first, this is what you entered: " << endl;
    for (int i = 0; i < str.size(); i++)
        cout << stack.remove();
    cout << endl;
}

/*********************************************************************
 ** Function: accessQueue
 ** Description: This function requests input from the user, and then
 ** adds each character of that input into the Queue list. It then calls
 ** the Queue's remove function, which returns the characters from the
 ** first node to the last, which appears as the characters in the
 ** same order as they were entered.
 *********************************************************************/

void accessQueue()
{
    cin.clear();
    cin.ignore();
    QueueList queue;
    string str;
    cout << "You have selected to work with a Queue!" << endl;
    cout << "Enter a series of characters, followed by ENTER." << endl;
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        queue.add(ch);
    }

    cout << "The characters have been entered into the queue." << endl;
    cout << "From the first character to the last, this is what you entered: " << endl;
    for (int i = 0; i < str.size(); i++)
        cout << queue.remove();
    cout << endl;
}
