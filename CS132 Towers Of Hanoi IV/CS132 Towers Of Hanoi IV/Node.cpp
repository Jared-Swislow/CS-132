#include "stdafx.h" //Dependancy for home computer
#include "Node.h"
#include <iostream>
#include <cassert>

using namespace std;

Node::Node(int newValue) {
	value = newValue;
	next = nullptr;
}

Node::Node(int newValue, Node* nextNodePtr) {
	value = newValue;
	next = nextNodePtr;
}

//Accessors for next and value
Node* Node::getNextNodePtr() const {
	return next;
}

int Node::getValue() const {
	assert(this != nullptr);
	return value;
}

//Mutators for next and value
void Node::setNextNodePtr(Node* ptrToSet) {
	next = ptrToSet;
}

void Node::setValue(int newValue) {
	value = newValue;
}


ostream& operator << (ostream& outStream, const Node thisNode) {
	outStream << thisNode.value;
	return outStream;
}

Node::~Node() {
	
}