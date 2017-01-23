//FILE : commuterTrain.h
//PROG : Paige Peck
//PURP : C++ class for high speed railway train simulator

//#include <cstdlib>				//Rqd unless you use namespace std.
									//Contains random # library methods
#include <ctime>					//Used to seed the random # generator

class CommuterTrain
{
	private:
		int numStations;			//Number of stations serviced by this train
		int maxCapacity;			//Max capacity of entire train
		int currentStation;			//Number of the station the train is stopped at
		int peopleOnBoard;			//Number of pax on train
		int destStation;			//Number of the next station to stop at
		int numOfLoad;				//Random number of people wanting to load/unload

		//Private methods
		//None for this class, at least not yet!

	public:
		CommuterTrain(int, int, int);		//Passed in: #stations, max pax, start station
		int getCurrentStation();
		int genRandNumber(int);				//Generates a random int <= value passed in
		int getPeopleOnBoard();
		int getMaxCapacity();
		int getNumStations();
		int getDestStation();

		void moveToStation(int);			//Moves train to station # passed in
		void unloadPeople();
		void loadPeople();
		void setDestStation(int);			//Parameters in: Destination station
		void setCurrentStation(int);		//Parameters in: Current Station
};
CommuterTrain::CommuterTrain(int numStops, int maxPersons, int start)
{
	numStations = numStops;
	maxCapacity = maxPersons;
	currentStation = start;

	peopleOnBoard = 0;		//Can't have any pax yet if we just built it!

	//Seed the C library random number generator--you only do this one time.
	srand ((unsigned)time(NULL));
}//END constructor

int CommuterTrain::getCurrentStation()
{
	return currentStation;
}//END getCurntStation

//This method accepts a max number for a call to the C random number generator
//The value returned is in the range of 0 - maxNum
int CommuterTrain::genRandNumber(int maxNum)
{
	//Generate a random integer <= maxNum
	return (rand() % (maxNum + 1));
}//END genRandNumber

//Set destStation and "move" the train to it.
void CommuterTrain::moveToStation(int nextStation)
{
	//Update the instance variable
	destStation = nextStation;
	
	cout << "Leaving station " << currentStation << " for station "
		 << destStation << " with "
		 << peopleOnBoard  << " pax.\n";

	//Now update curntStation to the destination, meaning we made it
	currentStation = destStation;
}//END moveToStation

int CommuterTrain::getPeopleOnBoard()
{
	return peopleOnBoard;
}//END getPeopleOnBoard

int CommuterTrain::getMaxCapacity()
{
	return maxCapacity;
}//END getMaxCapacity

int CommuterTrain::getNumStations()
{
	return numStations;
}//END getNumStations

int CommuterTrain::getDestStation()
{
	return destStation;
}//END getDestStation

void CommuterTrain::unloadPeople()
{
	//Offload random # of people returned from genRandNumber, updates peopleOnBoard
	numOfLoad = genRandNumber(peopleOnBoard);

	cout << numOfLoad << " people are unloading." << endl;
	peopleOnBoard -= numOfLoad;

	cout << "There are " << peopleOnBoard << " people on baord." << endl;

}//END unloadPeople

void CommuterTrain::loadPeople()
{
	//load random # of people returned from genRandNumber, but only up to maxCapacity, updates peopleOnBoard
	numOfLoad = genRandNumber(350);

	if((numOfLoad + peopleOnBoard) > maxCapacity)
	{
		cout << maxCapacity - peopleOnBoard << " out of the " << numOfLoad << " people have boarded." << endl;
		peopleOnBoard = maxCapacity;
	}
	else
	{
		cout << numOfLoad << " people are boarding." << endl;
		peopleOnBoard += numOfLoad;
	}//END if

	cout << "There are " << peopleOnBoard << " people on board.\n" << endl;

}//END loadPeople

void CommuterTrain::setDestStation(int destination)
{
	destStation = destination;
}//END setDestStation

void CommuterTrain::setCurrentStation(int current)
{
	currentStation = current;
}//END setCurrentStation