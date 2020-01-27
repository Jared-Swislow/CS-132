#include "stdafx.h"
#include "Peg.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

Peg::Peg(string pegName, int numDisks) {
	name = pegName;
	loadDisks(numDisks);
}

void Peg::loadDisks(int numDisks) {
	assert(numDisks >= 0);
	for (int i = numDisks; i > 0; i--) {
		stack.push(i);
	}
}

void Peg::printPeg() const {
	cout << name << ": ";
	//stack.displayStack();
	stack.displayStackInReverse();
	cout << endl;
}

unsigned int Peg::getNumDisks() const {
	return stack.getAmountOfNodes();
}

string Peg::getName() const {
	return name;
}

void Peg::addDisk(int diskValue) {
	stack.push(diskValue);
}

int Peg::topDisk() const {
	assert(getNumDisks() > 0);
	return stack.getTop()->getValue();
}

int Peg::removeTop() {
	assert(getNumDisks() > 0);
	int temp = stack.getTop()->getValue();
	stack.pop();
	return temp;
}

Peg::~Peg() {

}