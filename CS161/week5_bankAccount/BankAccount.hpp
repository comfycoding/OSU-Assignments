/*********************************************************************
** Author: Darlene Zouras
** Date: February 1, 2016
** Description: Project 5.b, BankAccount.cpp and BankAccount.hpp
** This program creates a class called BankAccount that can be used to
** create the customer information for a bank account. It also has included
** member functions that give it the ability to deposit to or withdraw from
** the customer's balance.
*********************************************************************/

// BankAccount.hpp is the BankAccount class specification file

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

class BankAccount
{
private:
	string customerName;
	string customerID;
	double customerBalance;

public:
	BankAccount(string, string, double);
	void withdraw(double);
	void deposit(double);
	string getCustomerName();
	string getCustomerID();
	double getCustomerBalance();

};
#endif