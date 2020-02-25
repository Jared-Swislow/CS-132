#include "Torus.h"
#include <ostream>

Torus::Torus(string newName, int newMinorRadius, int newMajorRadius) : Shape(newName) {
	minorRadius = newMinorRadius;
	majorRadius = newMajorRadius;
}

//Accessors
int Torus::getMinorRadius() const {
	return minorRadius;
}
int Torus::getMajorRadius() const {
	return majorRadius;
}

//Mutators
void Torus::setMinorRadius(int newMinorRadius) {
	minorRadius = newMinorRadius;
}
void Torus::setMajorRadius(int newMajorRadius) {
	majorRadius = newMajorRadius;
}

//Calculate Area and perimeter
float Torus::getArea() const { //Really volume
	//(πr^2)(2πR)
	const float PI = 3.14159265359;
	return ((PI * minorRadius * minorRadius) * (2 * PI * majorRadius));
}
float Torus::getPerimeter() const { //Really Surface Area
	//4 × Pi ^ 2 × R × r
	//4(pi^2)Rr
	const float PI = 3.14159265359;
	return (4 * (PI * PI) * minorRadius * majorRadius);
}

//Overload for <<
ostream& operator << (ostream& outStream, const Torus& torusToPrint) {
	outStream << "Name: " << torusToPrint.getName() << endl;
	outStream << "Minor Radius: " << torusToPrint.getMinorRadius() << endl;
	outStream << "Major Radius: " << torusToPrint.getMajorRadius() << endl;
	outStream << "Volume: " << torusToPrint.getArea() << endl;
	outStream << "Surface Area: " << torusToPrint.getPerimeter() << endl;
	outStream << endl;
	return outStream;
}

//Destructor
Torus::~Torus() {

}