#include "stdafx.h"
#include "Peg.h"
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

Peg::Peg(string pegName, int numDisks) {
	name = pegName;
	for (int i = numDisks; i > 0; i--) {
		stack.push_back(i);
	}
}

void Peg::loadDisks(int numDisks) {
	assert(numDisks >= 0, "Passed a negative number of disks into Peg::loadDisks()");
	for (int i = numDisks; i > 0; i--) {
		stack.push_back(i);
	}
}

void Peg::printPeg() const {
	cout << name << ": ";
	for (int i = 0; i < stack.size(); i++) {
		cout << stack[i];
	}
	cout << endl;
}

unsigned int Peg::getNumDisks() const {
	return stack.size();
}

string Peg::getName() const {
	return name;
}

void Peg::addDisk(int diskValue) {
	assert(diskValue > 0, "Passed a non-positive disk value into Peg::addDisk()");
	stack.push_back(diskValue);
}

int Peg::topDisk() const {
	return stack.back();
}

int Peg::removeTop() {
	int temp = stack.back();
	stack.pop_back();
	return temp;
}

bool Peg::isPegEmpty() {
	//If size is zero, the cast will convert it to false. Otherwise, true. Then boolean reversed to match method.
	return !static_cast<bool>(stack.size());
}

void Peg::displayName() {
	cout << name;
}

Peg::~Peg() {

}