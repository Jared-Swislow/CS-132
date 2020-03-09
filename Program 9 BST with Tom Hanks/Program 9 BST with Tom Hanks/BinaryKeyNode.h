#pragma once

#include "BinaryNode.h"

template<typename KeyType, typename PayloadType>
class BinaryKeyNode : public BinaryNode<PayloadType>{
private:
	BinaryKeyNode* left;
	BinaryKeyNode* right;
	KeyType key;
public:
	//Constructor with key and payload
	BinaryKeyNode(KeyType newKey, PayloadType newPayload) : BinaryNode<PayloadType>(newPayload, nullptr, nullptr) {
		key = newKey;
		//These are already initialized as nullptr in the BinaryNode constructor,
		// but the compiler gave warnings about them not being initialized until
		// I put these lines in
		left = nullptr;
		right = nullptr;
	}

	//Accessors for key and left and right nodes
	KeyType getKey() const {
		return key;
	}
	BinaryKeyNode* getLeft() const {
		return left;
	}
	BinaryKeyNode* getRight() const {
		return right;
	}

	//Mutator for key
	void setKey(KeyType newKey) {
		key = newKey;
	}
	void setLeft(BinaryKeyNode* newLeft) {
		left = newLeft;
	}
	void setRight(BinaryKeyNode* newRight) {
		right = newRight;
	}

	//Operator overload for <<
	friend ostream& operator << (ostream& outStream, const BinaryKeyNode<KeyType, PayloadType>& binaryKeyNode) {
		outStream << binaryKeyNode.getPayload();
		return outStream;
	}
};
