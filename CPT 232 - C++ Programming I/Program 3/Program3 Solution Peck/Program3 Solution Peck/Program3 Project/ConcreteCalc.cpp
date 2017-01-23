/****************************************************************************************
 * FILENAME		: ConcreteCalc.cpp                                                      *
 * PROGRAMMER	: Paige-David Peck                                                      *
 * PURPOSE		: Calculates and displays the cost of concrete for a dome and pond area *
 ***************************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//declare variables
	string customer_name;

	int num_seats;

	double pond_diameter, pond_radius, dome_diameter, dome_radius, pond_area, 
		total_dome_area, dome_area_minus_pond, pond_concrete_total, 
		dome_concrete_total, dome_volume, volume, dome_area_half;

	const double PI = 3.141592653589793;
	const double POND_CONCRETE_COST = 37;
	const double DOME_CONCRETE_COST = 27.50;

	//Ourput introdructory
	cout << "Welcome to SeaWorld Concrete Calculator Max! \nWe will get you on your way to find out how much the concrete will cost!\n" << endl;

	//Input statements
	cout << "Please enter your name: " << endl;
	getline ( cin, customer_name );
	cout << "Thank you, " << customer_name << ". Please enter the diameter of the pond: " << endl;
	cin >> pond_diameter;


	dome_diameter = pond_diameter * 3.0;
	//cout << "Dome Diameter: " << dome_diameter << endl;
	pond_radius = pond_diameter / 2.0;
	//cout << "Pond radius: " << pond_radius << endl;
	dome_radius = dome_diameter / 2.0;
	//cout << "Dome radius: " << dome_radius << endl;
	pond_area = pow(pond_radius, 2) * PI;
	//cout << "Pond Area: " << pond_area << endl;
	total_dome_area = pow(dome_radius, 2) * PI;
	//cout << "Total dome area: " << total_dome_area << endl;
	dome_area_minus_pond = total_dome_area - pond_area;
	//cout << "Dome Area Minus Pond: " << dome_area_minus_pond << endl;
	dome_area_half = dome_area_minus_pond / 2.0;
	//cout << "Dome Area Half: " << dome_area_half << endl;
	pond_concrete_total = POND_CONCRETE_COST * pond_area;
	//cout << "Pond Concrete Total: " << pond_concrete_total << endl;
	dome_concrete_total = DOME_CONCRETE_COST * dome_area_minus_pond;
	//cout << "Dome concrete total: " << dome_concrete_total << endl;
	num_seats = dome_area_half / 5.5;
	//cout << "Number of seats: " << num_seats << endl;
	volume = 11.0 * pond_area;
	//cout << "Volume: " << volume << endl;
	dome_volume = ( (4.0/3.0) * PI * (pow(dome_radius, 3)) ) / 2.0;
	//cout << "Dome volume: " << dome_volume << endl;


	//Output statements
	cout	<< "\n\n" 
			<< customer_name << ", the diameter of the pond is going to be: "
			<< setw(30) << setfill('-') << pond_diameter << ",\nwhile the diamter of the dome is going to be: "
			<< setw(32) << dome_diameter << ".\nThe area of the pond is: "  << fixed << setprecision(4)
			<< setw(53) << pond_area << ",\nand the area of the dome without the pond is going to be: " 
			<< setw(20) << dome_area_minus_pond << ".\nThe total cost of the concrete for the pond comes to: " << setprecision(2)
			<< setw(24) << pond_concrete_total << ".\nAnd the total cost of the concrete for the dome comes to: " 
			<< setw(20) << dome_concrete_total << ".\nThe volume of water to be put in the pond is going to be: " << setprecision(4)
			<< setw(20) << volume << ".\nAnd the number of seats you can place in the dome is: "
			<< setw(24) << num_seats << ".\n\nNow, if your looking at putting air-conditioning in,\nthe volume of the dome is: "
			<< setw(51) << dome_volume << ".\n\nWe hope your construction goes well "
			<< customer_name << "\nand hope to see you again for future calculations!\n" << endl;

	
	return 0;
}
