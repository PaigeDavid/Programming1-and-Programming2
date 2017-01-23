// FILE : InventoryData.h
// PROG : Paige-David Peck
// PURP : Class for searching through an array to find the price of a part in an inventory
//			using two seperate kinds of searches: sequential and binary

#include <fstream>
#include <string>
using namespace std;

class InventoryData
{

private:
	int idNum[200];
	double price[200];
	int totalCount;
	int count;

public:
	InventoryData();
	void loadArray();
	int seqSearch(int);
	int binSearch(int);
	int getCount();
	int getPartNum(int);
	double getPriceNum(int);
	int getTotalCount();
	int getBigO();

};

//Constructor
InventoryData::InventoryData()
{
	count = 0;

	loadArray();
}//END constructor

void InventoryData::loadArray()
{
	ifstream recordsIn;

	recordsIn.open("inventoryPricing.dat");
	if(recordsIn.is_open())
	{
		
		recordsIn >> idNum[count]; 
		recordsIn >> price[count];
		
		while(!recordsIn.eof())
		{
			count++;

			recordsIn >> idNum[count];
			recordsIn >> price[count];

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

int InventoryData::seqSearch(int target)
{
	int ind = 0, found = -1;

	while(ind < totalCount)
	{
		if(target == idNum[ind])
		{
			found = ind;
			ind = totalCount;
		}
		else
		{
			++ind;
		}//END if

	}//END while

	return found;
}//END seqSearch

int InventoryData::binSearch(int target)
{
	int mid, first = 0, last = totalCount, found = 0;

	while(first <= last && found == 0)
	{
		mid = (first + last)/2;

		if(idNum[mid] == target)
		{
			found = 1;
		}
		else
		{
			if(idNum[mid] < target)
			{
				first = mid + 1;
			}
			else
			{
				last = mid - 1;
			}//END if
		}//END if

	}//END while

	if(found == 0)
	{
		mid = -1;
	}//END if

	return mid;
}//END binSearch

int InventoryData::getCount()
{
	return count;
}//END getCount

int InventoryData::getPartNum(int index)
{
	return idNum[index];
}//END getArray

double InventoryData::getPriceNum(int index)
{
	return price[index];
}//END getPriceNum

int InventoryData::getTotalCount()
{
	return totalCount;
}//END getTotalCount

int InventoryData::getBigO()
{
	return bigO;
}//END getBigO