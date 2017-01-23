//FILE : ferryBoat.h
//PROG : Paige Peck
//PURP : C++ class for ferry boat simulator


#include <ctime>					//Used to seed the random # generator

class FerryBoat
{

private:
	int maxCapacity;				//Max capacity of boat for cars
	int carsOnBoard;				//Number of cars on board
	int portA;						//Number of cars at portA
	int portB;						//Number of cars at portB
	char currentPort;				//Current port boat is docked at
	char destPort;					//Destination port


public:
	FerryBoat(int, char);						//Constructor
	int genRandNumberFromRange(int, int);		//random number generator from specific range
	int getPortA();								//return portA
	int getPortB();								//return portB
	int getCarsOnBoard();						//return carsOnBoard
	int getMaxCapacity();						//return maxCapacity
	char getCurrentPort();						//return currentPort
	char getDestPort();							//return destPort

	void moveToPort(char);						//move boat to port
	void loadCars();							//load cars on boat while updating port numbers
	void unloadCars();							//unload cars
	void setCurrentPort(char);					//sets current port
	void setDestPort(char);						//sets destination port

};
FerryBoat::FerryBoat(int maxCars, char start)
{
	maxCapacity = maxCars;
	currentPort = start;

	carsOnBoard = 0;

	srand ((unsigned)time(NULL));

	portA = genRandNumberFromRange(75, 100);
	portB = genRandNumberFromRange(100, 150);

}//END constructor

int FerryBoat::genRandNumberFromRange(int minNum, int maxNum)
{
	maxNum+=1;

	return (rand() % (maxNum - minNum) + minNum); //returns random number from a max and min number
}//END genRandNumberFromRange

void FerryBoat::moveToPort(char nextPort)
{
	//Update the instance variable
	destPort = nextPort;
	
	cout << "Leaving port " << currentPort << " for port "
		 << destPort << " with "
		 << carsOnBoard  << " pax.\n";

	//Now update curntPort to the destination, meaning we made it
	currentPort = destPort;
}//END moveToPort

void FerryBoat::loadCars()
{
	if(currentPort == 'A')
	{
		if(portA >= maxCapacity) //If the cars left at portA are over max, load max cars and update portA
		{
			cout << maxCapacity << " out of the " << portA << " cars have boarded." << endl;
			portA -= maxCapacity;
			carsOnBoard = maxCapacity;
		}
		else //If cars are below max, load all cars left and update portA to 0
		{
			cout << portA << " out of the " << portA << " cars have boarded." << endl;
			carsOnBoard = portA;
			portA = 0;
			
		}//END if
	}
	else
	{
		if(portB >= maxCapacity) //If the cars left at portB are over max, load max cars and update portA
		{
			cout << maxCapacity << " out of the " << portB << " cars have boarded." << endl;
			portB -= maxCapacity;
			carsOnBoard = maxCapacity;
		}
		else //If cars are below max, load all cars left and update portB to 0
		{
			cout << portB << " out of the " << portB << " cars have boarded." << endl;
			carsOnBoard = portB;
			portB = 0;			
		}//END if
	}//END if

	cout << "There are " << carsOnBoard << " cars on board.\n" << endl;
}//END loadCars

void FerryBoat::unloadCars()
{
	cout << carsOnBoard << " cars are unloading." << endl;
	carsOnBoard = 0;

}//END unloadCars

int FerryBoat::getPortA()
{
	return portA;
}//END getPortA

int FerryBoat::getPortB()
{
	return portB;
}//END getPortB

int FerryBoat::getCarsOnBoard()
{
	return carsOnBoard;
}//END getCarsOnBoard

int FerryBoat::getMaxCapacity()
{
	return maxCapacity;
}//END getMaxCapacity

char FerryBoat::getDestPort()
{
	return destPort;
}//END getDestPort

char FerryBoat::getCurrentPort()
{
	return currentPort;
}//END getCurrentPort

void FerryBoat::setCurrentPort(char current)
{
	currentPort = current;
}//END setCurrentPort

void FerryBoat::setDestPort(char destination)
{
	destPort = destination;
}//END setDestPort