/*********************************************************************
** Program Filename: addArray.cpp
** Author: Darlene Zouras
** Date: 4/29/2016
** Description: Completes the first task of the Module 1 assignment.
** Asks the user how many numbers they would like to add to an array,
** and then receives those numbers. They are placed in an array and
** then the recursive function produces the sum of all of the numbers.
*********************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 ** Function: addArray
 ** Description: The recursive function for the first task.
 ** It works by receiving the array of integers, as well as its length.
 ** It then works through each of the spaces until it reaches the base
 ** case, which is when it reaches the first number in the array.
 *********************************************************************/

int addArray(int arr[], int length) {
    if (length == 0)
        return arr[0];

    else {
        return arr[length] + addArray(arr, (length - 1));
    }
}

/*********************************************************************
 ** Function: addMain
 ** Description: The main function that sets up so that the recursive 
 ** function has the information it needs. Asks the user how many
 ** integers they would like in an array, then asks what those integers
 ** are. It calls the recursive function addArray to get the sum.
 *********************************************************************/

void addMain() {
    cin.clear();
    cin.ignore();

    int nums;
    cout << "\nHow many numbers would you like to add to the array? ";
    nums = getOne();

    int array[nums];

    for (int i = 0; i < nums; i++) {
        int j;
        cout << "Enter number " << (i + 1) << ": ";
        j = getOne();
        array[i] = j;
    }

    cout << "These are the numbers in the array: " << endl;
    for (int i = 0; i < nums; i++) {
        cout << array[i] << " ";
    }

    int total = addArray(array, (nums - 1));
    cout << "\nThe sum of these numbers is " << total << endl;
}
