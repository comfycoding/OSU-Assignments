/*********************************************************************
** Program Filename: List.cpp
** Author: Darlene Zouras
** Date: 4/21/2016
** Description: List class member functions
*********************************************************************/

#include "List.hpp"
#include "Menu.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
 ** Function: List constructor
 ** Description: A default constructor that runs every time an object
 ** is created. It sets significant counting variables and also creates
 ** the dynamic array at its initial size of 4 (set by the variable num).
 *********************************************************************/

List::List() {
	num = 4;							// The list should start with at least four spaces
	count = 0;							// Count is initialized to 0

	l = new Item*[num];					// This creates an array of pointers, 4 long

	for (int i = 0; i < num; i++) {		// Sets them all initially to NULL
		l[i] = NULL;
	}
}

/*********************************************************************
 ** Function: menu
 ** Description: This is the main navigation menu that calls and runs
 ** the other functions found in the List class. It runs by requesting
 ** a number from the user that corresponds to an option in the menu.
 ** It validates the input to prevent error through the getOne() function.
 *********************************************************************/

void List::menu() {

	cout << "\nPlease enter a number for the following actions." << endl;

	cout << "\t1. Display the List." << endl;
	cout << "\t2. Add an Item." << endl;
	cout << "\t3. Remove an Item." << endl;
	cout << "\t4. Exit the program." << endl;

	cout << "\nEnter a number: ";
	int pick = 0;
	pick = getOne();		// Prevent error by non-integer inputs

	if (pick == 1) {
		cout << "\nYou have chosen option 1." << endl;
		displayList();
	}
	else if (pick == 2) {
		cout << "\nYou have chosen option 2." << endl;
		addItem();
	}
	else if (pick == 3) {
		cout << "\nYou have chosen option 3." << endl;
		removeItem();
	}
	else if (pick == 4) {
		cout << "\nYou have chosen option 4." << endl;
		cout << "Now closing the program." << endl;
		cleanUp();
		exit(0);
	}
	else {		// simple verification of input
		cout << "Sorry, that is not one of the options." << endl;
		cin.clear();
		cin.ignore();
		//menu();
	}

	menu();
}

/*********************************************************************
 ** Function: displayList
 ** Description: Displays the contents of the list array.
 ** In the case that there are no items in the list, it says there are
 ** no items and returns to the menu.
 ** In a non-empty list array it cycles through and calls the printItem
 ** function of the pointer in that spot.
 *********************************************************************/

void List::displayList() {
		// Check whether the list is empty
	if (count == 0) {
		cout << "There are no items in the list." << endl;
		menu();
	}

	double total = 0.0;

	for (int i = 0; i < num; i++) {
		if (l[i] != NULL) {
			cout << "\n--- Item number " << (i + 1) << " ---" << endl;
			l[i]->printItem();

			total += l[i]->getTotal();
		}
	}
	cout << "\n\tThe total price for all items is $" << total << "." << endl;
}

/*********************************************************************
 ** Function: addItem
 ** Description: Adds an Item object to the list.
 ** In the case that the list array has become filled, the rebuild
 ** function is called, which recreates the dynamic array so that it can
 ** hold more items.
 ** It uses the == operator to check that another item of the same
 ** name does not exist. If it does, the item is not added. Otherwise
 ** an Item object is created and the spot in the array is set to point
 ** to that Item.
 *********************************************************************/

void List::addItem() {
	cin.clear();
	cin.ignore();
	
	// FIRST: check whether or not the array needs to be expanded.
	if (count == num) {
		rebuild(l);	}

	string name;
	string unit;
	double price;
	int howMany;

	cout << "Enter the name of the item." << endl;
	getline(cin, name);

	for (int i = 0; i < count; i++) {
		if (*l[i] == name) {
			cout << "\nThe name of this item already matches another item on the list." << endl;
			cout << "Try again to add a unique item." << endl;
			menu();
		}
	}

	cout << "Enter the unit of measure for this item." << endl;
	getline(cin, unit);
	cout << "How much does one cost? Do not include a dollar sign." << endl;
	price = getDouble();
	cout << "How many of this item total? Please enter a whole number." << endl;
	howMany = getOne();

	l[count] = new Item(name, unit, howMany, price);
				count++;
				cout << "The item has been added." << endl;
}

/*********************************************************************
 ** Function: removeItem
 ** Description: This function is called in order to remove an Item from
 ** the list. In the case of an empty list, it says that the list is empty
 ** and returns to the menu.
 ** Otherwise, it prints the names and corresponding numbers of the Items
 ** in the List array. The function receives a number from the user (or 
 ** gives the option to type 0 to return to the menu without removing
 ** an item) and then sets the corresponding space in the array to NULL.
 ** In order to prevent spaces in the array, the contents of array are
 ** shifted to the left starting from the empty space.
 *********************************************************************/

void List::removeItem() {
	cin.clear();
	cin.ignore();

		// Prevent attempts to remove from an empty list.
	if (count == 0) {
		cout << "There are no items to remove." << endl;
		menu();
	}

		// List all of the items that can be removed, along with their numbers.
	int itemNum;
	cout << "These are the items in the list: " << endl;
	for (int i = 0; i < num; i++) {
		if (l[i] != NULL) {
			cout << "\t" << (i + 1) << ": " << l[i]->getName() << endl;
		}
	}

	cout << "Which item would you like to remove?" << endl;
	cout << "Enter 0 if you do not want to remove an item." << endl;
	//cin >> itemNum;
	itemNum = getOne();
	if (itemNum == 0)
		cout << "Returning to the menu." << endl;

		// if the number is anything besides 0 or one of the listed numbers,
		// refresh the remoteItem function.
	else if (itemNum > count) {
		cout << "The number you entered is not one of the options.";
		removeItem();
	}

	else {
		cout << "Removing item " << itemNum << "." << endl;

		l[itemNum-1] = NULL;		// Set the space to NULL, removing the item.
		count--;

		// Move all of the items into new spots to fill the empty gap.
		cout << "Shifting all items to their new position in the List." << endl;
		for (int i = (itemNum-1); i < (num-1); i++) {
			if (l[i+1] != NULL) {
				l[i] = l[i+1];				// Move the Item pointer from the next spot
				l[i+1] = NULL;				// Set the next spot to NULL
			}
		}
	}
}

/*********************************************************************
 ** Function: rebuild
 ** Description: Called from the addItem function in the case that 
 ** the array is too small. This function doubles the num variable,
 ** deletes the old array, and then creates a larger one and places the 
 ** Items back into the array in their places.
 *********************************************************************/

void List::rebuild(Item** temp) {
	num *= 2;								// Whenever the list becomes full,
											// double its space.

	//delete[] l;								// delete the full array l
	l = new Item*[num];						// create a new larger l
	for (int i = 0; i < (num/2) ; i++) {	// fill it with the old pointers!
		l[i] = temp[i];
	}
	for (int i = (num/2); i < num; i++) {
		l[i] = NULL;
	}
}

/*********************************************************************
 ** Function: cleanUp
 ** Description: Called when the user exits the menu, it deletes the 
 ** dynamic array.
 *********************************************************************/

void List::cleanUp() {
	delete[] l;
}