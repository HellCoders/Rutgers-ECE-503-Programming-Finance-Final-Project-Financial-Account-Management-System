#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

// Abstract base class, Account, for BankAccount and StockAccount. It offers basic functionality,
// from which the derived classes build off of, making this a usage of the Template Design Pattern
class Account
{
	public:
		Account();								// Constructor

		void setCashBalance(double);			// Adjusts cashBalance
		double getCashBalance();				// Returns cashBalance
		virtual void changeBalance(double) = 0; // Function that's implemented by
												// derived classes to save the cashBalance
												// into txt files
	private:
		double cashBalance;
};

#endif ACCOUNT_H