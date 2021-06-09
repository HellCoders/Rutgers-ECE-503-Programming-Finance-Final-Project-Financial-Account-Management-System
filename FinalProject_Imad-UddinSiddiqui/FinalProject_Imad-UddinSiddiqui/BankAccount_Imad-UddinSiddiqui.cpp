#define _CRT_SECURE_NO_WARNINGS

#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <string>
using namespace std;

BankAccount::BankAccount()
{
	// Reference for our cash balance text file
	ifstream cashBalance("cash_balance.txt");

	// If file exists, extract cash balance. If not, make the file
	if (cashBalance.good() == true)
	{
		double moolah;
		cashBalance >> moolah;
		setCashBalance(moolah);
	} else {
		setCashBalance(10000);
		changeBalance(10000);
	}

	// Check if stock transaction history exists. If not, then make the file
	// If it does, don't do anything
	ifstream bth("bank_transaction_history.txt");
	if (bth.good() == false)
	{
		ofstream initialize;
		initialize.open("bank_transaction_history.txt", ios::app);
		initialize << left << setw(25) << "Event" << setw(25) << "Amount" << setw(25) << "Date" << setw(25) << "Balance" << "\n";
		initialize.close();
	}
}

void BankAccount::changeBalance(double money)
{
	ofstream initialize;
	initialize.open("cash_balance.txt");
	initialize << money << "\n";
	initialize.close();
}

double BankAccount::obtainBalance()
{
	ifstream cashBalance("cash_balance.txt");
	double moolah;
	cashBalance >> moolah;
	return moolah;
}

void BankAccount::deposit(double money)
{
	// If the deposit is 0, return an error message. Otherwise, deposit
	if (money <= 0) {
		cout << "Error: Not depositing anything\n";
		return;
	} else {
		cout << "Deposit succeeded!\n";
	}

	setCashBalance(obtainBalance() + money);

	// Now to change cash balance
	changeBalance(getCashBalance());

	// Now to change transaction history
	changeHistory(money, 2);
}

void BankAccount::withdraw(double money)
{
	// If the withdrawal exceeds your balance or is 0, return an error message. Otherwise, withdraw
	if (money > getCashBalance())
	{
		cout << "Error: Withdraw exceeds cash balance\n";
		return;
	} else if (money <= 0) {
		cout << "Error: Not withdrawing anything\n";
		return;
	} else {
		cout << "Withdraw succeeded!\n";
	}

	setCashBalance(obtainBalance() - money);

	// Now to change cash balance
	changeBalance(getCashBalance());

	// Now to change transaction history
	changeHistory(money, 1);
}

void BankAccount::printTransactionHistory()
{
	ifstream transactions("bank_transaction_history.txt");
	string transaction;
	while (getline(transactions, transaction))
	{
		cout << transaction << endl;
	}
	transactions.close();
}

void BankAccount::changeHistory(double money, int mode)
{
	string method;
	if (mode == 1)
	{
		method = "Withdrawal";
	} else if (mode == 2) {
		method = "Deposit";
	}

	ofstream info;
	info.open("bank_transaction_history.txt", ios::app);
	time_t seconds;
	seconds = time(NULL);
	tm* timeinfo;
	timeinfo = localtime(&seconds);
	string moolah = "$" + to_string(money);
	string balance = "$" + to_string(getCashBalance());
	string currDate = to_string(timeinfo->tm_mon + 1) + "/" + to_string(timeinfo->tm_mday) + "/" + to_string(timeinfo->tm_year + 1900);
	info << left << setw(25) << method << setw(25) << moolah << setw(25) << currDate << setw(25) << balance << "\n";
	info.close();
}