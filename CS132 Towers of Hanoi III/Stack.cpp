#include "Stack.h"
#include "Node.h"

using namespace std;

Stack::Stack() {
	top = nullPtr;
	amountOfNodes = 0;
}

//Accessors for top and amountOfNodes
Node* Stack::getTop() const {
	assert(amountOfNodes > 0);
	return top;
}

int Stack::getAmountOfNodes() const {
	return amountOfNodes;
}

//Push and pop functions
//***Clean this up to not have ifs***?????
void push(int valueToPush) {
	if (amountOfNodes = 0) {
		top = new Node(valueToPush);
	}
	else {
		Node* temp = &top;
		top = new Node(valueToPush);
		top.next = temp;
	}
}
int pop() {
	assert(amountOfNodes > 0);
}