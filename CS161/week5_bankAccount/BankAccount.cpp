/*********************************************************************
** Author: Darlene Zouras
** Date: February 1, 2016
** Description: Project 5.b, BankAccount.cpp and BankAccount.hpp
** This program creates a class called BankAccount that can be used to
** create the customer information for a bank account. It also has included
** member functions that give it the ability to deposit to or withdraw from
** the customer's balance.
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;
#include "BankAccount.hpp"

/* BankAccount::BankAccount
The constructor, which assigns the private values of an object. */
BankAccount::BankAccount(string n, string id, double b)
{
	customerName = n;
	customerID = id;
	customerBalance = b;
}

/* BankAccount::withdraw
Subtracts an amount from the customerBalance value. */
void BankAccount::withdraw(double sub)
{
	customerBalance -= sub;
}

/* BankAccount::deposit
Adds an amount to the customerBalance value. */
void BankAccount::deposit(double add)
{
	customerBalance += add;
}

string BankAccount::getCustomerName()
{
	return customerName;
}

string BankAccount::getCustomerID()
{
	return customerID;
}

double BankAccount::getCustomerBalance()
{
	return customerBalance;
}