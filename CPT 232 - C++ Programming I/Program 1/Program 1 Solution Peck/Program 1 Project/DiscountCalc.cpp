/************************************************************************************
 * FILENAME		: Discountcalc.cpp                                                    *
 * PROGRAMMER	: Paige-David Peck                                                    *
 * PURPOSE		: Calculates and displays the discount of an item in a hardware store *
 ************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//declare variables
	string customer_name;
	string item_name;

	int community_years;
	int item_quantity;

	double original_price;
	double new_price;
	double total_cost;
	double discount_percent = .35; // constant put in a variable for a user to easily change it without sifting through code

	//Add introduction output


	//Input items
	//Make more user friendly!!!!!!!
	cout << "Enter name: ";
	cin >> customer_name;
	cout << "Years in Community: ";
	cin >> community_years;
	cout << "Item wish to purchase: ";
	cin >> item_name;
	cout << "What is the original price: ";
	cin >> original_price;
	cout << "How many items: ";
	cin >> item_quantity;
	
	//Calculations
	new_price = discount_percent * original_price;
	total_cost = new_price * item_quantity;


	//Output items
	//Make more user friendly!!!!!!!! - must change to own thoughts
	cout << "Well, " << customer_name << ", you asked for the new price for a " << item_name << ".\n"
		<< "With the " << discount_percent * 100 << "% discount today, our " << item_name << " has been marked\n"
		<< "down from the advertised price of $" << original_price << " down to a new price of\n"
		<< "$" << new_price << ".  So, since you want to buy " << item_quantity << " of these, your total cost for\n"
		<< "them comes to $" << total_cost << ".  Since you have lived around here for " << community_years << " years,\n"
		<< "I’m surprised I haven’t met you before, but I’m awfully glad to count\n"
		<< "you as a valued customer.  Thanks for stopping by and hope to see you again soon." << endl;




	return 0;
}