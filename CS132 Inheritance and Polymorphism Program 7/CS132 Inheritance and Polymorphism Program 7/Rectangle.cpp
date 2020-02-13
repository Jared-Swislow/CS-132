#include "Rectangle.h"
#include <string>
#include <ostream>

using namespace std;

Rectangle::Rectangle(string newName, int newWidth, int newHeight) : Shape(newName) {
	width = newWidth;
	height = newHeight;
}

int Rectangle::getHeight() const {
	return height;
}

int Rectangle::getWidth() const {
	return width;
}

void Rectangle::setHeight(int newHeight) {
	height = newHeight;
}

void Rectangle::setWidth(int newWidth) {
	width = newWidth;
}

int Rectangle::getArea() const {
	return width * height;
}

int Rectangle::getPerimeter() const {
	return (2 * width) + (2 * height);
}

ostream& operator << (ostream& outStream, const Rectangle& rectToPrint) {
	outStream << "Name: " << rectToPrint.getName() << endl;
	outStream << "Width: " << rectToPrint.getWidth() << endl;
	outStream << "Height: " << rectToPrint.getHeight() << endl;
	outStream << "Area: " << rectToPrint.getArea() << endl;
	outStream << "Perimeter: " << rectToPrint.getPerimeter() << endl;
	outStream << endl;
	return outStream;
}