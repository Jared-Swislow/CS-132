//Jared Swislow
//CS 132 Program 8: Basic Binary Tree
/*
TO-DO:
In BinaryTree.h:
    Traversal type(Program 8)
    Copy Constructor
    << overload
    Destructor
    Set traversal order (Program 8)
*/

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    {
        BinaryNode<int> myNode(1234, nullptr, nullptr);
        BinaryNode<string> myNode2("bruh", nullptr, nullptr);
        cout << myNode;
        cout << myNode2;
    }
}