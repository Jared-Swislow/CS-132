//#include "stdafx.h" //Dependancy for home computer
#include "Stack.h"
#include "Node.h"
#include <cassert>
#include <ostream>

using namespace std;

Stack::Stack() {
	top = nullptr;
	amountOfNodes = 0;
}

//Accessors for top and amountOfNodes
int Stack::getTop() const {
	assert(amountOfNodes > 0);
	return top->getValue();
}

int Stack::getAmountOfNodes() const {
	return amountOfNodes;
}

//Push and pop functions
void Stack::push(int valueToPush) {
	Node* temp = top;
	top = new Node(valueToPush);
	top->setNextNodePtr(temp);
	amountOfNodes++;
}
int Stack::pop() {
	assert(amountOfNodes > 0);
	int tempValue = top->getValue();
	Node* temp = top;
	top = top->getNextNodePtr();
	delete temp;
	amountOfNodes--;
	return tempValue;
}

//Displaying the stack
//void Stack::displayStack() const {
//	Node* crawler = top;
//	while(crawler != nullptr) {
//		cout << crawler->getValue();
//		crawler = crawler->getNextNodePtr();
//	}
//}
//
//void Stack::displayStackInReverse() const {
//	if (amountOfNodes > 0) {
//		displayStackReverseHelper(top);
//	}
//}

void Stack::displayStackReverseHelper(Node* current, ostream& outStream) const {
	if (current != nullptr) {
		displayStackReverseHelper(current->getNextNodePtr(), outStream);
		outStream << *current;
	}
}

//Operator Overloading for <<
ostream& operator <<(ostream& outStream, const Stack& stack) {
	stack.displayStackReverseHelper(stack.top, outStream);
	return outStream;
}

//Destructor
Stack::~Stack() {
	while (top != nullptr) {
		pop();
	}
}