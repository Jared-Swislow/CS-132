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
			newNode = new BinaryNode<int>(currentNode->getPayload(), copyHelper(currentNode->getLeftPtr()), copyHelper(currentNode->getRightPtr()));
		}
		return newNode;
	}

	//Helper to clear the tree
	//Doesn't set head to nullptr, so may need to be changed for some future use
	void clearTree(BinaryNode<int>* currentNode) {
		if (currentNode != nullptr) {
			clearTree(currentNode->getLeftPtr());
			clearTree(currentNode->getRightPtr());
			delete currentNode;
		}
	}

	//Helpers for each traversal order
	void preOrderHelper(const BinaryNode<int>* currentNode, ostream& outStream) {
		if (currentNode != nullptr) {
			outStream << currentNode->getPayload() << " ";
			preOrderHelper(currentNode->getLeftPtr(), outStream);
			preOrderHelper(currentNode->getRightPtr(), outStream);
		}
	}
	void inOrderHelper(const BinaryNode<int>* currentNode, ostream& outStream) {
		if (currentNode != nullptr) {
			inOrderHelper(currentNode->getLeftPtr(), outStream);
			outStream << currentNode->getPayload() << " ";
			inOrderHelper(currentNode->getRightPtr(), outStream);
		}
	}
	void postOrderHelper(const  BinaryNode<int>* currentNode, ostream& outStream) {
		if (currentNode != nullptr) {
			postOrderHelper(currentNode->getLeftPtr(), outStream);
			postOrderHelper(currentNode->getRightPtr(), outStream);
			outStream << currentNode->getPayload() << " ";
		}
	}

	void breadthOrderHelper(BinaryNode<int>* currentNode, ostream& outStream) {
		Queue<BinaryNode<int>*> queue;
		if (currentNode != nullptr) {
			queue.enqueue(currentNode);
		}
		while (!queue.isEmpty()) {
			BinaryNode<int>* tempHead = queue.dequeue();
			outStream << tempHead->getPayload() << " ";
			if (tempHead->getLeftPtr() != nullptr) {
				queue.enqueue(tempHead->getLeftPtr());
			}
			if (tempHead->getRightPtr() != nullptr) {
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

	//Accessor for TraversalType
	TraversalType getTraversalType() {
		return traversalType;
	}

	//Temporary Mutator for head
	void setHead(BinaryNode<int>* newHead) {
		head = newHead;
	}

	//Mutator for traversal type
	void setTraversalType(TraversalType newTraversalType) {
		traversalType = newTraversalType;
	}

	//Traversal manager(overload of <<)
	friend ostream& operator << (ostream & outStream, BinaryTree& treeToPrint) {
		switch (treeToPrint.traversalType) {
		case TraversalType::INORDER:
			treeToPrint.inOrderHelper(treeToPrint.head, outStream);
			break;

		case TraversalType::PREORDER:
			treeToPrint.preOrderHelper(treeToPrint.head, outStream);
			break;

		case TraversalType::POSTORDER:
			treeToPrint.postOrderHelper(treeToPrint.head, outStream);
			break;

		case TraversalType::BREADTHORDER:
			treeToPrint.breadthOrderHelper(treeToPrint.head, outStream);
			break;
		}
		return outStream;
	}

	//Operator overload for =
	BinaryTree operator = (const BinaryTree& fromTree) {
		if (this != &fromTree) {
			clearTree(head);
			head = copyHelper(fromTree.head);
		}
		return *this;
	}

	~BinaryTree() {
		clearTree(head);
	}
};
