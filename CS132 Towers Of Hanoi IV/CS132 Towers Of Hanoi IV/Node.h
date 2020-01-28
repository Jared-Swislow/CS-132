#pragma once

#include <iostream>

using namespace std;

class Node {
private:
	Node* next;
	int value;
public:
	//Constructor with value
	Node(int newValue);
	Node(int newValue, Node* nextNodePtr);

	//Accessors for value and next
	Node* getNextNodePtr() const;
	int getValue() const;

	//Mutators for value and next
	void setNextNodePtr(Node* ptrToSet);
	void setValue(int newValue);

	//Operator overloading
	friend ostream& operator << (ostream& outStream, Node thisNode);

	//Default Destructor
	~Node();
};