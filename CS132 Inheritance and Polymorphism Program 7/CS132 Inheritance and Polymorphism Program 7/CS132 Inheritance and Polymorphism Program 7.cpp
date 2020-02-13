//Jared Swislow
//CS 132 Program 7: Inheritance and Polymorphism

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {
	Rectangle myRect("First rectangle", 3, 5);
	cout << myRect;
	myRect.setName("New rectangle!");
	myRect.setWidth(8);
	myRect.setHeight(10);
	cout << myRect;
}