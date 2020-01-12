//Jared Swislow
//CS 132 Program 1: Towers Of Hanoi

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

const int NUM_OF_DISKS = 7;

struct Peg {
	vector<int> peg;
	string name;
};

void addDisks(Peg& peg, int amountToAdd);
void displayPeg(Peg peg);
void display3Pegs(const Peg& peg1, const Peg& peg2, const Peg& peg3);
void moveDisk(Peg &peg1, Peg &peg2, int& amountOfMoves);
void hanoi(Peg &startPeg, Peg &goalPeg, Peg &tempPeg, int amountOfDisks, int& amountOfMoves);

int main()
{
	Peg peg1, peg2, peg3;
	int amountOfMoves = 0;
	peg1.name = "peg1";
	peg2.name = "peg2";
	peg3.name = "peg3";

	addDisks(peg1, NUM_OF_DISKS);

	display3Pegs(peg1, peg2, peg3);

	cout << "Moves taken to move " << NUM_OF_DISKS << " from peg1 to peg3:" << endl;
	hanoi(peg1, peg3, peg2, NUM_OF_DISKS, amountOfMoves);

	cout << endl;

	display3Pegs(peg1, peg2, peg3);
	cout << "Moving " << NUM_OF_DISKS << " pegs took " << amountOfMoves << " moves." << endl;
}

void addDisks(Peg& peg, int amountToAdd) {
	for (int i = amountToAdd; i > 0; i--) {
		peg.peg.push_back(i);
	}
}

void displayPeg(Peg peg) {
	cout << "Peg " << peg.name << ": ";
	for (int i = 0; i < static_cast<int>(peg.peg.size()); i++) {
		cout << peg.peg[i];
	}
	cout << endl;
}

void display3Pegs(const Peg& peg1, const Peg& peg2, const Peg& peg3) {
	displayPeg(peg1);
	displayPeg(peg2);
	displayPeg(peg3);
	cout << endl;
}

void moveDisk(Peg& peg1, Peg& peg2, int& amountOfMoves) {
	assert(!peg1.peg.empty());
	if (!peg2.peg.empty()) {
		assert(peg2.peg.back() > peg1.peg.back());
	}
	peg2.peg.push_back(peg1.peg.back());
	peg1.peg.pop_back();
	cout << "Moved disk " << peg2.peg.back() << " from " << peg1.name << " to " << peg2.name << endl;
	amountOfMoves++;
}

void hanoi(Peg &startPeg, Peg &goalPeg, Peg &tempPeg, int amountOfDisks, int& amountOfMoves) {
	if (amountOfDisks != 1) {
		//Move all but one peg to tempPeg
		hanoi(startPeg, tempPeg, goalPeg, amountOfDisks - 1, amountOfMoves);

		//Move leftover disk to goalPeg
		moveDisk(startPeg, goalPeg, amountOfMoves);

		//Move all of tempPeg onto goalPeg
		hanoi(tempPeg, goalPeg, startPeg, amountOfDisks - 1, amountOfMoves);
	}
	else {
		moveDisk(startPeg, goalPeg, amountOfMoves);
	}
}
