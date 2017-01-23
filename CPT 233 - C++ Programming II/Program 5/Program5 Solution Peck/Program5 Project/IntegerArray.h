// FILE : Integer.h
// PROG : Paige-David Peck
// PURP : Class for loading an integer array

//Libraries for C file streams
#include <fstream>
#include <string>
using namespace std;

class IntegerArray
{
	private:
		int records[100];
		int count;
		int totalCount;
		int average;
	public:
		IntegerArray();
		void loadArray();
		void displayArray();
		int calcAverage();
		int countBelowAvg();
		int findMaxInteger();
		int getCount();
		int getTotalCount();
		void displayOneRecord(int);
};

//Constructor
IntegerArray::IntegerArray()
{
	count = 0;

	loadArray();
}//END constructor

void IntegerArray::loadArray()
{
	ifstream recordsIn;

	recordsIn.open("program5.dat");
	if(recordsIn.is_open())
	{
		recordsIn >> records[count];

		while(!recordsIn.eof())
		{
			count++;

			recordsIn >> records[count];
		}//END while

		totalCount = count;

		recordsIn.close();
	}//END if file opened
	else
	{
		count = -1;
		cout << "File failed to open.";
	}

}//END loadArray

void IntegerArray::displayArray()
{
	count = 0;
	while(count < totalCount)
	{
		cout << "Record #" << count + 1 << " = " << records[count] << endl;
		count++;
	}//END while

}//END displayArray

int IntegerArray::calcAverage()
{
	average = 0;
	count = 0;

	while(count < totalCount)
	{
		average += records[count];
		count++;
	}//END while
	
	//cout << "Count = " << count << endl;

	average /= count;

	return average;

}//END calcAverage

int IntegerArray::countBelowAvg()
{
	int elementsBelow = 0;
	count = 0;

	while(count < totalCount)
	{
		if(records[count] < average)
		{
			elementsBelow++;
		}//END if

		count++;
	}//END while

	return elementsBelow;

}//END countBelowAvg

int IntegerArray::findMaxInteger()
{
	count = 0;
	int maxInteger = records[count];

	while(count < totalCount)
	{
		if(maxInteger < records[count])
		{
			maxInteger = records[count];
		}//END if

		count++;

	}//END while

	return maxInteger;
}//END findMaxInteger

int IntegerArray::getCount()
{
	return count;
}//END getCount

int IntegerArray::getTotalCount()
{
	return totalCount;
}//END getTotalCount

void IntegerArray::displayOneRecord(int index)
{
	cout << "Record #" << index+1 << " = " << records[index] << endl;
}//END displayOneRecord