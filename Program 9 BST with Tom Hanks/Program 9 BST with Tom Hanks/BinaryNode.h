#pragma once
#include <ostream>

using namespace std;

template <typename P>
class BinaryNode {
private:
	P payload;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(P newPayload, BinaryNode* newLeft, BinaryNode* newRight) {
		payload = newPayload;
		left = newLeft;
		right = newRight;
	}

	//Accessors
	P getPayload() const {
		return payload;
	}
	BinaryNode* getLeft() const {
		return left;
	}
	BinaryNode* getRight() const {
		return right;
	}

	//Mutators
	void setPayload(P newPayload) {
		payload = newPayload;
	}
	void setLeft(BinaryNode* newLeftPtr) {
		left = newLeftPtr;
	}
	void setRight(BinaryNode* newRightPtr) {
		right = newRightPtr;
	}

	//<< overload
	friend ostream& operator << (ostream& outStream, const BinaryNode& nodeToPrint) {
		outStream << nodeToPrint.getPayload();
		return outStream;
	}

	~BinaryNode() {

	}
};