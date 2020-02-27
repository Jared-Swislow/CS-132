#pragma once
#include "BinaryNode.h"
#include "Queue.h"

using namespace std;

enum class TraversalType {INORDER, PREORDER, POSTORDER, BREADTHORDER};

class BinaryTree {
private:
	BinaryNode<int>* head;
	TraversalType traversalType;

	//Helper to copy the tree with the head node passed in
	BinaryNode<int>* copyHelper(BinaryNode<int>* currentNode) {
		BinaryNode<int>* newNode = nullptr;
		if (currentNode != nullptr) {
			BinaryNode<int>* newNode = new BinaryNode<int>(currentNode->getPayload(), copyHelper(currentNode->getLeftPtr()), copyHelper(currentNode->getRightPtr()));
		}
		return newNode;
	}

	//Helper to clear the tree
	void clearTree(BinaryNode<int>* currentNode) {
		if (currentNode != nullptr) {
			clearTree(currentNode->getLeftPtr());
			clearTree(currentNode->getRightPtr());
			delete currentNode;
		}
	}

	//Helpers for each traversal order
	void preOrderHelper(const BinaryTree& fromTree, ostream& outStream);
	void inOrderHelper(const BinaryTree& fromTree, ostream& outStream);
	void postOrderHelper(const BinaryTree& fromTree, ostream& outStream);

	void breadthOrderHelper(const BinaryTree& fromTree, ostream& outStream) {
		Queue<BinaryNode<int>*> queue;
		if (fromTree.head != nullptr) {
			queue.enqueue(fromTree.head);
		}
		while (!queue.isEmpty()) {
			BinaryNode<int>* tempHead = queue.dequeue();
			outStream << tempHead;
			if (tempHead->getLeftPtr() != nullptr) {
				queue.enqueue(tempHead->getLeftPtr());
			}
			if (tempHead->getLeftPtr() != nullptr) {
				queue.enqueue(tempHead->getRightPtr());
			}
		}
	}

public:

	//Constructor with traversalType defined
	BinaryTree(TraversalType printOrder) {
		head = nullptr;
		traversalType = printOrder;
	}

	//Copy Constructor
	BinaryTree(BinaryTree& fromTree) {
		head = copyHelper(fromTree.head);
		traversalType = fromTree.traversalType;
	}

	//Temporary Accessor for head
	BinaryNode<int>* getHeadPtr() {
		return head;
	}

	//Temporary Mutator for head
	void setHeadPtr(BinaryNode<int>* newHeadPtr) {
		head = newHeadPtr;
	}

	//Traversal manager(overload of <<)
	friend ostream& operator << (ostream & outStream, BinaryTree& treeToPrint) {
		switch (treeToPrint.traversalType) {
		case TraversalType::INORDER:
			treeToPrint.inOrderHelper(treeToPrint, outStream);
			break;

		case TraversalType::PREORDER:
			treeToPrint.preOrderHelper(treeToPrint, outStream);
			break;

		case TraversalType::POSTORDER:
			treeToPrint.postOrderHelper(treeToPrint, outStream);
			break;

		case TraversalType::BREADTHORDER:
			treeToPrint.breadthOrderHelper(treeToPrint, outStream);
			break;
		}
		return outStream;
	}

	//Operator overload for =
	BinaryTree operator = (const BinaryTree& fromTree) {
		if (this != &fromTree) {
			clearTree(head);
			copyHelper(fromTree.head);
		}
		return *this;
	}

	~BinaryTree() {
		clearTree(head);
	}
};
