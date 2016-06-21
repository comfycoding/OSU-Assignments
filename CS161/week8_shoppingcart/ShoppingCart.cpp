#include "ShoppingCart.hpp"
#include "Item.hpp"

ShoppingCart::ShoppingCart()
{	
	for (int count = 0; count < 100; count++)
		cart[count] = NULL;				// sets all of the array to NULL
	arrayEnd = 0;						// initializes arrayEnd to zero
}

void ShoppingCart::addItem(Item * const thing)
{
	cart[arrayEnd] = thing;				// inserts the item into the next
										// empty space of the cart array
	arrayEnd++;							// sets arrayEnd to the next empty space
}

double ShoppingCart::totalPrice()
{	
	double total = 0, temp = 0;
	int count = 0;
	while (cart[count] != NULL)			// loop through elements that are NOT NULLED
	{
		temp = (cart[count]->getPrice()) * (cart[count]->getQuantity());
		total += temp;
		count++;
	}

	return total;
} 

