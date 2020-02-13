#pragma once
#include "Shape.h"

using namespace std;

class Rectangle : public Shape{
private:
	int height, width;
protected:
public:
	//Constructor that calls the shape base class
	Rectangle(string newName, int width, int height);

	//Accessors
	int getHeight() const;
	int getWidth() const;

	//Mutators
	void setHeight(int newHeight);
	void setWidth(int newWidth);

	//Calculate Area and perimeter
	int getArea() const;
	int getPerimeter() const;

	//Overload for <<
	friend ostream& operator << (ostream& outStream, const Rectangle& rectToPrint);
};