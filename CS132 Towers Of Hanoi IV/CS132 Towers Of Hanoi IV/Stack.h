#pragma once

#include "Node.h"

using namespace std;

class Stack {
private:
	Node* top;
	int amountOfNodes;

	void displayStackReverseHelper(Node* current) const;
public:
	//Default constructor
	Stack();
	
	//Accessors for top and amountOfNodes
	Node* getTop() const;
	int getAmountOfNodes() const;

	//Mutators?

	//Push and pop functions
	void push(int valueToPush);
	int pop();

	//Displaying the stack
	void displayStack() const;
	void displayStackInReverse() const;

	//Default Destructor
	~Stack();
};