#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Peg
{
private:
	//Name of the peg
	string name;

	//Structure to hold the disks
	vector<int> stack;

	//Private method to load numDisks disks onto a Peg
	void loadDisks(int numDisks);

public:
	//Constructor
	Peg(string pegName, int numDisks);

	//Method to return the number of disks on the Peg
	unsigned int getNumDisks() const;

	//Method to display what disks are on the peg
	void printPeg() const;

	//Accessor for the peg name
	string getName() const;

	//Method to return the value of the top disk
	int topDisk() const;

	//Methods to add and remove disks from the peg
	void addDisk(int diskValue);
	int removeTop();

	//Method to check if peg is empty
	bool isPegEmpty();

	//Method to cout the name of the peg (made to not #include <string> in the main file)
	void displayName();

	//Destructor
	~Peg();
};