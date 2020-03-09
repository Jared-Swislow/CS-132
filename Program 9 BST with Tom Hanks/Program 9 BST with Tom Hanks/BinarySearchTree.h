#pragma once

#include <iostream>
#include "BinaryTree.h"
#include "BinaryKeyNode.h"

using namespace std;

template<typename KeyType, typename PayloadType>
class BinarySearchTree : protected BinaryTree<PayloadType> {
	BinaryKeyNode<KeyType, PayloadType>* head;
private:
	//Recursive insert helper which takes the newKey with a newPayload
	// and sorts it into the tree using the headPtr, which it returns
	BinaryKeyNode<KeyType, PayloadType>* insertHelper(
		BinaryKeyNode<KeyType, PayloadType>* headPtr,
		const KeyType&newKey,
		const PayloadType&newPayload) {
		if (headPtr == nullptr) { //Empty tree
			headPtr = new BinaryKeyNode<KeyType, PayloadType>(newKey, newPayload);
		}
		else if (newKey < headPtr->getKey()) {
			headPtr->setLeft(insertHelper(headPtr->getLeft(), newKey, newPayload));
		}
		else {
			headPtr->setRight(insertHelper(headPtr->getRight(), newKey, newPayload));
		}
		return headPtr;
	}

	//Tries to find the node with the keyToFind and returns a boolean if it does.
	// If it finds it, it sets the payloadToModify to the payload of the found
	// node so the user has access.
	bool findHelper(
		BinaryKeyNode<KeyType, PayloadType>* headPtr,
		const KeyType& keyToFind,
		PayloadType& payloadToModify,
		int &amountOfComparisons) const {
		bool isNodeFound = false;
		if (headPtr != nullptr) {
			cout << "Comparing " << headPtr->getKey() << " to " << keyToFind << "..." << endl;
			amountOfComparisons++;
			if (headPtr->getKey() == keyToFind) { //Found the node
				isNodeFound = true;
				payloadToModify = headPtr->getPayload();
			}
			else if(keyToFind < headPtr->getKey()) { //keyToFind is less than headPtr's key, visit left subtree
				isNodeFound = findHelper(headPtr->getLeft(), keyToFind, payloadToModify, amountOfComparisons);
			}
			else { //keyToFind will be greater than headPtr's key, visit right subtree
				isNodeFound = findHelper(headPtr->getRight(), keyToFind, payloadToModify, amountOfComparisons);
			}
		}
		return isNodeFound;
	}
	/*
	//This overload of findHelper will do the same thing as findHelper,
	// but will have a pointer to the found node instead of the payload
	// modified in the original. This is used for delete().
	bool findHelper(
		BinaryKeyNode<KeyType, PayloadType>* headPtr,
		const KeyType& keyToFind,
		BinaryKeyNode<KeyType, PayloadType>* pointerToModify) const {
		bool isNodeFound = false;
		if (headPtr != nullptr) {
			if (headPtr->getKey() == keyToFind) { //Found the node
				isNodeFound = true;
				pointerToModify = headPtr;
			}
			else if (keyToFind < headPtr->getKey()) { //keyToFind is less than headPtr's key, visit left subtree
				findHelper(headPtr->getLeft(), keyToFind, pointerToModify);
			}
			else { //keyToFind is greater than headPtr's key, visit right subtree
				findHelper(headPtr->getRight(), keyToFind, pointerToModify);
			}
		}
		return isNodeFound;
	}*/

	//Print Helper(Does inorder traversal)
	void printHelper(const BinaryKeyNode<KeyType, PayloadType>* currentNode, ostream& outStream) const {
		if (currentNode != nullptr) {
			printHelper(currentNode->getLeft(), outStream);
			outStream << *currentNode;
			printHelper(currentNode->getRight(), outStream);
		}
	}
public:
	BinarySearchTree() {
		head = nullptr;
	}

	//Insert: Inserts a node to a sorted place in the BST(uses insertHelper())
	void insert(const KeyType newKey, const PayloadType newPayload) {
		head = insertHelper(head, newKey, newPayload);
	}

	//Find: Returns boolean based on whether the node was found and modifies
	// payloadToModify to whatever the payload of the node is (uses findHelper)
	bool find(const KeyType& keyToFind, PayloadType& payloadToModify) const {
		int amountOfComparisons = 0;
		bool returnBool = findHelper(head, keyToFind, payloadToModify, amountOfComparisons);
		cout << amountOfComparisons << " nodes searched..." << endl;
		if (returnBool == false) {
			cout << keyToFind << " was not found." << endl;
		}
		return returnBool;
	}

	/*
	//Delete: Deletes a node with the given key and returns it's payload
	// (uses findHelper)
	int remove(const char& keyToRemove) {
		int payloadToReturn; //This will be the payload that will be removed
		BinaryKeyNode<char, int>* nodeToRemove; //This will be the node that we will remove
		findHelper(head, keyToRemove, nodeToRemove); //An overload of findHelper which will give us back a pointer to the found Node
		payloadToReturn = nodeToRemove->getPayload();
		//If both children are null, set the parent's pointer to nullptr
		if (nodeToRemove->getLeft() == nullptr && nodeToRemove->getRight() == nullptr) {
			//Now we need the node's parent somehow...
		}
		return payloadToReturn;
	}
	*/

	//Operator overload for <<
	friend ostream& operator << (ostream& outStream, const BinarySearchTree& treeToPrint) {
		treeToPrint.printHelper(treeToPrint.head, outStream);
		return outStream;
	}

	~BinarySearchTree() {

	}
};