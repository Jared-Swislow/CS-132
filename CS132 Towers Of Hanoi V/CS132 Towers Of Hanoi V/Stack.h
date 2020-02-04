#pragma once

#include "Node.h"
#include <ostream>

using namespace std;

class Stack {
private:
	Node* top;
	int amountOfNodes;

	void displayStackReverseHelper(Node* current, ostream& outStream) const;
public:
	//Default constructor
	Stack();
	
	//Accessors for top and amountOfNodes
	int getTop() const;
	int getAmountOfNodes() const;

	//Push and pop functions
	void push(int valueToPush);
	int pop();

	//Displaying the stack
	//void displayStack() const;
	//void displayStackInReverse() const;

	//Operator Overloading for <<
	friend ostream& operator <<(ostream& outStream, const Stack& stack);

	//Default Destructor
	~Stack();
};