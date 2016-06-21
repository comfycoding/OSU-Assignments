/*********************************************************************
** Program Filename: List.hpp
** Author: Darlene Zouras
** Date: 4/21/2016
** Description: List class header file.
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"

class Item;

class List {
private:
	Item* *l;						// Dynamic array to Item pointers
	int num;						// The size of the array
	int count;						// counter for the next open space in the array	
public:
	List();
	void menu();					// Options menu
	void displayList();
	void addItem();
	void removeItem();
	void rebuild(Item** temp);		// Doubles the space in the array l
	void cleanUp();					// deletes the dynamic array
};

#endif