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
	BinaryNode* getLeftPtr() const {
		return left;
	}
	BinaryNode* getRightPtr() const {
		return right;
	}

	//Mutators
	void setPayload(P newPayload) {
		payload = newPayload;
	}
	void setLeftPtr(BinaryNode* newLeftPtr) {
		left = newLeftPtr;
	}
	void setRightPtr(BinaryNode* newRightPtr) {
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