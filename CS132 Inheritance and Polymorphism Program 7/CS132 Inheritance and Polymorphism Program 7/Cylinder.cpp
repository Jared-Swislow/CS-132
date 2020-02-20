#include "Cylinder.h"
#include <ostream>

Cylinder::Cylinder(string newName, int newBaseRadius, int newHeight) : Shape(newName) {
	baseRadius = newBaseRadius;
	height = newHeight;
}

float Cylinder::getArea() const { //Really volume
	const float PI = 3.14159265359;
	return(PI * baseRadius * baseRadius * height);
}

float Cylinder::getPerimeter() const { //Really Surface Area
	const float PI = 3.14159265359;
	return((2 * PI * baseRadius * baseRadius) + (PI * 2 * baseRadius * height)); //2pir^2+pidh
}

//Accessors
int Cylinder::getBaseRadius() const {
	return baseRadius;
}
int Cylinder::getHeight() const {
	return height;
}

//Mutators
void Cylinder::setBaseRadius(int newBaseRadius) {
	baseRadius = newBaseRadius;
}
void Cylinder::setHeight(int newHeight) {
	height = newHeight;
}

//Operator overloading for <<
ostream& operator << (ostream& outStream, const Cylinder& cylinderToPrint) {
	outStream << "Name: " << cylinderToPrint.getName() << endl;
	outStream << "Base Radius: " << cylinderToPrint.getBaseRadius() << endl;
	outStream << "Height: " << cylinderToPrint.getHeight() << endl;
	outStream << "Volume: " << cylinderToPrint.getArea() << endl;
	outStream << "Surface Area: " << cylinderToPrint.getPerimeter() << endl;
	outStream << endl;
	return outStream;
}

Cylinder::~Cylinder() {

}