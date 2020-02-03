//#include "stdafx.h" //Dependancy for home computer
#include "Node.h"
#include <ostream>

using namespace std;

Node::Node(int newValue) {
	value = newValue;
	next = nullptr;
}

Node::Node(int newValue, Node* nextNodePtr) {
	value = newValue;
	next = nullptr;
}

//Accessors for next and value
Node* Node::getNextNodePtr() const {
	return next;
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

//Operator overloading for <<
ostream& operator << (ostream& outStream, const Node& node) {
	outStream << node.getValue();
	return outStream;
}

Node::~Node() {
	
}