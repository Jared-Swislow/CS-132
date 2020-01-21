#include "Node.h"

using namespace std;

Node::Node(int newValue) {
	value = newValue;
	next = nullptr;
}

//Accessors for next and value
Node* getNextNodePtr() const {
	return next;
}

int getValue() const {
	return value;
}

//Mutators for next and value
void setNextNodePtr(Node* ptrToSet) {
	next = ptrToSet;
}

void Node::setValue(int newValue) {
	value = newValue;
}

Node::~Node() {
	
}