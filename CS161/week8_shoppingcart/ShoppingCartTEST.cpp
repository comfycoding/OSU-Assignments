#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingCart.hpp"
using namespace std;

void showItem(Item);

int main()
{
	Item item0("Bulbasaur", 1.30, 1);
	Item item1("Squirtle", 1.70, 4);
	Item item2("Charmander", 1.60, 7);
	ShoppingCart cart1;

	cout << "These are the current items: " << endl;
	showItem(item0);
	showItem(item1);
	showItem(item2);

	cart1.addItem(&item0);
	cart1.addItem(&item1);
	cart1.addItem(&item2);
	double total = cart1.totalPrice();
	cout << "The total cost of all of the items in stock is $" << total << endl;

	return 0;
}

// Prints the information stored in each part of an Item class member
void showItem(Item thing)
{
	cout << "\nThe item is a " << thing.getName() << "." << endl;
	cout << "It costs $" << thing.getPrice() << "." << endl;
	cout << "They have " << thing.getQuantity() << " in stock." << endl;
}