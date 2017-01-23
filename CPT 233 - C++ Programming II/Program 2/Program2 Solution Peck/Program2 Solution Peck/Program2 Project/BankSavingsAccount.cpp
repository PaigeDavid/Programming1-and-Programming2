//FILE	:	Bank Savings Account.cpp
//PROG	:	Paige Peck
//PURP	:	Simple savings account simulator

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "SavingsAccount.h"

//FUNCTION prototypes
void depositToAccount (SavingsAccount &, double);
void withdrawFromAccount (SavingsAccount &, double);

int main()
{
	//Declaration
	//Create one instance of a SavingsAccount
	SavingsAccount myAccount;

	string acctNumber;
	char choice;

	int months = 1;
	double currentBalance;
	double deposit;
	double withdraw;
	double intRate;
	double startingBalance;
	double endingBalance;
	double interestEarned;

	//Call function to do the actual deposit
	//depositToAccount (myAccount, deposit);

	//Initialization
	acctNumber = myAccount.getAccountNumber();
	currentBalance = myAccount.getBalance();
	intRate = myAccount.getInterestRate();

	//Output
	cout << "Welcome to South Carolina Bank." << endl;
	cout << "The account number is: " << acctNumber << endl;
	cout << "The initial balance is: " << currentBalance << endl;
	cout << "The interest rate is: " << intRate * 100 << "%" << endl; 

	//Deposit
	cout << "\nWould you like to make a deposit?(y for yes, n for no) " << endl;
	cin >> choice;

	choice = toupper(choice);

	if(choice == 'Y')
	{
		cout << "Enter amount to deposit:  ";
		cin  >> deposit;

		//Call function to do the actual deposit
		depositToAccount(myAccount, deposit);
		currentBalance = myAccount.getBalance();
	}//END if

	//Withdraw
	cout << "\nWould you like to make a withdraw?(y for yes, n for no) " << endl;
	cin >> choice;

	choice = toupper(choice);

	if(choice == 'Y')
	{
		cout << "Enter amount to withdraw: ";
		cin >> withdraw;

		//Check to see if withdraw amount is more than balance
		if(withdraw > currentBalance)
		{
			while(withdraw > currentBalance)
			{
				cout << "\nERROR: Can not have a negative balance! Please re-enter withdraw amount: " << endl;
				cin >> withdraw;
			}//END while
			//cout << "EXIT while" << endl;
		}//END if
		//cout << "EXIT if" << endl;

		//Call funtion to do the actual withdraw
		withdrawFromAccount(myAccount, withdraw);
		currentBalance = myAccount.getBalance();
	}//END if
	
	cout << "\nThe account balance is: " << currentBalance << "\n\n" << endl;

	startingBalance = currentBalance;

	cout << fixed << setprecision(2);

	//Final Output
	cout << "Months" << setw(15) << "Starting" << setw(15) << "Interest"
		<< setw(15) << "Ending" << endl;

	cout << setw(3) << "#" << setw(17) << "Balance" << setw(14) << "Earned"
		<< setw(18) << "Balance" << endl;


	while(months < 13)
	{
		interestEarned = startingBalance * intRate;
		endingBalance = startingBalance + (startingBalance * intRate);

		cout << setw(3) << months << setw(17) << startingBalance << setw(14) << interestEarned 
			<< setw(18) << endingBalance << endl;
		
		startingBalance = endingBalance;
		months++;
	}//END while

	return 0;
}//END main

/*******************************************************	*
 * PURPOSE	: Deposit money into savings account			*
 * PASSED IN: myAccount and the deposit						*
 * RETURNED: nothing										*
 ************************************************************/
void depositToAccount (SavingsAccount &thisAccount, double thisDeposit)
{
	//Call the object’s method addToBalance to make the deposit
	thisAccount.addToBalance(thisDeposit);
}//END depositToAccount

/*******************************************************	*
 * PURPOSE	: withdraw money from savings account			*
 * PASSED IN: myAccount and the withdrawl					*
 * RETURNED: nothing										*
 ************************************************************/
void withdrawFromAccount (SavingsAccount &thisAccount, double thisWithdraw)
{
	//Call the object’s method addToBalance to make the deposit
	thisAccount.subtractFromBalance(thisWithdraw);
}//END withdrawFromAccount
