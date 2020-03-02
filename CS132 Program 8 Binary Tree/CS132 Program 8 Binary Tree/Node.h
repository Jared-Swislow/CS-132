#pragma once

#include <ostream>

using namespace std;
template<typename P>

class Node {
private:
	Node<P>* next;
	P payload;
public:
	//Constructors with value and one with a nextPtr
	Node(P newPayload) {
		payload = newPayload;
		next = nullptr;
	}
	Node(P newPayload, Node* nextNodePtr) {
		payload = newPayload;
		next = nextNodePtr;
	}

	//Accessors for value and next
	Node* getNext() const {
		return next;
	}
	P getPayload() const {
		return payload;
	}

	//Mutators for value and next
	void setNext(Node* ptrToSet) {
		next = ptrToSet;
	}
	void setPayload(int newPayload) {
		payload = newPayload;
	}

	//Operator Overloading for <<
	friend ostream& operator << (ostream& outStream, const Node<P>& node) {
		outStream << node.getPayload();
		return outStream;
	}

	//Default Destructor
	~Node() {};
};