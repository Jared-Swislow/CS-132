#include "stdafx.h" //Dependancy for home computer
#include "Stack.h"
#include "Node.h"
#include <cassert>
#include <iostream>

using namespace std;

Stack::Stack() {
	top = nullptr;
	amountOfNodes = 0;
}

//Accessors for top and amountOfNodes
Node* Stack::getTop() const {
	assert(amountOfNodes > 0);
	return top;
}

int Stack::getAmountOfNodes() const {
	return amountOfNodes;
}

//Push and pop functions
//Clean this up to not have ifs?
void Stack::push(int valueToPush) {
	if (amountOfNodes == 0) {
		top = new Node(valueToPush);
	}
	else {
		Node* temp = top;
		top = new Node(valueToPush);
		top->setNextNodePtr(temp);
	}
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
void Stack::displayStack() const {
	Node* crawler = top;
	while(crawler != nullptr) {
		cout << crawler->getValue();
		crawler = crawler->getNextNodePtr();
	}
}

void Stack::displayStackInReverse() const {
	if (amountOfNodes > 0) {
		displayStackReverseHelper(getTop());
	}
}

void Stack::displayStackReverseHelper(Node* current) const {
	if (current != nullptr) {
		displayStackReverseHelper(current->getNextNodePtr());
		cout << current->getValue();
	}
}

//Destructor
Stack::~Stack() {
	while (top != nullptr) {
		pop();
	}
}