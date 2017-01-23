// FILE : InventoryData.cpp
// PROG : Paige-David Peck
// PURP : Program for searching through an array to find the price of a part in an inventory
//			using two seperate kinds of searches: sequential and binary

#include <iostream>
#include <iomanip>
using namespace std;
#include "InventoryData.h"
#include "OrdersProcessed.h"

int main()
{
	InventoryData inventory;

	OrdersProcessed orders("ordersProcessed.dat");

	int count, target, index, partNum, amount,
		totalQueries = 0, validPartCount = 0, inValidPartCount = 0;

	double  price, totalCost, totalPartsCost;

	ofstream recordsOut;

	cout << fixed << setprecision(2);

	count = inventory.getCount();
	if(count == -1 )
	{
		cout << "\nERROR! File didn't open. Ending program." << endl;
	}
	else
	{
		count = orders.getFileStatus();
		if(count == 0)
		{
			cout << "Welcome to Inventory Data Sorting Searcher 6000. \nProgrammed by Peck Inc\n" << endl;

			cout << "Please enter the part number(-1 to quit): " << endl;
			cin >> target;

			while(target > -1)
			{
				/*index = inventory.seqSearch(target);
				if(index > -1)
				{
					cout	<< "Sequential found part number " << inventory.getPartNum(index) << " and its price is $" 
						<< inventory.getPriceNum(index) << "\n" << endl;
			
				
				}//END IF
			
				*/

				index = inventory.binSearch(target);
				if(index > -1)
				{
				/*	cout	<< "Binary found part number " << inventory.getPartNum(index) << " and its price is $" 
							<< inventory.getPriceNum(index) << "\n\n" << endl;
				*/
					cout << "Please enter the amount needed: " << endl;
					cin >> amount;
						
					partNum = inventory.getPartNum(index);
					price = inventory.getPriceNum(index);

					totalCost = price * amount;

					orders.saveRecord(partNum, amount, totalCost);

					cout << "PartID#" << setw(11) << "Price" << setw(19) << "Qty Ordered" << setw(11) << "Total" << endl;
					cout << partNum << setw(13) << price << setw(15) << setprecision(0) << amount << setw(15) 
						<< setprecision(2) << totalCost << endl;
						
					validPartCount++;
				}
				else
				{
					cout	<< "Invalid part number, please try again." << endl;
						
					inValidPartCount++;
				}//END IF

				totalQueries++;

				cout << "Please enter the part number(-1 to quit): " << endl;
				cin >> target;

				/*if(target > -1)
				{
					cout << "Please enter the amount needed: " << endl;
					cin >> amount;
				}//END iF */

			}//END while

			/*
			cout << "\nSome minor statistics:\n" << endl;
			cout << "Total number of searches: " << totalQueries << endl;
			cout << "Total number of valid parts found: " << validPartCount << endl;
			cout << "Total number of invalid parts found: " << inValidPartCount << endl;

			*/

			orders.closeFile();
			system("CLS");

			orders.displayOrders();

			totalPartsCost = orders.calcTotalCostOfOrders();

			if(totalPartsCost >= 0)
			{
				cout << "\nThe total cost of all parts ordered is: " << totalPartsCost << endl;
			}

			cout	<< "\nThank you for using our program, we hope you enjoyed it"
					<< "\nand will continue using Peck Inc programs in the future.\n" << endl;

			recordsOut.close();
		}
		else
		{
			cout << "\nERROR! File didn't open. Ending program." << endl;
		}//END if

	}//END if

	return 0;
}//END main