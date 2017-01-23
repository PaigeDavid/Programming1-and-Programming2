/************************************************************************************
 * FILENAME		: DiscountCalculator.cpp                                                    *
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
	double discount_price;
	double discount_percent = .35; // constant put in a variable for a user to easily change it without sifting through code

	//Introduction output
	cout << "Welcome to Hardware Central! This computer terminal will help you calculate the discount on an item your looking for!\n";

	//Input items
	cout << "What is your first name: ";
	cin >> customer_name;
	cout << "How many years have you lived in the community: ";
	cin >> community_years;
	cout << "What is the name of the item you are looking for: ";
	cin.ignore( 100, '\n');
	getline( cin, item_name, '\n' );
	cout << "What is the original price of your item: ";
	cin >> original_price;
	cout << "And lastly, how many would you like: ";
	cin >> item_quantity;
	
	//Calculations
	discount_price = discount_percent * original_price;
	new_price = original_price - discount_price;
	total_cost = new_price * item_quantity;


	//Output items
	cout	<< "\n\nWell, "
			<< customer_name << ", you were looking for the new price of a "
			<< item_name << ".\n" << "With the "
			<< discount_percent * 100 << "% discount this week, our " 
			<< item_name << " has been marked\n"
			<< "down from the original price of $"
			<< original_price << " down to the new low price of\n$" 
			<< new_price << ".  So, since you want to pruchase " 
			<< item_quantity << " of these, your total cost for\n"
			<< "them comes to $" 
			<< total_cost << ".\n\nSince you have lived around here for "
			<< community_years << " years,\n"
			<< "I am surprised this is the first time we have met, but I am very \n"
			<< "happy to meet you, and we hope to see you here again soon!\n" << endl;




	return 0;
}