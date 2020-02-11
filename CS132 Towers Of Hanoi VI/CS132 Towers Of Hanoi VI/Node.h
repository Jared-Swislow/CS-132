#pragma once

#include <ostream>

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

	//Operator Overloading for <<
	friend ostream& operator <<(ostream& outStream, const Node& node);

	//Default Destructor
	~Node();
};