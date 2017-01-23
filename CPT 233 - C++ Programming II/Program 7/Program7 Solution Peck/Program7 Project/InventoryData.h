// FILE : InventoryData.h
// PROG : Paige-David Peck
// PURP : Class for searching through an array, after sorting it, to find the price of a part in an inventory
//			using two seperate kinds of searches: sequential and binary

#include <fstream>
#include <string>
using namespace std;

class InventoryData
{

private:
	int idNum[200];
	double price[200];
	int count;
	int bigO;

public:
	InventoryData();
	void loadArray();
	int seqSearch(int);
	int binSearch(int);
	int getCount();
	int getPartNum(int);
	double getPriceNum(int);
	int getBigO();
	void bubbleSort();
};

//Constructor
InventoryData::InventoryData()
{
	count = 0;

	loadArray();
	bubbleSort();
}//END constructor

void InventoryData::loadArray()
{
	ifstream recordsIn;

	recordsIn.open("masterInventory.dat");
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
	bigO = 0;

	while(ind < count)
	{
		if(target == idNum[ind])
		{
			found = ind;
			ind = count;
		}
		else
		{
			++ind;
		}//END if

		bigO++;

	}//END while

	if(found == -1)
	{
		cout	<< "\nThe sequential search took " << bigO 
				<< " comparisons \nuntil it determined the number wasn't there.\n" << endl;
	}
	else
	{
		cout	<< "\nThe sequential search took " << bigO 
				<< " comparisons \nto find the number's location.\n" << endl;
	}//END if

	return found;
}//END seqSearch

int InventoryData::binSearch(int target)
{
	int mid, first = 0, last = count, found = 0;
	bigO = 0;

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

		bigO++;

	}//END while

	if(found == 0)
	{
		mid = -1;
	}//END if

	if(found == 0)
	{
		cout	<< "\nThe binary search took " << bigO 
				<< " comparisons \nuntil it determined the number wasn't there.\n" << endl;
	}
	else
	{
		cout	<< "\nThe binary search took " << bigO 
				<< " comparisons to find the location.\n" << endl;
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

int InventoryData::getBigO()
{
	return bigO;
}//END getBigO

void InventoryData::bubbleSort()
{
	int ind, swap, temp;
	double tempPrice;
	int last = count - 1;
	

	while(last > 0)
	{
		ind = 0;
		swap = 0;

		while(ind < last)
		{
			if(idNum[ind] > idNum[ind + 1])
			{
				//SWAP ELEMENTS FOR idNum
				temp = idNum[ind];
				idNum[ind] = idNum[ind + 1];
				idNum[ind + 1] = temp;

				//SWAP ELEMENTS FOR price
				tempPrice = price[ind];
				price[ind] = price[ind + 1];
				price[ind + 1] = tempPrice;

				//a swap has occured, initialize swap to 1
				swap = 1;
			}
			else
			{
				++ind;
			}//END IF
		}//END WHILE

		if(swap == 0)
		{
			last = 0;
		}
		else
		{
			last = last - 1;
		}//END IF

	
	}//END WHILE
}//END bubbleSort
