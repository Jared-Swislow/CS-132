//Jared Swislow
//CS 132 Program 4: Towers of Hanoi with  operator overloading for <<

#include "stdafx.h" //Dependancy for home computer
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
	Peg peg1("Peg 1", NUM_OF_DISKS);
	Peg peg2("Peg 2", 0);
	Peg peg3("Peg 3", 0);

	int amountOfMoves = 0;

	cout << "Jared Swislow's Program 4: Towers Of Hanoi with operator overloading for <<" << endl << endl;

	cout << peg1 << peg2 << peg3;

	cout << endl << "Moves taken to move " << NUM_OF_DISKS << " pegs from peg1 to peg3:" << endl;
	hanoi(peg1, peg3, peg2, NUM_OF_DISKS, amountOfMoves);

	cout << endl;

	cout << peg1 << peg2 << peg3;
	/*peg1.printPeg();
	peg2.printPeg();
	peg3.printPeg();*/
	cout << "Moving " << NUM_OF_DISKS << " pegs took " << amountOfMoves << " moves." << endl;

	//Cliff's test code
	{
		const Node cliffNode(123, (Node*)0x45678);
		Stack cliffStack; cliffStack.push(123); cliffStack.push(-456); cliffStack.push(789); const Stack cliffStack2;
		const Peg cliffPeg("Cliff Peg", 3);
		cout << cliffNode << cliffStack << cliffStack2 << cliffPeg << endl;
	}
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
	cout << peg2;
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