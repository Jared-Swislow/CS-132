#include "Peg.h"
#include <ostream>
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

//void Peg::printPeg() const {
//	cout << name << ": " << stack << endl;
//}

//void Peg::printPegReverse() const {
//	cout << name << ": ";
//	stack.displayStackInReverse();
//	cout << endl;
//}

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
	return stack.getTop();
}

int Peg::removeTop() {
	assert(getNumDisks() > 0);
	int temp = stack.getTop();
	stack.pop();
	return temp;
}

//Operator Overloading for <<
ostream& operator <<(ostream& outStream, const Peg& peg) {
	cout << peg.name << ": " << peg.stack << endl;
	return outStream;
}

Peg::~Peg() {

}