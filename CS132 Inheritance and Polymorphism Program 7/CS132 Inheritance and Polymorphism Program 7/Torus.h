#pragma once
#include "Shape.h"

class Torus : public Shape {
private:
	int minorRadius, majorRadius;
protected:
public:
	//Constructor
	Torus(string newName, int newMinorRadius, int newMajorRadius);

	//Accessors
	int getMinorRadius() const;
	int getMajorRadius() const;

	//Mutators
	void setMinorRadius(int newMinorRadius);
	void setMajorRadius(int newMajorRadius);

	//Calculate Area and perimeter
	float getArea() const;  //Really volume
	float getPerimeter() const; //Really Surface Area

	//Overload for <<
	friend ostream& operator << (ostream& outStream, const Torus& torusToPrint);

	//Destructor
	~Torus();
};