#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Item.hpp"
using namespace std;

class ShoppingCart
{
private:
	Item *cart[100];
	int arrayEnd;		// keeps track of the index of the next empty
						// spot of the array
public:
	ShoppingCart();
	void addItem(Item * const);
	double totalPrice();
};

#endif
