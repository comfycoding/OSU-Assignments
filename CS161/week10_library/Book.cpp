/*********************************************************************
** Author: Darlene Zouras
** Date: March 9, 2016
** Description: Project 10
** Book.cpp
** Manages the book class objects by setting and sending information
** regarding books to be held in the library.
*********************************************************************/

#include "Book.hpp"
#include <iostream>
using namespace std;

// The constructor sets the information for the book
// and also initializes the requestedBy and checkedOutBy variables to NULL.
// It also sets the location.
Book::Book(string idc, string t, string a)
{
    idCode = idc;
    title = t;
    author = a;
    requestedBy = NULL;
    checkedOutBy = NULL;
    setLocation(ON_SHELF);
}

string Book::getIdCode()
{   return idCode;  }

string Book::getTitle()
{   return title;   }

string Book::getAuthor()
{   return author;  }

void Book::setLocation(Locale where)
{   location = where;    }

Locale Book::getLocation()
{   return location;  }

void Book::setCheckedOutBy(Patron* patron)
{
    checkedOutBy = patron;
}

Patron* Book::getCheckedOutBy()
{   return checkedOutBy;    }

void Book::setRequestedBy(Patron* patron)
{   requestedBy = patron;   }

Patron* Book::getRequestedBy()
{    return requestedBy;    }

void Book::setDateCheckedOut(int checkout)
{   dateCheckedOut = checkout;  }

int Book::getDateCheckedOut()
{   return dateCheckedOut;  }
