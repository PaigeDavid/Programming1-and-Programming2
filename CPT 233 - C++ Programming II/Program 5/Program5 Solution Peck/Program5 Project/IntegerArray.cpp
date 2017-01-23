//FILE : IntegerArray.cpp
//PROG : Paige-David Peck
//PURP : Loading an integer array

#include <iostream>
using namespace std;
#include "IntegerArray.h"

int main()
{
	IntegerArray records;
	int count;

	count = records.getCount();
	if(count == -1 )
	{
		cout << "\nERROR! File didn't open. Ending program." << endl;
	}
	else
	{
		records.displayArray();

		cout << "\nAverage = " << records.calcAverage() << endl;
		cout << "# of Elements below average = " << records.countBelowAvg() << endl;
		cout << "Max integer in records = " << records.findMaxInteger() << endl;
	}//END if



	return 0;
}