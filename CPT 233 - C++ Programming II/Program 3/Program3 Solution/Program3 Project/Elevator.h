//FILE	:	Elevator.h
//PROG	:	Paige Peck
//PURP	:	Header for an elevator class

class Elevator
{
	//Data declarations
private:
	int numOnBoard;
	int maxCapacity;
	int currentFloor;
	int destFloor;
	int maxFloor;
	int minFloor;
	//int numOfLoad;	//Number of people loading or unloading

	//Methods declarations
public:
	Elevator(int, int, int, int);		//Prototype for the constructor
	int getNumOnBoard();
	int getMaxCapacity();
	int getCurrentFloor();
	int getDestFloor();
	int getMaxFloor();
	int getMinFloor();
	void loadElevator(int);
	void unLoadElevator(int);
	void moveElevator(int);


};

//Methods implementation
//This is the constructor
Elevator::Elevator(int board, int capacity, int min, int max)
{
	numOnBoard = board;
	maxCapacity = capacity;
	minFloor = min;
	maxFloor = max;
	currentFloor = 1;
}

int Elevator::getNumOnBoard()
{
	return numOnBoard;
}

int Elevator::getMaxCapacity()
{
	return maxCapacity;
}

int Elevator::getCurrentFloor()
{
	return currentFloor;
}

int Elevator::getDestFloor()
{
	return destFloor;
}

int Elevator::getMaxFloor()
{
	return maxFloor;
}

int Elevator::getMinFloor()
{
	return minFloor;
}

void Elevator::loadElevator(int numOfLoad)
{
	if((numOfLoad + numOnBoard) > maxCapacity)
	{
		cout << maxCapacity - numOnBoard << " out of the " << numOfLoad << " people have loaded." << endl;
		numOnBoard = maxCapacity;
	}
	else
	{
		cout << numOfLoad << " people are loading." << endl;
		numOnBoard += numOfLoad;
	}//END if

	cout << "There are " << numOnBoard << " people on board.\n" << endl;
}

void Elevator::unLoadElevator(int numOfLoad)
{
	if(numOfLoad > numOnBoard)
	{
		cout << numOnBoard << " people are unloading." << endl;
		numOnBoard = 0;
	}
	else
	{
		cout << numOfLoad << " people are unloading." << endl;
		numOnBoard -= numOfLoad;
	}//END if

	cout << "There are " << numOnBoard << " people on board.\n" << endl;
}

void Elevator::moveElevator(int requestedFloor)
{
	if(requestedFloor >= minFloor && requestedFloor <= maxFloor && requestedFloor != currentFloor)
	{
		destFloor = requestedFloor;

		if(destFloor > currentFloor)
		{
			cout << "Going up from " << currentFloor << endl;

			while(currentFloor < (destFloor - 1))
			{
				currentFloor++;
				cout << "Passing Floor " << currentFloor << endl;
			}//END while
			currentFloor++;
		}
		else
		{
			cout << "Going down from " << currentFloor << endl;
			
			while(currentFloor > (destFloor + 1))
			{
				currentFloor--;
				cout << "Passing floor " << currentFloor << endl;
			}//END while
			currentFloor--;
		}//END if
		cout << "\nMade it to floor " << currentFloor << endl;

	}
	else
		cout << "Can't go there!" << endl;
	//END if

}

//END OF CLASS Elevator