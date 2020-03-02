//Jared Swislow
//CS 132 Program 8: Basic Binary Tree
/*
TO-DO:
In BinaryTree.h:
    template Binary Tree
    Create constructor(s), a copy constructor, accessor/
    mutator for the head pointer and print traversal order, an
    overload for the assignment (=) operator, and a destructor.
    In addition, overload the ostream insertion (<<) operator
    allowing for output in breadth order, pre-order, in-order,
    or post-order, depending how the print order attribute is set.
*/

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{

    //Test code
    {
        BinaryNode<int> myNode(1234, nullptr, nullptr);
        BinaryNode<string> myNode2("testNode", nullptr, nullptr);
        cout << myNode << endl;
        cout << myNode2 << endl;

        BinaryTree myTree(TraversalType::BREADTHORDER);

        cout << myTree;

    }

	{
		BinaryTree tree1(TraversalType::BREADTHORDER), tree2(TraversalType::BREADTHORDER);
		BinaryNode<int>* node1, * node2;

		tree1.setHead(new BinaryNode<int>(1, nullptr, nullptr));

		// Level 1
		node1 = tree1.getHeadPtr();
		node1->setLeftPtr(new BinaryNode<int>(2, nullptr, nullptr));
		node1->setRightPtr(new BinaryNode<int>(3, nullptr, nullptr));

		// Level 2
		node2 = node1->getRightPtr(); // 3
		node1 = node1->getLeftPtr(); // 2

		node1->setRightPtr(new BinaryNode<int>(4, nullptr, nullptr));
		node2->setLeftPtr(new BinaryNode<int>(5, nullptr, nullptr));
		node2->setRightPtr(new BinaryNode<int>(6, nullptr, nullptr));

		// Level 3
		node1 = node2->getLeftPtr(); // 5
		node2 = node2->getRightPtr(); // 6

		node1->setLeftPtr(new BinaryNode<int>(7, nullptr, nullptr));
		node2->setLeftPtr(new BinaryNode<int>(8, nullptr, nullptr));
		node2->setRightPtr(new BinaryNode<int>(9, nullptr, nullptr));

		tree1.setTraversalType(TraversalType::PREORDER);
		cout << "Tree 1 (preorder)    : " << tree1 << endl;
		tree1.setTraversalType(TraversalType::INORDER);
		cout << "Tree 1 (inorder)     : " << tree1 << endl;
		tree1.setTraversalType(TraversalType::POSTORDER);
		cout << "Tree 1 (postorder)   : " << tree1 << endl;
		tree1.setTraversalType(TraversalType::BREADTHORDER);
		cout << "Tree 1 (breadthorder): " << tree1 << endl;

		// Test the copy constructor and = method.
		tree2 = tree1;
		cout << "Tree 2               : " << tree2 << endl;

		BinaryTree tree3(tree1);
		cout << "Tree 3               : " << tree3 << endl;
	}

    //Cliff's main
	/*
    {
		BinaryTree<char> tree1, tree2;
		BinaryNode<char>* node1, * node2;

		tree1.setHead(new BinaryNode<char>('A', nullptr, nullptr));

		// Level 1
		node1 = tree1.getHead();
		node1->setLeftPtr(new BinaryNode<char>('B', nullptr, nullptr));
		node1->setRightPtr(new BinaryNode<char>('C', nullptr, nullptr));

		// Level 2
		node2 = node1->getRightPtr(); // C
		node1 = node1->getLeftPtr(); // B

		node1->setRightPtr(new BinaryNode<char>('D', nullptr, nullptr));
		node2->setLeftPtr(new BinaryNode<char>('E', nullptr, nullptr));
		node2->setRightPtr(new BinaryNode<char>('F', nullptr, nullptr));

		// Level 3
		node1 = node2->getLeftPtr(); // E
		node2 = node2->getRightPtr(); // F

		node1->setLeftPtr(new BinaryNode<char>('G', nullptr, nullptr));
		node2->setLeftPtr(new BinaryNode<char>('H', nullptr, nullptr));
		node2->setRightPtr(new BinaryNode<char>('I', nullptr, nullptr));

		tree1.setTraverseOrder(TraversalType::PREORDER);
		cout << "Tree 1 (preorder)    : " << tree1 << endl;
		tree1.setTraverseOrder(TraversalType::INORDER);
		cout << "Tree 1 (inorder)     : " << tree1 << endl;
		tree1.setTraverseOrder(TraversalType::POSTORDER);
		cout << "Tree 1 (postorder)   : " << tree1 << endl;
		tree1.setTraverseOrder(TraversalType::BREADTHORDER);
		cout << "Tree 1 (breadthorder): " << tree1 << endl;

		// Test the copy constructor and = method.
		tree2 = tree1;
		cout << "Tree 2               : " << tree2 << endl;

		BinaryTree<char> tree3(tree1);
		cout << "Tree 3               : " << tree3 << endl;
    }
	*/
}