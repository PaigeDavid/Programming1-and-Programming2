//FILE : CommuterTrain.cpp
//PROG : Paige Peck
//PURP : Simulation of a high speed railway train

#include <iostream>
#include <string>
using namespace std;
#include "commuterTrain.h"

int main()
{
	const int STATIONCOUNT = 30;
	//Make a train with 30 stops, 200 max pax, and starts at station #1
	CommuterTrain myTrain(STATIONCOUNT, 200, 1);

	//In this program I am only running the train to the next three stations from home.
	//A real train would have certainly need to take the stationCount variable into account!

	//First, we would need to call the loadPax method to load up some passengers.
	//But we can't actually do that here, since I didn't write the method!
	//Unfortunately, then, the train will roll empty, a complete waste of taxpayer money!

	myTrain.loadPeople();
	cout << "All aboard the Summerville Express Train!\n";
	for (int ct = 0; ct < STATIONCOUNT - 1; ++ct)
	{
		myTrain.moveToStation(myTrain.getCurrentStation() + 1);
		myTrain.unloadPeople();
		myTrain.loadPeople();
	}

	myTrain.moveToStation(1);
	myTrain.unloadPeople();

	//And now, just for "fun" let's ask the random number method for a
	//value between 0 and 1700
	//cout << "\n\nOne random number: " << myTrain.genRandNumber(1700) << endl;

	return 0;
}