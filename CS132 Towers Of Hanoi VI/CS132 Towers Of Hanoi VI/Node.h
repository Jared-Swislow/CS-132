#pragma once

#include <ostream>

using namespace std;
template<typename V>

class Node {
private:
	Node* next;
	V value;
public:
	//Constructors with value and one with a nextPtr
	Node(V newValue) {
		value = newValue;
		next = nullptr;
	}
	Node(V newValue, Node* nextNodePtr) {
		value = newValue;
		next = nextNodePtr;
	}

	//Accessors for value and next
	Node* getNextNodePtr() const {
		return next;
	}
	V getValue() const {
		return value;
	}

	//Mutators for value and next
	void setNextNodePtr(Node* ptrToSet) {
		next = ptrToSet;
	}
	void setValue(int newValue) {
		value = newValue;
	}

	//Operator Overloading for <<
	friend ostream& operator << (ostream& outStream, const Node& node) {
		outStream << node.getValue();
		return outStream;
	}

	//Default Destructor
	~Node() {};
};