/************************************************************************************************
* FILENAME		: ticketSales2.0.cpp                                                            *
* PROGRAMMER	: Paige-David Peck                                                              *
* PURPOSE		: Calculates and displays the ticket sales for the Summerville Seaworld         *
************************************************************************************************/

#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 
//#include <ctime>

using namespace std;


//FUNCTION PROTOTYPES
char get_ticket_type(double, double);

double find_ticket_price(char, int, double, double);

double apply_discount(double, double, char);

void disp_purchase(int, double, string, string);

void disp_final_report(int, int, int, int, int, int, double);


//START main
int main()
{
	//Declare variables
	string user_name;
	string ticket_name;

	const int MAX_SEAT_COUNT = 15;
	const double JUNIOR_TICKET_COST = 7.50;
	const double ADULT_TICKET_COST = 11.50;
	const double DISCOUNT = .25;

	char ticket_choice;
	//char tmpbuf[128];
	//_strdate_s ( tmpbuf ); //store date in tmpbuf

	double single_tickets_cost = 0.0, total_dollar_sales = 0.0;

	int single_tickets_sold, extra_tickets = 0, total_toddler_tickets = 0, 
		total_junior_tickets = 0, total_adult_tickets = 0, total_tickets_sold = 0;

	cout << fixed;
	

	//Intro output
	cout	<< setw(50) << "PECK CODING UNLIMITED\n";
	cout	<< setw(57) << "Summerville Seaworld Ticket Seller\n" << endl;

	//Input statements
	cout << "Please enter login name: " << endl;
	getline (cin, user_name);

	system("cls");
	cout	<< setw(50) << "PECK CODING UNLIMITED\n";
	cout	<< setw(57) << "Summerville Seaworld Ticket Seller\n" << endl;
	cout	<< "Welcome, " << user_name << "." << endl;

	ticket_choice = get_ticket_type(JUNIOR_TICKET_COST, ADULT_TICKET_COST);
	//cout << "Ticket choice: " << ticket_choice << endl; //test

	//while loop for ending full loop
	while( ticket_choice != 'Q' && total_tickets_sold  < MAX_SEAT_COUNT )
	{
		
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
		//END if

		single_tickets_cost = find_ticket_price(ticket_choice, single_tickets_sold, JUNIOR_TICKET_COST, ADULT_TICKET_COST);
		
		if( ticket_choice == 'T' )
		{
			total_toddler_tickets += single_tickets_sold;
			ticket_name = "toddler";
		}
		else if( ticket_choice == 'J' )
		{
			total_junior_tickets += single_tickets_sold;
			ticket_name = "junior";
		}
		else if( ticket_choice == 'A' )
		{
			total_adult_tickets += single_tickets_sold;
			ticket_name = "adult";
		}
		//END if

		single_tickets_cost = apply_discount(single_tickets_cost, DISCOUNT, ticket_choice);

		disp_purchase(single_tickets_sold, single_tickets_cost, ticket_name, user_name);
		system("cls");
			
		cout	<< setw(50) << "PECK CODING UNLIMITED\n";
		cout	<< setw(57) << "Summerville Seaworld Ticket Seller\n" << endl;
		cout	<< "Logged in: " << user_name << "." << endl;

		total_dollar_sales += single_tickets_cost;
		total_tickets_sold += single_tickets_sold;

		if( total_tickets_sold  < MAX_SEAT_COUNT )
		{
		ticket_choice = get_ticket_type(JUNIOR_TICKET_COST, ADULT_TICKET_COST);
		//cout << "Ticket choice: " << ticket_choice << endl; //test
		}
		//END if

	}//END while

	if ( ticket_choice == 'Q' )
	{
		system("cls");

		cout	<< setw(50) << "PECK CODING UNLIMITED\n";
		cout	<< setw(57) << "Summerville Seaworld Ticket Seller\n" << endl;
		cout	<< "Logged in: " << user_name << "." << endl;
	}
	//END if

	if ( total_tickets_sold > MAX_SEAT_COUNT )
		extra_tickets = total_tickets_sold - MAX_SEAT_COUNT;


	disp_final_report(MAX_SEAT_COUNT, extra_tickets, total_tickets_sold, total_toddler_tickets,
						total_junior_tickets, total_adult_tickets, total_dollar_sales);

	return 0;
}//END main

