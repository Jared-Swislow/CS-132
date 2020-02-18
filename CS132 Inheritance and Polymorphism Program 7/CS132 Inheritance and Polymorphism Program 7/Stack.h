#pragma once

#include "Node.h"
#include <ostream>
#include <cassert>
#include <iostream>

using namespace std;
template <typename T>

class Stack {
private:
	Node<T> *top;
	unsigned int amountOfNodes;

	void displayStackReverseHelper(Node<T>* current, ostream& outStream) const {
		if (current != nullptr) {
			displayStackReverseHelper(current->getNextNodePtr(), outStream);
			outStream << *current;
		}
	}
	void destructorHelper() {
		while (top != nullptr) {
			pop();
		}
	}
public:
	//Default constructor
	Stack() {
		top = nullptr;
		amountOfNodes = 0;
	}

	//Copy constructor with helper function
	Stack(const Stack& fromStack) {
		amountOfNodes = 0;
		top = nullptr;
		copyHelper(fromStack.top);
	}
	void copyHelper(Node<int>* fromTop) {
		if (fromTop != nullptr) {
			copyHelper(fromTop->getNextNodePtr());
			push(fromTop->getValue());
		}
	}
	
	//Accessors for top and amountOfNodes
	T getTop() const {
		assert(amountOfNodes > 0);
		if (amountOfNodes == 0) {
			throw runtime_error("There are no nodes on the stack (Stack::getTop())");
		}
		return top->getValue();
	}
	int getAmountOfNodes() const {
		return amountOfNodes;
	}

	//Push and pop functions
	bool push(T valueToPush) {
		//If there is not enough memory, it will return false
		bool returnBool = true;
		Node<T>* temp = top;
		try {
			top = new Node<T>(valueToPush);
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
	T pop() {
		assert(amountOfNodes > 0);
		if (amountOfNodes == 0) {
			throw runtime_error("There are no nodes on the stack (Stack::pop())");
		}
		T tempValue;
		tempValue = top->getValue();
		Node<T>* temp = top;
		top = top->getNextNodePtr();
		delete temp;
		amountOfNodes--;
		return tempValue;
	}

	//Operator Overloading for <<
	friend ostream& operator <<(ostream & outStream, const Stack & stack) {
		stack.displayStackReverseHelper(stack.top, outStream);
		return outStream;
	}

	//Operator Overloading for =
	Stack& operator = (const Stack& fromStack) {
		if (this != &fromStack) {
			destructorHelper();
			copyHelper(fromStack.top);
		}
		return *this;
	}

	//Operator Overloading for ==
	bool operator == (const Stack& fromStack) {
		bool returnBool = true;
		if (this != &fromStack) { //Only do the if statement if they aren't the same memory addresses
			if (amountOfNodes != fromStack.amountOfNodes) { //If they have the same amount of nodes, exit and return false
				returnBool = false;
			}
			else { //Else(Only if they don't have the same memory address and have the same amount of nodes)
				Node<T>* thisTopTemp = top;
				Node<T>* fromTopTemp = fromStack.top;
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

	//Default Destructor
	~Stack() {
		destructorHelper();
	}
};