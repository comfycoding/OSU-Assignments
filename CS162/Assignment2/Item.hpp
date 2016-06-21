/*********************************************************************
** Program Filename: Item.hpp
** Author: Darlene Zouras
** Date: 4/21/2016
** Description: Item class header
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <cstring>
using std::string;

class Item {
private:
	string name;
	string unit;
	int numUnit;
	double ppUnit;
public:

	/*********************************************************************
 	** Function: Item constructor
 	** Description: Creates an Item class object.
 	** Parameters: Receives all of the information that is held by each 
 	** object and sets each variable.
 	*********************************************************************/

	Item(string n, string u, int num, double p) {
		name = n;
		unit = u;
		numUnit = num;
		ppUnit = p;
	};
	
	void printItem();
	double getTotal();
	string getName();
	bool operator==(string a);
};

#endif