//START get_ticket_type
char get_ticket_type(double JUNIOR_TICKET_COST, double ADULT_TICKET_COST)
{
	char ticket_choice;

	//MENU

	//cout << "MENU t, j, a, q" << endl;
	cout << setprecision(2);

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

	//while loop for proper input
	while( ticket_choice != 'T' && ticket_choice != 'J'  && ticket_choice != 'A' && ticket_choice != 'Q' )
	{
		//ERROR MESSAGE
		cout << "ERROR! Please re-enter ticket choice: " << endl;
		cin >> ticket_choice;
		ticket_choice = toupper(ticket_choice);
		//cout << "Ticket choice test: " << ticket_choice << endl; //test
	}
	//END while

	return ticket_choice;
}//END get_ticket_type


//START find_ticket_price
double find_ticket_price(char ticket_choice, int single_tickets_sold, double JUNIOR_TICKET_COST, double ADULT_TICKET_COST)
{
	double single_tickets_cost;

	//If statements for ticket choices
	//DISPLAY TICKET CHOICE
	if( ticket_choice == 'T' )
	{
		single_tickets_cost = 0;

	}
	else if( ticket_choice == 'J' )
	{
		single_tickets_cost = JUNIOR_TICKET_COST * single_tickets_sold;
		
	}
	else if( ticket_choice == 'A' )
	{
		single_tickets_cost = ADULT_TICKET_COST * single_tickets_sold;
		
	}
	//END IF

	return single_tickets_cost;
}//END find_ticket_price

//START apply_discount
double apply_discount(double single_tickets_cost, double DISCOUNT, char ticket_choice)
{
	char coupon;

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
			single_tickets_cost = single_tickets_cost - (DISCOUNT * single_tickets_cost);

	}
	//END if

	//cout << "Single transaction cost (discount test): " << setprecision(2) << single_tickets_cost << endl; //test

	return single_tickets_cost;
}//END apply_discount


//START disp_purchase
void disp_purchase(int single_tickets_sold, double single_tickets_cost, string ticket_name, string user_name)
{
	system("cls");
	cout	<< setw(50) << "PECK CODING UNLIMITED\n";
	cout	<< setw(57) << "Summerville Seaworld Ticket Seller\n" << endl;
	cout	<< "Logged in: " << user_name << ".\n" << endl;

	//END OF TRANSACTION REPORT
	cout << setw(40) << "Transaction totals for " << ticket_name << " tickets:\n" << endl;
	cout << "Transaction tickets: " << setw(25) << "Transaction cost: " << endl;
	cout << setw(20) << single_tickets_sold << setw(20) << setprecision(2) << single_tickets_cost << "\n\n" <<endl;
	cout << setprecision(0);

	system("pause");
	
}//END disp_purchase


//START disp_final_report
void disp_final_report(int MAX_SEAT_COUNT, int extra_tickets, int total_tickets_sold, int total_toddler_tickets,
						int total_junior_tickets, int total_adult_tickets, double total_dollar_sales)
{
	//cout << setw(50) << "TICKET SALES REPORT FOR DATE: " << tmpbuf << "\n\n\n" << endl;
	cout << "\n\n\n\n";
	cout << setw(20) << "SEAT CAPACITY" << setw(15) << "EXTRAS" << setw(20) << "TOTAL SOLD" << endl;
	cout << setw(15) << MAX_SEAT_COUNT << setw(18) << extra_tickets << setw(18) << total_tickets_sold << "\n" << endl;
	cout << setw(17) << "TODDLERS" << setw(18) << "JUNIORS" << setw(18) << "ADULTS" << endl;
	cout << setw(15) << total_toddler_tickets << setw(18) << total_junior_tickets << setw(18) << total_adult_tickets << "\n" << endl;
	cout << setprecision(2) << endl;
	cout << "GROSS  FOR TODAY: $" << total_dollar_sales << "\n\n" << endl;

}//END disp_final_report
