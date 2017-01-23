//FILE : Analyze SSW Daily Sales.cpp
//PROG : Paige-David Peck
//PURP : To read the data from the sales document and calculate the costs

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Function prototypes
string full_ticket_display(char);
string full_coupon_display(char);

double delta_calc(char, char, int, double, const double, const double, const double);
double coupon_loss(const double, const double);


int main()
{
	//Input file stream object to read the data file
	ifstream salesIn;

	//Declare variables
	string ticketDate, ticket_string, coupon_string;

	char ticketType, coupon;

	const double DISCOUNT = .25, JUNIOR_TICKET_COST = 7.5,
		ADULT_TICKET_COST = 11.5;

	int line_number = 0, ticketQty, total_adult_tickets = 0, 
		total_junior_tickets = 0, total_child_tickets = 0;

	double ticketCost, delta = 0.0, total_adult_cost = 0.0, total_junior_cost = 0.0,
		total_dollar_sales, total_delta = 0.0, total_coupon_loss = 0.0;

	
	//Any other variables you need are your responsibility to declare!

	//Set up the output specs
	cout << fixed << setprecision(2);
	
	//Open the data file
	salesIn.open("ssw-sales.dat");
	if (salesIn.is_open())
	{
		//Headers
		cout	<< setw(50) << "PECK CODING UNLIMITED\n";
		cout	<< setw(57) << "Summerville Seaworld Ticket Corrector\n\n" << endl;

		//Prime read:  read the first record of the data file
		salesIn		>>	ticketDate
					>>	ticketType
					>>	ticketQty
					>>	coupon
					>>	ticketCost;

		cout	<< setw(3) << "#" << setw(7) << "TYPE" << setw(8) << "QTY" << setw(10) 
				<< "COUPON" << setw(13) << "ACTUAL CHG" << setw(10) << "DELTA" << endl;

		cout	<< setw(3) << "-" << setw(7) << "----" << setw(8) << "---" << setw(10) 
				<< "------" << setw(13) << "----------" << setw(10) << "-----" << endl;

		//Begin the central record-processing while loop
		while (!salesIn.eof())
		{
			//Display the first and last field of each record for testing
			//purposes only.  If all fields appear OK on screen, then you 
			//should comment out this cout for later work
			//cout << ticketDate << setw(10) << ticketCost << endl;

			//Here is where you will need to do all your processing for each record
			//Everything you need to add, count, accumulate, display, etc
			//needs to be done here (or in other functions!).
			//When you get to the "Read the next record" code below,
			//the current record vanishes!

			line_number++;

			ticketType = toupper(ticketType);
			coupon = toupper(coupon);

			ticket_string = full_ticket_display(ticketType);
			coupon_string = full_coupon_display(coupon);
			delta = delta_calc(ticketType, coupon, ticketQty, ticketCost, ADULT_TICKET_COST, JUNIOR_TICKET_COST, DISCOUNT);

			cout << setw(3) << line_number << setw(8) << ticket_string << setw(6) << ticketQty;


			if(ticketType != 'C')
				cout << setw(10) << coupon_string << setw(14) << ticketCost <<  setw(10) << delta << endl;
			else
				cout << endl;
			//END if

			if(ticketType == 'A')
			{
				total_adult_tickets += ticketQty;
				total_adult_cost += ticketCost;
			}
			else if(ticketType == 'J')
			{
				total_junior_tickets += ticketQty;
				total_junior_cost += ticketCost;
			}
			else
			{
				total_child_tickets += ticketQty;
			}
			//END if

			total_delta += delta;


			//Read the next record (bottom of while loop)
			salesIn		>>	ticketDate
						>>	ticketType
						>>	ticketQty
						>>	coupon
						>>	ticketCost;
		} //END OF RECORD PROCESSING WHILE LOOP

		//Close the data file since we are done with it
		salesIn.close();

		//Display all totals next
		//You should comment out this cout and either display the totals here,
		//or better yet call a function to display the final report
		//cout << "\n\nEnd of test run.\n";

		cout << endl;

		system("pause");
		system("cls");

		cout	<< setw(50) << "PECK CODING UNLIMITED\n";
		cout	<< setw(57) << "Summerville Seaworld Ticket Corrector\n\n" << endl;

		total_dollar_sales = total_adult_cost + total_junior_cost;

		/*
		cout << " total adult cost, total junior cost, " << endl;
		cout << line_number << " " << total_adult_tickets << " " << total_adult_cost << " " 
			<< total_junior_tickets << " " << total_junior_cost << " " << total_child_tickets 
			<< " " << total_dollar_sales << " " << total_delta << endl;
		*/

		//EC
		total_coupon_loss = coupon_loss(JUNIOR_TICKET_COST, ADULT_TICKET_COST);

		cout << setw(20) << "TOTAL REPORTS" << setw(25) << "TOTAL DOLLAR SALES" << setw(20) << "TOTAL DELTA" << endl;
		cout << setw(15) << line_number << setw(18) << "$" << total_dollar_sales << setw(18) << "$" << total_delta << "\n" << endl;
		cout << setw(22) << "TOTAL ADULT TICKETS" << setw(25) << "TOTAL JUNIOR TICKETS" << setw(25) << "TOTAL CHILD TICKETS" << endl;
		cout << setw(15) << total_adult_tickets << setw(23) << total_junior_tickets << setw(24) << total_child_tickets << "\n" << endl;
		cout << setw(20) << "TOTAL ADULT COST" << setw(25) << "TOTAL JUNIOR COST" << setw(25) << "TOTAL COUPON LOSS" << endl;
		cout << setw(12) << "$" << total_adult_cost << setw(18) << "$" << total_junior_cost << setw(18) << "$" << total_coupon_loss << "\n\n" << endl;
		

		//cout << "TOTAL COUPON LOSS: $" << total_coupon_loss << "\n\n" << endl;
		

		

	}//END IF FILE OPENED

	else  //File did not open
		cout << "The sales file did not open!\n";

	return 0;
}//END MAIN

