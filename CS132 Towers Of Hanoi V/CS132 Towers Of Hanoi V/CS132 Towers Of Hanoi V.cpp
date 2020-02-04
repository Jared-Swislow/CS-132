//Jared Swislow
//CS 132 Program 5: Towers of Hanoi with stack exception handling, copy constructors, and assignment and equality overloading

#include <iostream>
#include <cassert>
#include <string> //Included so I can directly cout strings on my home computer. Removable in newer versions of VS
#include "Peg.h"

using namespace std;

const int NUM_OF_DISKS = 7;

void moveDisk(Peg& peg1, Peg& peg2, int& amountOfMoves);
void hanoi(Peg& startPeg, Peg& goalPeg, Peg& tempPeg, int amountOfDisks, int& amountOfMoves);

int main()
{
	//Cliff's test code
	
	{
		// Read Top Element / Pop from an empty stack - catch the exceptions
		Stack stack0;
		try
		{
			stack0.getTop();
		}
		catch (exception &e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		}/*
		try
		{
			stack0.pop();
		}
		catch (exception &e)
		{
			cerr << "Caught: " << e.what() << endl;
			cerr << "Type: " << typeid(e).name() << endl;
		}

		Stack stack1(stack0); // test initialization with an empty stack
		stack1.push(1); stack1.push(2); stack1.push(3); stack1.push(4);
		cout << boolalpha << "stack1: " << stack1 << ", equal to stack1? " << (stack1 == stack1) << endl;
		stack1 = stack1; // Test the = operator on self
		cout << "stack1: " << stack1 << endl;

		{ // Test the copy constructor
			Stack stack2(stack1); cout << "stack2: " << stack2 << ", equal to stack1? " << (stack1 == stack2) <<
			endl;
		} // Test the stack2 destructor

		{ // Test the = operator
			Stack stack3;
			stack3.push(10); stack3.push(11);
			cout << "stack3: " << stack3 << ", equal to stack1? " << (stack1 == stack3) << endl;
			stack3 = stack1;
			cout << "stack3: " << stack3 << ", equal to stack1? " << (stack1 == stack3) << endl;
		} // Test the stack3 destructor

		cout << "stack1: " << stack1 << endl; // Has stack 1 changed?*/
	}

	Peg peg1("Peg 1", NUM_OF_DISKS);
	Peg peg2("Peg 2", 0);
	Peg peg3("Peg 3", 0);

	int amountOfMoves = 0;

	cout << "Jared Swislow's Program 5: Towers of Hanoi with stack exception handling, copy constructors, and assignment and equality overloading" << endl << endl;

	cout << peg1 << peg2 << peg3;

	cout << endl << "Moves taken to move " << NUM_OF_DISKS << " pegs from peg1 to peg3:" << endl;
	hanoi(peg1, peg3, peg2, NUM_OF_DISKS, amountOfMoves);

	cout << endl;

	cout << peg1 << peg2 << peg3;

	cout << "Moving " << NUM_OF_DISKS << " pegs took " << amountOfMoves << " moves." << endl;
	system("pause");
	return 0;
}

void moveDisk(Peg& peg1, Peg& peg2, int& amountOfMoves) {
	//Make sure there is a disk to be moved
	assert(!(peg1.getNumDisks() == 0));

	//If the second peg isn't empty, make sure that the moving disk is larger than the top disk on the second peg, as per the rules
	if ((!peg2.getNumDisks() == 0)) {
		assert(peg2.topDisk() > peg1.topDisk());
	}

	peg2.addDisk(peg1.topDisk());
	peg1.removeTop();
	cout << "Moved disk " << peg2.topDisk() << " from " << peg1.getName() << " to " << peg2.getName() << endl;
	amountOfMoves++;
}

void hanoi(Peg& startPeg, Peg& goalPeg, Peg& tempPeg, int amountOfDisks, int& amountOfMoves) {
	//Move all but one peg to tempPeg
	if (amountOfDisks > 1) {
		hanoi(startPeg, tempPeg, goalPeg, amountOfDisks - 1, amountOfMoves);
	}

	//Move leftover disk to goalPeg
	moveDisk(startPeg, goalPeg, amountOfMoves);

	//Move all of tempPeg onto goalPeg
	if (amountOfDisks > 1) {
		hanoi(tempPeg, goalPeg, startPeg, amountOfDisks - 1, amountOfMoves);
	}
}
