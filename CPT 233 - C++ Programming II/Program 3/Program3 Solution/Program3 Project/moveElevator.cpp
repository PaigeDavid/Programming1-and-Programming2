//FILE	:	moveElevator.cpp
//PROG	:	Paige Peck
//PURP	:	Simple elevator simulator

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Elevator.h"

void loading(Elevator &, int, int, int);

int main()
{
	//Declarations
	//Creating one instance of an Elevator
	Elevator myElevator(0, 18, 1, 99);
	
	/*
	myElevator.loadElevator(5);
	//Trip 1
	loading(myElevator, 8, 6, 12); // Number order - Enter Destination floor, passengers loading, passengers unloading
	system("pause");
	system("cls");
	//Trip 2
	loading(myElevator, 3, 5, 20);
	system("pause");
	system("cls");
	//Trip 3
	loading(myElevator, 100, 10, 7);
	system("pause");
	system("cls");
	//Trip 4
	loading(myElevator, 10, 12, 18);
	system("pause");
	system("cls");
	//Trip 5
	loading(myElevator, 0, 5, 3);
	*/

	myElevator.loadElevator(5);
	//Trip 1
	myElevator.moveElevator(8);
	myElevator.unLoadElevator(6);
	myElevator.loadElevator(2);
	system("pause");
	system("cls");
	//Trip 2
	myElevator.moveElevator(3);
	myElevator.unLoadElevator(5);
	myElevator.loadElevator(20);
	system("pause");
	system("cls");
	//Trip test
	myElevator.moveElevator(100);
	system("pause");
	system("cls");
	//Trip 3
	myElevator.moveElevator(12);
	myElevator.unLoadElevator(10);
	myElevator.loadElevator(7);
	system("pause");
	system("cls");
	//Trip 4
	myElevator.moveElevator(10);
	myElevator.unLoadElevator(12);
	myElevator.loadElevator(18);
	system("pause");
	system("cls");
	//Trip test
	myElevator.moveElevator(0);
	system("pause");
	system("cls");
	//Trip 5
	myElevator.moveElevator(4);
	myElevator.unLoadElevator(5);
	myElevator.loadElevator(3);
	
	

	return 0;
}

void loading(Elevator &thisElevator, int floor, int load, int unload)
{
	
	int destFloor, maxFloor, minFloor, currentFloor;

	currentFloor = thisElevator.getCurrentFloor();

	thisElevator.moveElevator(floor);	

	destFloor = thisElevator.getDestFloor();
	maxFloor = thisElevator.getMaxFloor();
	minFloor = thisElevator.getMinFloor();
	

	//cout << currentFloor << " " << destFloor << " " << maxFloor << " " << minFloor << " " << floor << endl;

	if(destFloor >= minFloor && destFloor <= maxFloor && destFloor != currentFloor)
	{
		thisElevator.unLoadElevator(load);
		thisElevator.loadElevator(unload);
	}//END if

}