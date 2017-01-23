/************************************************************************************
 * FILENAME		: LawnMaintenanceCalc.cpp                                             *
 * PROGRAMMER	: Paige-David Peck                                                    *
 * PURPOSE		: Calculates and displays the cost of a lawn mower					  *
 ************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Declare variable
	string user_name;
	string mower_name;

	int cut_speed = 2;
	int length;
	int width;
	int property_size;

	double house_size = .4;
	double burn_rate = 1.2;
	double total_size_of_lawn;
	double pay_per_hour;
	double cut_time_minutes;
	double cut_time_hours;
	double gas_consumed;
	double total_fee;
	
	double break_time, new_minutes, break_pay;

	//Introduction output
	cout << "Hello! And welcome to Super Lawn Maintenance 3000 Deluxe Edition! " << endl;

	//Input items
	cout << "\nLet's get started by entering your name: " << endl;
	getline( cin, user_name);
	cout << "And what is the name of the lawn mower: " << endl;
	getline( cin, mower_name);
	cout << "Please enter the length of the property in feet rounded up: " << endl;
	cin >> length;
	cout << "Please enter the width of the property in feet rounded up: " << endl;
	cin >> width;
	cout << "And please enter the pay per hour for the lawn mower: " << endl;
	cin >> pay_per_hour;


	//Calculations
	property_size = length * width;
	total_size_of_lawn = property_size - (house_size * property_size);
	cut_time_minutes = (total_size_of_lawn / cut_speed) / 60;
	cut_time_hours = cut_time_minutes / 60;
	gas_consumed = cut_time_hours * burn_rate;
	total_fee = pay_per_hour * cut_time_hours;
	//Extra credit
	break_time = cut_time_minutes / 12.0;
	new_minutes = break_time + cut_time_minutes;
	break_pay = (new_minutes / 60) * pay_per_hour;


	//Output items
	//MAKE MORE USER FRIENDLY
	cout	<< "\n\nThank you " 
			<< user_name << ". "
			<< mower_name << " will need to cut \n"
			<< total_size_of_lawn << " square feet. It will take "
			<< cut_time_minutes << " minutes while using "
			<< gas_consumed << " gallons \nof fuel. You will owe "
			<< mower_name << " $" 
			<< total_fee << ".\n" << endl;

	cout	<< "\n\nIf you are to give " 
			<< mower_name << " a 5 minute break every hour, then the amount \nof time it will take is " 
			<< new_minutes << " minutes. And the pay would instead be $" 
			<< break_pay << ".\n\nThank you for using the Deluxe Edition, \nand we look forward to serving you in the future!\n" << endl;




	return 0;
}