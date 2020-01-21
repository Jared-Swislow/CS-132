#pragma once

using namespace std;

class Node {
private:
	Node* next = nullptr;
	int value;
public:
	//Default Constructor
	Node();

	//Accessors for value and next
	Node* getNextNodePtr() const;
	int getValue() const;

	//Mutators for value and next
	void setNextNodePtr(Node* ptrToSet);
	int setValue(int newValue);

	//Default Destructor
	~Node();
};