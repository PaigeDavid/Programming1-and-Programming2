// FILE : InventoryData.cpp
// PROG : Paige-David Peck
// PURP : Class for searching through an array to find the price of a part in an inventory
//			using two seperate kinds of searches: sequential and binary

#include <iostream>
using namespace std;
#include "InventoryData.h"

int main()
{
	InventoryData inventory;
	int count, target, index;

	count = inventory.getCount();
	if(count == -1 )
	{
		cout << "\nERROR! File didn't open. Ending program." << endl;
	}
	else
	{
		cout << "Welcome to Inventory Data Searcher 5000. \nProgrammed by Peck Inc\n" << endl;

		cout << "Please enter the number to be compared(-1 to quit): " << endl;
		cin >> target;

		while(target > -1)
		{
			index = inventory.seqSearch(target);
			if(index > -1)
			{
				cout	<< "Sequential found part number " << inventory.getPartNum(index) << " and its price is $" 
						<< inventory.getPriceNum(index) << "\n" << endl;
			}//END if

			index = inventory.binSearch(target);
			if(index > -1)
			{
				cout	<< "Binary found part number " << inventory.getPartNum(index) << " and its price is $" 
						<< inventory.getPriceNum(index) << "\n\n" << endl;
			}//END if

			cout << "Please enter the number to be compared(-1 to quit): " << endl;
			cin >> target;
		}//END while

		cout << "\nThank you for using our program, we hope you enjoyed it"
			<< "\nand will continue using Peck Inc programs in the future.\n" << endl;

	}//END if

	return 0;
}//END main