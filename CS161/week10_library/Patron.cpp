/*********************************************************************
** Author: Darlene Zouras
** Date: March 9, 2016
** Description: Project 10
** Patron.cpp
** Manages the patron class objects by setting and sending information
** regarding the patrons as well as the books that they interact with.
*********************************************************************/

#include "Patron.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Patron::Patron(string idn, string n)
{
    idNum = idn;
    name = n;
    fineAmount = 0.0;
}

string Patron::getIdNum()
{   return idNum;   }

string Patron::getName()
{   return name;    }

double Patron::getFineAmount()
{   return fineAmount;  }

vector<Book*> Patron::getCheckedOutBooks()
{   return checkedOutBooks; }

void Patron::addBook(Book* b)
{
    checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
    for (int num = 0; num < checkedOutBooks.size(); num++)
        if ( checkedOutBooks[num] == b )
            checkedOutBooks.erase(checkedOutBooks.begin() + num);
}

void Patron::amendFine(double amount)
{
    if ( -(amount) == fineAmount )
        fineAmount = 0.0;
    else
        fineAmount += amount;
}
