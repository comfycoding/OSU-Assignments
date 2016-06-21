#include "Item.hpp"

Item::Item()									// default constructor
{
	name = "";
	price = 0.0;
	quantity = 0;
}

Item::Item(string n, double p, int q)			// constructor
{
	setName(n);
	setPrice(p);
	setQuantity(q);
}

void Item::setName(string n)					// sets name variable
{	name = n;	}

string Item::getName()
{	return name; }

void Item::setPrice(double p)					// sets price variable
{	price = p;	}

double Item::getPrice()
{	return price;	}

void Item::setQuantity(int q)					// sets quantity variable
{	quantity = q;	}

int Item::getQuantity()
{	return quantity;	}