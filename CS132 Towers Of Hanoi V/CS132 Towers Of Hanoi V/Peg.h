#pragma once

#include <iostream>
#include "Stack.h"

using namespace std;

class Peg
{
private:
	//Name of the peg
	string name;

	//Structure to hold the disks
	Stack stack;

	//Private method to load numDisks disks onto a Peg
	void loadDisks(int numDisks);

public:
	//Constructor
	Peg(string pegName, int numDisks);

	//Method to return the number of disks on the Peg
	unsigned int getNumDisks() const;

	//Methods to display what disks are on the peg
	//void printPeg() const;
	//void printPegReverse() const;

	//Accessor for the peg name
	string getName() const;

	//Method to return the value of the top disk
	int topDisk() const;

	//Methods to add and remove disks from the peg
	void addDisk(int diskValue);
	int removeTop();

	//Operator Overloading for <<
	friend ostream& operator <<(ostream& outStream, const Peg& peg);

	//Destructor
	~Peg();
};