#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Account.h"
#include <cstddef>
using namespace std;

class BankAccount : public Account
{
public:
	// Singleton Design Pattern to ensure only one bank account is
	// available to use any time the project is run. Meyers implementation
	// specifically
	static BankAccount& getInstance()
	{
		static BankAccount instance;
		return instance;
	}

	void changeBalance(double); // Changes balance in txt file
	double obtainBalance(); // Obtains balance from txt file
	void deposit(double); // Deposits money
	void withdraw(double); // Withdraws money
	void printTransactionHistory(); // Prints transaction history
	void changeHistory(double, int); // To adjust transaction txt file

private:
	BankAccount(); // Constructor
};

#endif BANKACCOUNT_H