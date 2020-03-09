#pragma once
#include "BinaryNode.h"
#include "Queue.h"

using namespace std;

template <typename P>
class BinaryTree {
private:
	BinaryNode<P>* head;

	//Helper to copy the tree with the head node passed in
	BinaryNode<P>* copyHelper(BinaryNode<P>* currentNode) {
		BinaryNode<P>* newNode = nullptr;
		if (currentNode != nullptr) {
			newNode = new BinaryNode<P>(currentNode->getPayload(), copyHelper(currentNode->getLeft()), copyHelper(currentNode->getRight()));
		}
		return newNode;
	}

	//Helper to clear the tree
	//Doesn't set head to nullptr, so may need to be changed for some future use
	void clearTree(BinaryNode<P>* currentNode) {
		if (currentNode != nullptr) {
			clearTree(currentNode->getLeft());
			clearTree(currentNode->getRight());
			delete currentNode;
		}
	}

	//Print Helper(Does inorder traversal)
	void printHelper(const BinaryNode<P>* currentNode, ostream& outStream) const {
		if (currentNode != nullptr) {
			printHelper(currentNode->getLeft(), outStream);
			outStream << currentNode->getPayload();
			printHelper(currentNode->getRight(), outStream);
		}
	}

protected:
	//Accessor and mutator for head ptr for children to change the head
	BinaryNode<P>* getHead() {
		return head;
	}

	void setHead(BinaryNode<P>* newHead) {
		head = newHead;
	}
public:
	//Constructor
	BinaryTree() {
		head = nullptr;
	}

	//Copy Constructor
	BinaryTree(BinaryTree& fromTree) {
		head = copyHelper(fromTree.head);
	}

	//Operator overload for <<
	friend ostream& operator << (ostream & outStream, const BinaryTree& treeToPrint) {
		treeToPrint.printHelper(treeToPrint.head, outStream);
		return outStream;
	}

	//Operator overload for =
	BinaryTree& operator = (const BinaryTree& fromTree) {
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