//Your other functions need to be defined here

/*******************************************************	*
 * PURPOSE	: Convert ticketType into a string for output	*
 * PASSED IN	: ticket type character						*
 * RETURNED: ticket type string								*
 ************************************************************/

string full_ticket_display(char ticketType)
{
	string ticket_string;

	if(ticketType == 'A')
		ticket_string = "Adult";
	else if(ticketType == 'J')
		ticket_string = "Junior";
	else
		ticket_string = "Child";
	//END if

	return ticket_string;
}//END full_ticket_display

/*******************************************************	*
 * PURPOSE	: Convert coupon into a string for output   	*
 * PASSED IN	: coupon character		    				*
 * RETURNED: coupon string									*
 ************************************************************/

string full_coupon_display(char coupon)
{
	string coupon_string;

	if(coupon == 'Y')
		coupon_string = "Yes";
	else
		coupon_string = "No";
	//END if

	return coupon_string;
}//END full_coupon_display

/***********************************************************************	*
 * PURPOSE	: Calculate delta, loss of money from ticket seller				*
 * PASSED IN	: ticket type character, coupon character, ticket quantity, *
				  ticket cost, cost of adult ticket, cost of junior ticket, *
				  discount percentage										*
 * RETURNED: delta, loss of money											*
 ****************************************************************************/

double delta_calc(char ticketType, char coupon, int ticketQty, double ticketCost, 
	const double ADULT_TICKET_COST, const double JUNIOR_TICKET_COST, const double DISCOUNT)
{
	double delta = 0.0, correct_ticket_cost;

	if(ticketType == 'A')
	{
		correct_ticket_cost = ticketQty * ADULT_TICKET_COST;

		if(coupon == 'Y')
		{
			correct_ticket_cost -= (correct_ticket_cost * DISCOUNT);
			delta = ticketCost - correct_ticket_cost;
		}
		else
			delta = ticketCost - correct_ticket_cost;
		//END if

	}
	else if(ticketType == 'J')
	{
		correct_ticket_cost = ticketQty * JUNIOR_TICKET_COST;

		if(coupon == 'Y')
		{
			correct_ticket_cost -= (correct_ticket_cost * DISCOUNT);
			delta = ticketCost - correct_ticket_cost;
		}
		else
			delta = ticketCost - correct_ticket_cost;
		//END if

	}
	//END if

	return delta;
}//END delta_calc

/***********************************************************	*
 * PURPOSE	: Calculates loss of money from coupon savings		*
 * PASSED IN	: cost of junior ticket, cost of adult ticket	*
 * RETURNED: total loss from coupons							*
 ************************************************************/

double coupon_loss(const double JUNIOR_TICKET_COST, const double ADULT_TICKET_COST)
{
	ifstream salesIn;

	string ticketDate;

	char ticketType, coupon;

	int ticketQty;

	double ticketCost;
	double total_coupon_loss = 0.0;
	double correct_ticket_cost;
	double total_savings;

	salesIn.open("ssw-sales.dat");
	if (salesIn.is_open())
	{
		salesIn		>>	ticketDate
					>>	ticketType
					>>	ticketQty
					>>	coupon
					>>	ticketCost;

		while (!salesIn.eof())
		{
			if(coupon == 'Y')
			{

				if(ticketType == 'A')
				{
					correct_ticket_cost = ticketQty * ADULT_TICKET_COST;
					total_savings = correct_ticket_cost - ticketCost;
					//cout << "Total savings adult: " << total_savings << endl; //test
				}
				else if(ticketType == 'J')
				{
					correct_ticket_cost = ticketQty * JUNIOR_TICKET_COST;
					total_savings = correct_ticket_cost - ticketCost;
					//cout << "Total savings junior: " << total_savings << endl; // test
				}
				//END if

				total_coupon_loss += total_savings;
				
			}
			//END if

			salesIn		>>	ticketDate
						>>	ticketType
						>>	ticketQty
						>>	coupon
						>>	ticketCost;
		}
		//END while

		salesIn.close();
	}
	else
		cout << "The sales file did not open!\n";

	//END if

	return total_coupon_loss;
}//END coupon_loss