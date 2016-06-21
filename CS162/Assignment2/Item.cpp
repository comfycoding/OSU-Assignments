/*********************************************************************
** Program Filename: 
** Author: Darlene Zouras
** Date: 4/21/2016
** Description: Item class member functions
*********************************************************************/

#include "Item.hpp"
#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*********************************************************************
 ** Function: printItem
 ** Description: Prints the information held in a particular Item object.
 ** Parameters: Called by a pointer in the List class' displayList function.
 *********************************************************************/

void Item::printItem() {
	cout << "Item: " << name << endl;
	cout << "Unit of measure: " << unit << endl;
	cout << "Price per unit: $" << ppUnit << endl;
	cout << "Total units: " << numUnit << endl;
	cout << "\tTotal price for " << numUnit << " " << unit << ": $" << (numUnit * ppUnit) << endl;
}

/*********************************************************************
 ** Function: getTotal
 ** Description: Returns a double that is the price of all of the units
 ** of a particular item.
 *********************************************************************/

double Item::getTotal() {
	return (numUnit * ppUnit);
}

/*********************************************************************
 ** Function: getName
 ** Description: Returns the name of the item.
 *********************************************************************/

string Item::getName() {
	return name;
}

/*********************************************************************
 ** Function: Overloaded == operator
 ** Description: This operator helps to compare the name of a new item
 ** added to the List array by comparing it the names of the other Item
 ** object pointers held in the array already. This prevents duplicate
 ** entries.
 *********************************************************************/

bool Item::operator==(string a) {
	return (name == a);
}