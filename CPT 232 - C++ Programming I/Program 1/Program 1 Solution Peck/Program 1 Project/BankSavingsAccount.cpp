//FILE	:	Bank Savings Account.cpp
//PROG	:	Dave Jones
//PURP	:	Simple savings account simulator

#include <iostream>
#include <string>
using namespace std;

#include "SavingsAccount.h"

int main()
{
	//Create one instance of a SavingsAccount
	SavingsAccount  myAccount;
	double currentBalance;

	currentBalance  =  myAccount.getBalance();

	//This will initially display garbage:  the object has no initial value in its balance variable
	cout  <<  "The initial balance is "  <<  currentBalance  <<  endl;

	return 0;
}
