#include "Node.h"

using namespace std;

Node::Node(int newValue) {
	value = newValue;
	next = nullptr;
}

//Accessors for next and value
Node* Node::getNextNodePtr() const {
	Node* returnPtr = nullptr;
	if (next != nullptr) {
		returnPtr = next;
	}
	return returnPtr;
}

int Node::getValue() const {
	return value;
}

//Mutators for next and value
void Node::setNextNodePtr(Node* ptrToSet) {
	next = ptrToSet;
}

void Node::setValue(int newValue) {
	value = newValue;
}

Node::~Node() {
	
}