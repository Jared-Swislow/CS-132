//#include "stdafx.h"
#include "Peg.h"
#include <iostream>
#include <vector>
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
		stack.push_back(i);
	}
}

void Peg::printPeg() const {
	cout << name << ": ";
	for (int i = 0; i < static_cast<int>(stack.size()); i++) {
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
	stack.push_back(diskValue);
}

int Peg::topDisk() const {
	assert(getNumDisks() > 0);
	return stack.back();
}

int Peg::removeTop() {
	assert(getNumDisks() > 0);
	int temp = stack.back();
	stack.pop_back();
	return temp;
}

Peg::~Peg() {

}