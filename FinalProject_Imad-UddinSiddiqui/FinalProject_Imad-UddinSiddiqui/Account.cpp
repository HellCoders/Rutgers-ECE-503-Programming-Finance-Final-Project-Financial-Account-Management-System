#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

Account::Account()
{
	setCashBalance(10000);
}

void Account::setCashBalance(double money)
{
	cashBalance = money;
}

double Account::getCashBalance()
{
	return cashBalance;
}