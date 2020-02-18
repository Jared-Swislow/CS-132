//Jared Swislow
//CS 132 Program 7: Inheritance and Polymorphism

#include <iostream>
#include "Rectangle.h"
#include "Cylinder.h"
#include "Stack.h"

using namespace std;

int main() {
	Stack<Shape*> shapeStack;

	shapeStack.push(new Rectangle("Rectangle on stack", 3, 5));
	shapeStack.push(new Cylinder("Cylinder on stack", 4, 10));

	while (shapeStack.getAmountOfNodes() > 0) {
		Shape* shapePtr = shapeStack.pop();
		cout << "Name: " << shapePtr->getName() << endl;
		cout << "Area/Volume: " << shapePtr->getArea() << endl;
		cout << "Perimeter/Surface Area: " << shapePtr->getPerimeter() << endl << endl;
		delete shapePtr;
	}
	
	//Shape Test Code
	{
		Rectangle myRect("First rectangle", 3, 5);
		cout << myRect;
		myRect.setName("New rectangle");
		myRect.setWidth(8);
		myRect.setHeight(10);
		cout << myRect;

		Cylinder myCylinder("First cylinder", 4, 10);
		cout << myCylinder;
		myCylinder.setName("New cylinder");
		myCylinder.setBaseRadius(8);
		myCylinder.setHeight(1);
		cout << myCylinder;
	}
}