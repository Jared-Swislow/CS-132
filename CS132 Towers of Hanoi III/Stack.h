#pragma once

#include "Node.h"

using namespace std;

class Stack {
private:
	Node* top;
	int amountOfNodes;
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

	//Default Destructor
	~Stack();
};