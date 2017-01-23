// FILE : OrdersProcessed.h
// PROG : Paige-David Peck
// PURP : Class to open an output file for storing orders and calculating the total cost of all valid orders

#include <fstream>
#include <string>
using namespace std;

class OrdersProcessed
{
private:
	ofstream recordsOut;
	ifstream recordsIn;
	int fileOpenSuccess;
	void openFile(string);

public:
	OrdersProcessed(string);
	int getFileStatus();
	void saveRecord(int, int, double);
	void closeFile();
	void displayOrders();
	double calcTotalCostOfOrders();
	
};

//Constructor
OrdersProcessed::OrdersProcessed(string file)
{
	openFile(file);
}//END constructor

void OrdersProcessed::openFile(string file)
{
	recordsOut.open(file);

	if(recordsOut.is_open())
	{
		fileOpenSuccess = 0;
	}
	else
	{
		fileOpenSuccess = -1;
	}//END if

}//END openFile

int OrdersProcessed::getFileStatus()
{
	return fileOpenSuccess;
}//END getFileStatus

void OrdersProcessed::saveRecord(int partNum, int amount, double totalCost)
{
	recordsOut << partNum << " ";
	recordsOut << amount << " ";
	recordsOut << totalCost << endl;

}//END saveRecord

void OrdersProcessed::closeFile()
{
	recordsOut.close();
}//END closeFile

void OrdersProcessed::displayOrders()
{
	int count = 1, part, quantity;
	
	double cost;

	recordsIn.open("ordersProcessed.dat");

	if(recordsIn.is_open())
	{
		
		recordsIn >> part;
		recordsIn >> quantity;
		recordsIn >> cost;

		while(!recordsIn.eof())
		{
			cout << "Line #" << setw(10) << "PartID#" << setw(19) << "Qty Ordered" << setw(11) << "Total" << endl;
			cout << count << setw(13) << part << setw(16) << quantity << setw(18) << setprecision(2) << cost << endl;

			count++;

			recordsIn >> part;
			recordsIn >> quantity;
			recordsIn >> cost;

		}//END while

		recordsIn.close();
	}
	else
	{
		cout << "File failed to open.";
	}//END if

}//END displayOrders

double OrdersProcessed::calcTotalCostOfOrders()
{
	double cost = 0, totalCost = 0;

	int part, quantity;

	recordsIn.open("ordersProcessed.dat");
	if(recordsIn.is_open())
	{
		recordsIn >> part;
		recordsIn >> quantity;
		recordsIn >> cost;

		while(!recordsIn.eof())
		{
			totalCost += cost;

			recordsIn >> part;
			recordsIn >> quantity;
			recordsIn >> cost;

			
		}//END while

		recordsIn.close();

	}
	else
	{
		totalCost = -1;
		cout << "File failed to open.";
	}//END if


	return totalCost;
}//END calcTotalCostOfOrders