#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item
{
private:
	string name;			// item name
	double price;			// price per unit
	int quantity;			// item quantity

public:
	Item();
	Item(string, double, int);
	void setName(string);
	string getName();
	void setPrice(double);
	double getPrice();
	void setQuantity(int);
	int getQuantity();
};

#endif