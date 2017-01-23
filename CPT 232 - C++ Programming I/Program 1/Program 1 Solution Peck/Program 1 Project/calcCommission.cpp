/************************************************************************************
 * FILENAME		: calcCommission.cpp                                                 *
 * PROGRAMMER	: Paige-David Peck                                                  *
 * PURPOSE		: Calculates and displays the commission                            *
 ************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//declare vaiables
	double sale1 = 0.0;
	double sale2 = 0.0;
	double commissionRate = 0.0;
	double totalSales = 0.0;
	double commission = 0.0;

	//Introduction output
	cout << "Welcome to Commission Calculator 2.0! " << endl;
	cout << "Let's begin calculating the amount you have earned from your sales!\n\n";

	//enter input items
	cout << "Amount earned from first sale? ";
	cin >> sale1;
	cout << "And from the second sale? ";
	cin >> sale2;
	cout << "What is your commision rate in decimal format? ";
	cin >> commissionRate;

	//calculate total sales and commission
	totalSales = sale1 + sale2;
	commission = totalSales * commissionRate;

	//display the commission
	cout << "Your commission comes out to be: $" << commission << endl;

	//Outro output
	cout << "\nThank you for using Commission Calculator 2.0!\n"
		<< "Please feel free to leave feedback at our homepage, www.commcalc.com!\n" << endl;

	return 0;
}