/*********************************************************************
** Author: Darlene Zouras
** Date: March 9, 2016
** Description: Project 10
** Library.cpp
** Manages the library class object(s). It interacts with book and
** patron objects to simulate some library situations, including
** checking out books, assessing late fees, reserving books, and
** and returning them.
*********************************************************************/

#include "Library.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Library::Library()
{   currentDate = 0;    }

void Library::addBook(Book* b)
{   holdings.push_back(b);  }

void Library::addPatron(Patron* p)
{   members.push_back(p);   }

Book* Library::getBook(string bID)
{
    int i = 0;
    while (i < holdings.size())
    {
        // compare the getIdCode for the book in the vector to bID.
        if (holdings[i]->getIdCode() == bID)
            return holdings[i];
        else
            i++;
    }

    // if the while loop completes without matching an ID
    return NULL;
}

Patron* Library::getPatron(string pID)
{
    int j = 0;
    while (j < members.size())
    {
        // compare the getIdNum for the patron in the vector to pID.
        if (members[j]->getIdNum() == pID)
            return members[j];
        else
            j++;
    }

    // if the while loop completes without matching an ID
    return NULL;
}

string Library::checkOutBook(string pID, string bID)
{
    if (getPatron(pID) == NULL)
        return "\nPatron not found.";
    if (getBook(bID) == NULL)
        return "\nBook not found.";

    if (getBook(bID)->getLocation() == CHECKED_OUT)
        return "\nBook already checked out.";

    // If the book is on hold, determine whether or not this person
    // checking out is the person that has requested it. If not,
    // it cannot be checked out by them.
    if (getBook(bID)->getLocation() == ON_HOLD_SHELF)
    {
        if (getPatron(pID) != getBook(bID)->getRequestedBy())
            return "\nBook on hold by other patron.";
        if (getPatron(pID) == getBook(bID)->getRequestedBy())
            getBook(bID)->setRequestedBy(NULL);
            getBook(bID)->setCheckedOutBy(getPatron(pID));
            getBook(bID)->setDateCheckedOut(currentDate);
            getBook(bID)->setLocation(CHECKED_OUT);
            return "\nCheck out successful.";
    }
    else
    {
        getBook(bID)->setCheckedOutBy(getPatron(pID));
        getBook(bID)->setDateCheckedOut(currentDate);
        getBook(bID)->setLocation(CHECKED_OUT);
        return "\nCheck out successful.";
    }
}

string Library::returnBook(string bID)
{
    if (getBook(bID) == NULL)
        return "\nBook not found.";
    if (getBook(bID)->getLocation() != CHECKED_OUT)
        return "\nBook already in library.";

    if (getBook(bID)->getRequestedBy() != NULL)
        getBook(bID)->setLocation(ON_HOLD_SHELF);
    else
        getBook(bID)->setLocation(ON_SHELF);
        getBook(bID)->setCheckedOutBy(NULL);
        return "\nReturn successful.";
}

string Library::requestBook(string pID, string bID)
{
    if (getBook(bID) == NULL)
        return "\nBook not found.";
    if (getPatron(pID) == NULL)
        return "\nPatron not found.";
    if (getBook(bID)->getRequestedBy() != NULL)
        return "\nBook already on hold.";           // if already reserved
    else
    {
        // Sets the location to the hold shelf
        // and sets the person that has requested the book.
        getBook(bID)->setRequestedBy(getPatron(pID));
        if (getBook(bID)->getLocation() == ON_SHELF)
            getBook(bID)->setLocation(ON_HOLD_SHELF);
        return "\nRequest successful.";
    }
}

string Library::payFine(string pID, double payment)
{
    if (getPatron(pID) == NULL)
        return "\nPatron not found.";
    getPatron(pID)->amendFine(-1*payment);
    return "\nPayment successful.";
}

void Library::incrementCurrentDate()
{
    currentDate ++;

    for (int k = 0; k < holdings.size(); k++)
    {
        if (holdings[k]->getLocation() == CHECKED_OUT)
        {
            int daysCheckedOut = currentDate - holdings[k]->getDateCheckedOut();
            if ( daysCheckedOut > 21)
                holdings[k]->getCheckedOutBy()->amendFine(.10);
        }
    }
}
