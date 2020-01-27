#pragma once

using namespace std;

class Node {
private:
	Node* next;
	int value;
public:
	//Constructor with value
	Node(int newValue);

	//Accessors for value and next
	Node* getNextNodePtr() const;
	int getValue() const;

	//Mutators for value and next
	void setNextNodePtr(Node* ptrToSet);
	void setValue(int newValue);

	//Default Destructor
	~Node();
};