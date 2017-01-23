//FILE : ferryBoat.cpp
//PROG : Paige Peck
//PURP : C++ class for ferry boat simulator

#include <iostream>
#include <string>
using namespace std;
#include "ferryBoat.h"

int main()
{
	FerryBoat myFerry(20, 'A');
	int portA, portB;

	portA = myFerry.getPortA();
	portB = myFerry.getPortB();

	myFerry.loadCars();

	while( (portA != 0) || (portB != 0) )
	{
		myFerry.moveToPort('B');
		myFerry.unloadCars();
		myFerry.loadCars();
		myFerry.moveToPort('A');
		myFerry.unloadCars();
		myFerry.loadCars();

		portA = myFerry.getPortA();
		portB = myFerry.getPortB();
	}//END while

	cout << "Arrived at Port " << myFerry.getCurrentPort() << ". Final docking." << endl;

	return 0;
}//END main