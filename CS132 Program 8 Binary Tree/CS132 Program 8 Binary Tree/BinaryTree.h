#pragma once
#include "BinaryNode.h"

using namespace std;

class BinaryTree {
private:
	BinaryNode<int>* head;
	//TraversalType traversalType;
public:
	BinaryTree() {
		head = nullptr;
	}

	//BinaryTree(const BinaryTree& oldTree);

	//Temporary Accessor for head
	BinaryNode<int>* getHeadPtr() {
		return head;
	}

	//Temporary Mutator for head
	void setHeadPtr(BinaryNode<int>* newHeadPtr) {
		head = newHeadPtr;
	}
};
