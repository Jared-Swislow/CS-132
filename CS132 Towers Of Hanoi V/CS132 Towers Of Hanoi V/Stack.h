#pragma once

#include "Node.h"
#include <ostream>

using namespace std;

class Stack {
private:
	Node* top;
	unsigned int amountOfNodes;

	void displayStackReverseHelper(Node* current, ostream& outStream) const;
	void destructorHelper();
public:
	//Default constructor
	Stack();

	//Copy constructor with helper function
	Stack(const Stack& fromStack);
	void copyHelper(Node* fromTop);
	
	//Accessors for top and amountOfNodes
	int getTop() const;
	int getAmountOfNodes() const;

	//Push and pop functions
	bool push(int valueToPush);
	int pop();

	//Displaying the stack
	//void displayStack() const;
	//void displayStackInReverse() const;

	//Operator Overloading for <<
	friend ostream& operator <<(ostream& outStream, const Stack& stack);

	//Operator Overloading for =
	Stack& operator = (const Stack& fromStack);

	//Operator Overloading for ==
	bool operator == (const Stack& fromStack);

	//Default Destructor
	~Stack();
};