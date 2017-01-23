/************************************************************************************************
* FILENAME		: seaworldCalc.cpp                                                              *
* PROGRAMMER	: Paige-David Peck                                                              *
* PURPOSE		: Calculates and displays the cost of concrete for a pond area as well as seats *
************************************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 

using namespace std;

int main()
{
	//declare vairables
	string customer_name;

	int contractor_quote, num_seats, seat_type, seat_contractor;

	double pond_diameter, pond_radius, dome_diameter, dome_radius, pond_area,
		total_dome_area, dome_area_minus_pond, dome_area_half, volume_gallons,
		volume_feet, pond_concrete_total, seat_size, contractor_bid, install_cost, seat_bid;

	const double PI = 3.141592653589793;

	//Introductory output
	cout << "                             PECK CODING UNLIMITED\n";
	cout << "                        DESIGN FOR SUMMERVILLE SEAWORLD\n" << endl;

	//Input statements
	cout << "Please enter your name: ";
	getline (cin, customer_name);
	cout << "\nThank you, " << customer_name << ". We will need a few numbers from you.\n"
		<< "Please refrain from using commas when inputting the figures.\n" << endl;

	cout << "First, please enter the number of gallons\nthat will be used for the porpoise pond: " << endl;
	cin >> volume_gallons;

	//cout << "Volume gallons: " << volume_gallons << endl; // test
	volume_feet = volume_gallons * 0.13368;
	//cout << "Volume feet: " << volume_feet << endl; //test
	pond_radius = sqrt(volume_feet / (PI * 11.0));
	//cout << "Pond radius: " << pond_radius << endl; //test
	pond_diameter = 2.0 * pond_radius;
	//cout << "Pond diameter: " << pond_diameter << endl; //test
	dome_diameter = pond_diameter * 3.0;
	//cout << "Dome diameter: " << dome_diameter << endl; //test
	dome_radius = dome_diameter / 2.0;
	//cout << "Dome radius: " << dome_radius << endl; //test
	pond_area = pow(pond_radius, 2) * PI;
	//cout << "Pond area: " << pond_area << endl; //test
	total_dome_area = pow(dome_radius, 2) * PI;
	//cout << "Total dome area: " << total_dome_area << endl; //test
	dome_area_minus_pond = total_dome_area - pond_area;
	//cout << "Dome area minus pond: " << dome_area_minus_pond << endl; //test
	dome_area_half = dome_area_minus_pond / 2.0;
	//cout << "Dome area half: " << dome_area_half << endl; //test

	//system("pause");
	system("cls");
	cout << fixed << setprecision(1);
	
	cout << "Alright, if we use " << volume_gallons << " gallons of water to fill the 11-foot pond,\nthat will make the pond "
		<< pond_diameter << " feet in diameter. If you\nare going to round the number for the contractor, lower the number\n"
		<< "so we don't use too much water!\n\n" << endl;

	cout << "Now, " << customer_name << ", lets choose the types of seats we want to install. \n\nThe two options we have are " 
		<< "wooden deck chairs and \nplastic seats that are bolted down. The plastic seats\nare smaller, so we will be able "
		<< "to place more of them.\n\n\nHere is a breakdown of the two options: \n" << endl;

	cout << setprecision(0);

	cout << "1     Wooden seats:  " << (dome_area_half / 5.5) << endl;
	cout << "2     Plastic seats: " << (dome_area_half / 4.8) << endl;

	cout << "\nPlease enter 1 for wooden and 2 for plastic: " << endl;
	cin >> seat_type;

	cout << endl;

	if(seat_type == 1)
	{
		cout << "Ok, we will be using the Wooden chairs" << endl;
		seat_size = 5.5;
	}
	else
	{
		cout << "Ok, we will be using the Plastic chairs" << endl;
		seat_size = 4.8;
	}
	//END IF

	
	num_seats = dome_area_half / seat_size;

	cout << setprecision(2);

	cout << "\n\nSo, " << customer_name << ", it is time to decide on which contractor you will be choosing.\n" 
		<< "Here is the breakdown: \n\n" << endl;

	cout << "BID     CONTRACTOR ID     BID AMOUNT ($ COST PER SQ FT)    TOTAL BID FOR THE JOB";
	cout << " 1          11237                 37.75                        $" << 37.75 * pond_area << endl;
	cout << " 2          10979                 38.95                        $" << 38.95 * pond_area << endl;
	cout << " 3          21352                 44.99                        $" << 44.99 * pond_area << endl;
	cout << " 4          22976                 45.35                        $" << 45.35 * pond_area << endl;
	cout << " 5          33209                 22.85                        $" << 22.85 * pond_area << endl;


	cout << "\nWhich contractor would you like to go with (1, 2, 3, 4, 5): ";
	cin >> contractor_quote;

	if(contractor_quote == 1)
		contractor_bid = 37.75;
	else if(contractor_quote == 2)
		contractor_bid = 38.95;
	else if(contractor_quote == 3)
		contractor_bid = 44.99;
	else if(contractor_quote == 4)
		contractor_bid = 45.35;
	else
		contractor_bid = 22.85;
	//END IF

	pond_concrete_total = contractor_bid * pond_area;

	cout << "\n\nGood. Lastly, " << customer_name << ", we need to decide on a contractor for installing the seats."
		<< "Here is the breakdown: \n\n" << endl;

	cout << "BID     CONTRACTOR ID     BID AMOUNT ($ COST PER seat)    TOTAL BID FOR THE JOB";
	cout << "  1          31237                 39.95                        $" << 39.95 * num_seats << endl;
	cout << " 2          12679                 34.50                        $" << 34.50 * num_seats << endl;
	cout << " 3          21372                 43.95                        $" << 43.95 * num_seats << endl;

	cout << "\nPlease choose the contractor for the job (1, 2, 3): ";
	cin >> seat_contractor;

	if(seat_contractor == 1)
		seat_bid = 39.95;
	else if(seat_contractor == 2)
		seat_bid = 34.50;
	else
		seat_bid = 43.95;
	//END IF

	install_cost = seat_bid * num_seats;

	//cout << "Install Cost: " << install_cost << " Pond concrete total: " << pond_concrete_total << endl; //test

	//system("pause");
	system("cls"); // Clear the screen

	//Closing report
	cout << "                             PECK CODING UNLIMITED\n";
	cout << "                      DESIGN FOR SUMMERVILLE SEAWORLD (V1.3)\n" << endl;

	cout << "POND VALUES" << endl;
	cout << "-----------" << endl;
	cout << "Diameter:           " << setprecision(1) << pond_diameter << " feet" << endl;
	cout << "Area:               " << pond_area << "square feet" << endl;
	cout << "Concrete Cost:      $" << setprecision(2) << pond_concrete_total << endl;
	cout << "Gallons of water:   " << setprecision(0) << volume_gallons << " (fills to the 11-foot mark)\n" << endl;
	cout << "DOME VALUES" << endl;
	cout << "-----------" << endl;
	cout << "Diameter:           " << setprecision(1) << dome_diameter << " feet" << endl;
	cout << "Area Under Dome:    " << dome_area_minus_pond << " square feet" << endl;
	cout << "Number of seats:    " << num_seats << " (to fill half of the available dome area)" << endl;
	cout << "Seat Install Cost:  " << setprecision(2) << install_cost << endl;

	cout << "\n\nThank you, " << customer_name << ", and let us know if you need any more help.\n"
		<< "It has been a pleasure serving you. \n" << endl;




	return 0;
}