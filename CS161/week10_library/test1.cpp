// This is the test page for assignment 10

#include "Library.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Book book1("123", "Norwegian Wood", "Haruki Murakami");
    Book book2("124", "The Hobbit", "JRR Tolkien");
    Book book3("125", "Game of Thrones", "George RR Martin");

    Patron pat1("abc", "John");
    Patron pat2("abd", "Darlene");
    Patron pat3("abe", "Derek");

    Library lib;
    lib.addBook(&book1);
    lib.addBook(&book2);
    lib.addBook(&book3);
    lib.addPatron(&pat1);
    lib.addPatron(&pat2);
    lib.addPatron(&pat3);

    cout << "\n(John is checking out the book.)";
    cout << lib.checkOutBook("abc", "124");
    cout << "\n\n(Darlene is trying to check out the book.)";
    cout << lib.checkOutBook("abd", "124");
    cout << "\n\n(She can't, so she requests a hold.)";
    cout << lib.requestBook("abd", "124");

    for (int i=0; i < 25; i++)
        lib.incrementCurrentDate();
    cout << "\n(John kept his books too long and has a fine:)" << endl;
    double pat1Fine = pat1.getFineAmount();
    cout << "\n(His fine is $" << pat1Fine << ")";

    cout << "\n\n(John returns the book.)";
    cout << lib.returnBook("124");
    cout << "\n\n(Derek tries to check out the book, but it is on hold.)";
    cout << lib.checkOutBook("abe", "124");
    cout << "\n\n(Darlene is able to check out the book because she requested it.)";
    cout << lib.checkOutBook("abd", "124");
    cout << "\n(Finally, John is going to pay his $.40 fine)";
    cout << lib.payFine("abc", 0.4);
    cout << "\n(His fine is now $" << pat1.getFineAmount() << ")";


    return 0;
}
