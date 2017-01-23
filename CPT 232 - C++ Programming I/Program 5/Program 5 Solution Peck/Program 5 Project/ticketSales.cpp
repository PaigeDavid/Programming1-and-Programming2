/************************************************************************************************
* FILENAME		: ticketSales.cpp                                                               *
* PROGRAMMER	: Paige-David Peck                                                              *
* PURPOSE		: Calculates and displays the ticket sales for the Summerville Seaworld         *
************************************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 
#include <ctime>

using namespace std;

int main()
{

	//Declare variables
	string user_name;

	const int MAX_SEAT_COUNT = 15;
	const double JUNIOR_TICKET_COST = 7.50;
	const double ADULT_TICKET_COST = 11.50;
	const double DISCOUNT = .25;

	char coupon, ticket_choice;
	char tmpbuf[128];
	_strdate_s ( tmpbuf ); //store date in tmpbuf

	double single_tickets_cost = 0.0, total_dollar_sales = 0.0;

	int single_tickets_sold, extra_tickets = 0, total_toddler_tickets = 0, 
		total_junior_tickets = 0, total_adult_tickets = 0, total_tickets_sold = 0;


	//Intro output
	cout	<< setw(50) << "PECK CODING UNLIMITED\n";
	cout	<< setw(57) << "Summerville Seaworld Ticket Seller\n" << endl;

	//Input statements
	cout << "Please enter login name: " << endl;
	getline (cin, user_name);

	system("cls");
	cout	<< "\nWelcome, " << user_name << "." << endl;

	
	//MENU

	//cout << "MENU t, j, a, q" << endl;
	cout << fixed << setprecision(2);

	cout << "\n\nToddlers:5 and Under ('t')" << setw(29) << "Juniors:6 through 16 ('j')"
		<< setw(25) << "Adults:17 and Up ('a')";
	cout << setw(18) << "Free Admission" << setw(20) << "$" << JUNIOR_TICKET_COST << setw(23) << "$" 
		<< ADULT_TICKET_COST << endl;

	cout << setprecision(0);
	//END MENU

	//MENU CHOICE 
	cout << "\n\nPlease choose a ticket type ('q' to quit): ";
	cin >> ticket_choice;

	cout << "\n\n" << endl;
	ticket_choice = toupper( ticket_choice );
	//cout << "Ticket choice test: " << ticket_choice << endl; //test
	

	//while loop for ending full loop
	while( ticket_choice != 'Q' && total_tickets_sold  < MAX_SEAT_COUNT )
	{

		//while loop for proper input
		while( ticket_choice != 'T' && ticket_choice != 'J'  && ticket_choice != 'A' && ticket_choice != 'Q' )
		{
			//ERROR MESSAGE
			cout << "ERROR! Please re-enter ticket choice: " << endl;
			cin >> ticket_choice;
			ticket_choice = toupper(ticket_choice);
			//cout << "Ticket choice test: " << ticket_choice << endl; //test
		}
		//cout << "1st Loop exited test" << endl; //test
		//cout << "Ticket choice test: " << ticket_choice << endl; //test

		//ENTER TRANSACTION AMOUNT
		cout << "Enter amount to be purchased: " << endl;
		cin >> single_tickets_sold;

		if( single_tickets_sold > 10)
		{
			//ERROR MESSAGE
			cout << "ERROR! Only 10 tickets can be purchased per transaction." << endl;
			single_tickets_sold = 10;
			//cout << "Single tickets sold after reintialize test: " << single_tickets_sold << endl; //test
		}

		if( ticket_choice == 'T' )
		{
			//No coupons needed
		}
		else
		{
		//ENTER COUPON
		cout << "Do you have a coupon (y, n): " << endl;
		cin >> coupon;

		coupon = toupper(coupon);
		//cout << "Coupon test: " << coupon << endl; //test

		if( coupon == 'Y' )
			single_tickets_cost = single_tickets_sold - (DISCOUNT * single_tickets_sold);
		else
			single_tickets_cost = single_tickets_sold;

		}
		//cout << "Single transaction cost (discount test): " << single_tickets_cost << endl; //test

		system("cls");

		//If statements for ticket choices
		//DISPLAY TICKET CHOICE
		if( ticket_choice == 'T' )
		{
			total_toddler_tickets += single_tickets_sold;
			single_tickets_cost = 0;
			cout << "You are buying " << single_tickets_sold << " toddler tickets." << endl;
		}
		else if( ticket_choice == 'J' )
		{
			total_junior_tickets += single_tickets_sold;
			single_tickets_cost = JUNIOR_TICKET_COST * single_tickets_cost;
			cout << "You are buying " << single_tickets_sold << " junior tickets." << endl;
		}
		else if( ticket_choice == 'A' )
		{
			total_adult_tickets += single_tickets_sold;
			single_tickets_cost = ADULT_TICKET_COST * single_tickets_cost;
			cout << "You are buying " << single_tickets_sold << " adult tickets." << endl;
		}
		//END IF

		cout << "\n" << endl;

		//END OF TRANSACTION REPORT
		cout << setw(25) << "Transaction tickets: " << setw(25) << "Transaction cost: " << endl;
		cout << setw(20) << single_tickets_sold << setw(20) << setprecision(2) << single_tickets_cost << "\n\n" <<endl;
		cout << setprecision(0);

		total_dollar_sales += single_tickets_cost;
		total_tickets_sold += single_tickets_sold;

		system("pause");
		system("cls");


		//cout << "Total dollar sales: " << total_dollar_sales << "\nTotal tickets sold: " 
		//	<< total_tickets_sold << "\nMax Seat Count " << MAX_SEAT_COUNT << endl; //test

		if( total_tickets_sold  < MAX_SEAT_COUNT )
		{
			//MENU
			cout << fixed << setprecision(2);

			cout << "\n\nToddlers:5 and Under ('t')" << setw(29) << "Juniors:6 through 16 ('j')"
				<< setw(25) << "Adults:17 and Up ('a')";
			cout << setw(18) << "Free Admission" << setw(20) << "$" << JUNIOR_TICKET_COST << setw(23) << "$" 
				<< ADULT_TICKET_COST << endl;

			cout << setprecision(0);

			//END MENU

			//MENU CHOICE
			cout << "\n\nPlease choose a ticket type ('q' to quit): ";
			cin >> ticket_choice;

			cout << "\n\n" << endl;
			ticket_choice = toupper( ticket_choice );
			//cout << "Ticket choice test: " << ticket_choice << endl; //test
			//cout << "Total tickets sold test: " << total_tickets_sold << endl; //test
		}
		
	}
	//END WHILE

	//cout << "2nd loop exited test" << endl; //test

	if ( ticket_choice == 'Q' )
		system("cls");

	if ( total_tickets_sold > MAX_SEAT_COUNT )
		extra_tickets = total_tickets_sold - MAX_SEAT_COUNT;

	//cout << "Extra tickets test: " << extra_tickets << endl; //test

	cout << fixed;

	cout << setw(50) << "TICKET SALES REPORT FOR DATE: " << tmpbuf << "\n\n\n" << endl;
	cout << setw(20) << "SEAT CAPACITY" << setw(15) << "EXTRAS" << setw(20) << "TOTAL SOLD" << endl;
	cout << setw(15) << MAX_SEAT_COUNT << setw(18) << extra_tickets << setw(18) << total_tickets_sold << "\n" << endl;
	cout << setw(17) << "TODDLERS" << setw(18) << "JUNIORS" << setw(18) << "ADULTS" << endl;
	cout << setw(15) << total_toddler_tickets << setw(18) << total_junior_tickets << setw(18) << total_adult_tickets << "\n" << endl;
	cout << setprecision(2) << endl;
	cout << "GROSS  FOR TODAY: $" << total_dollar_sales << "\n\n" << endl;



	return 0;
}