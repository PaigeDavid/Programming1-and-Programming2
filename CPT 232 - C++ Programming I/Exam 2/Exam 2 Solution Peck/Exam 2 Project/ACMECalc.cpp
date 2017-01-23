/***************************************************************************************************
* FILENAME		: ACMECalc.cpp                                                                     *
* PROGRAMMER	: Paige-David Peck                                                                 *
* PURPOSE		: Calculates and displays the discount depending on the amount of pounds purchased *
***************************************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 

using namespace std;

int main()
{

	//Declare variables
	string user_name;

	double purchase_pounds, reduction_rate, total_cost, total_cost_discount, 
		total_savings;

	const double BASE_PRICE = 1.13;

	
	//Intro output
	cout	<< setw(50) << "PECK CODING MAX\n";
	cout	<< setw(60) << "ACME Cement Company Discount Calcultaor\n" << endl;

	//Input statements
	cout	<< "Please enter your name: ";
	getline (cin, user_name);
	cout	<< "\nThank you, " << user_name << ". Please enter the amount concrete\n"
			<< "per pound you wish to purchase: " << endl;
	cin >> purchase_pounds;



	//Calculations
	total_cost = purchase_pounds * BASE_PRICE;
	//cout << "Total Cost: " << total_cost << endl; // test	
	
	//cout << "Purchase pounds: " << purchase_pounds << endl; // test

	if(purchase_pounds >= 0.0 && purchase_pounds <= 500.0 ) //If statements to initialize variable rectuion rate only
		reduction_rate = .02;
	else if(purchase_pounds > 500.0 && purchase_pounds <= 9000.0)
		reduction_rate = .04;
	else if(purchase_pounds > 9000.0 && purchase_pounds <= 15000.0)
		reduction_rate = .05;
	else if(purchase_pounds > 15000)
		reduction_rate = .09;
	else
	{
		cout	<< "Invalid Entry, Program terminating" << endl;
		return 0;
	}
	//END IF

	//cout << "Reduction rate: " << reduction_rate << endl; // test

	total_cost_discount = total_cost * reduction_rate;
	//cout << "Total Cost Discount: " << total_cost_discount << endl; //test

	total_savings = total_cost - total_cost_discount;
	//cout << "Total Savings: " << total_savings << endl; //test

	system("cls");

	//Closing Report
	cout << fixed;
	cout << setprecision(2);

	cout	<< setw(50) << "PECK CODING MAX\n";
	cout	<< setw(60) << "ACME Cement Company Discount Calcultaor\n" << endl;

	cout	<< "ACME Cement Company" << endl;
	cout	<< "1512 Skyline Drive" << endl;
	cout	<< "Charleston, SC 29414" << endl;
	cout	<< "555-4312-2341\n" << endl;
	cout	<< setfill('-') << setw(74) << "-" << endl;
	cout	<< setfill(' ');
	cout	<< "Item" << setw(15) << "| Price" << setw(10) << "| Qty" << setw(25) 
			<< "| Discount Rate" << setw(10) << "| Total" << setw(10) << "|" << endl;
	cout	<< setfill('-') << setw(74) << "-" << endl;
	cout	<< setfill(' ');
	cout	<< "Cement" << setw(10) << "$" << BASE_PRICE << setw(15) << purchase_pounds << setw(15) 
			<< reduction_rate * 100 << "%" << setw(10) << "$" << total_cost << endl;
	cout	<< setfill('-') << setw(74) << "-" << endl;
	cout	<< setfill(' ') << endl;
	cout	<< endl;
	cout	<< setw(65) << "Pre-Discount Total: " << setw(5) << total_cost << endl;
	cout	<< setw(65) << "Discount: " << setw(5) << total_cost_discount << endl;
	cout	<< setw(75) << setfill('-') << " " << endl;
	cout	<< setfill(' ');
	cout	<< setw(65) << "Total Amount Due: " << setw(5) << total_savings << endl;


	//Final Output
	cout	<< "\nThank you, " << user_name << ". After the purchase, your product will arrive \nwithin 5 to 10 business days.\n" << endl;

	return 0;
}