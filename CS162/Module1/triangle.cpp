/*********************************************************************
** Program Filename: triangle.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Completes the third task for the Module 1 assignment.
** Uses a recursive function to sum up a triangle of items arranged
** in rows.
*********************************************************************/

#include <iostream>
using std::cout;
using std::cin;

/*********************************************************************
 ** Function: triSum
 ** Description: The recursive function. It adds up each number of each
 ** row until it reaches the base case, which is when there is only
 ** one row. It returns the total where it was called.
 *********************************************************************/

int triSum(int row) {
	if (row == 1)
		return 1;
	else
		return row + triSum(row - 1);
}

/*********************************************************************
 ** Function: triMain
 ** Description: Gets the number of rows from the user, then calls
 ** the recursive function triSum with that number.
 *********************************************************************/

void triMain() {
	cin.clear();
    cin.ignore();

	int triRows;
	cout << "\nEnter the number of rows in the triange: " << endl;
	triRows = getOne();

	int total = triSum(triRows);
	cout << "The sum of objects in the triangle with " << triRows << " rows is " << total << "." << endl;
}