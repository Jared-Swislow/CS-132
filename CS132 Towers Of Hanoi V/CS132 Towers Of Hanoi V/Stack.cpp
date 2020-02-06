#include "Stack.h"
#include "Node.h"
#define NDEBUG
#include <cassert>
#include <iostream>

using namespace std;

Stack::Stack() {
	top = nullptr;
	amountOfNodes = 0;
}

Stack::Stack(const Stack& fromStack) {
	amountOfNodes = 0;
	top = nullptr;
	copyHelper(fromStack.top);
}

void Stack::copyHelper(Node* fromTop) {
	if (fromTop != nullptr) {
		copyHelper(fromTop->getNextNodePtr());
		push(fromTop->getValue());
	}
}

//Accessors for top and amountOfNodes
int Stack::getTop() const {
	assert(amountOfNodes > 0);
	if (amountOfNodes == 0) {
		throw runtime_error("There are no nodes on the stack (Stack::getTop())");
	}
	return top->getValue();
}

int Stack::getAmountOfNodes() const {
	return amountOfNodes;
}

//Push and pop functions
bool Stack::push(int valueToPush) {
	//If there is not enough memory, it will return false
	bool returnBool = true;
	Node* temp = top;
	try {
		top = new Node(valueToPush);
	}
	catch (exception & e) {
		cerr << "A node was attempted to put on the stack, but ther is not enough memory. (Stack::push())" << endl;
		cerr << "The error reported by the compiler: " << e.what() << endl;
		cerr << "The name of the error: " << typeid(e).name() << endl;
		returnBool = false;
	}
	top->setNextNodePtr(temp);
	amountOfNodes++;
	return returnBool;
}
int Stack::pop() {
	assert(amountOfNodes > 0);
	if (amountOfNodes == 0) {
		throw runtime_error("There are no nodes on the stack (Stack::pop())");
	}
	int tempValue;
	tempValue = top->getValue();
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

//Operator Overloading for =
Stack& Stack::operator = (const Stack& fromStack) {
	if (this != &fromStack) {
		destructorHelper();
		copyHelper(fromStack.top);
	}
	return *this;
}

//Operator Overloading for ==
bool Stack::operator == (const Stack& fromStack) {
	bool returnBool = true;
	if (this != &fromStack) { //Only do the if statement if they aren't the same memory addresses
		if (amountOfNodes != fromStack.amountOfNodes) { //If they have the same amount of nodes, exit and return false
			returnBool = false;
		}
		else { //Else(Only if they don't have the same memory address and have the same amount of nodes)
			Node* thisTopTemp = top;
			Node* fromTopTemp = fromStack.top;
			while (thisTopTemp != nullptr && returnBool) { //run while we still have nodes left or we've already found that they are different
				if (thisTopTemp->getValue() != fromTopTemp->getValue()) {
					returnBool = false;
				}
				thisTopTemp = thisTopTemp->getNextNodePtr();
				fromTopTemp = fromTopTemp->getNextNodePtr();
			}
		}
	}
	return returnBool;
}

//Destructor
Stack::~Stack() {
	destructorHelper();
}

//Destuctor helper
void Stack::destructorHelper() {
	while (top != nullptr) {
		pop();
	}
}