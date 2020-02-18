#pragma once
#include "shape.h"

class Cylinder : public Shape {
private:
	int baseRadius, height;
protected:
public:
	//Constructor
	Cylinder(string newName, int newBaseRadius, int newHeight);

	//Accessors
	int getBaseRadius() const;
	int getHeight() const;

	//Mutators
	void setBaseRadius(int newBaseRadius);
	void setHeight(int newHeight);

	//Calculate Area and perimeter
	float getArea() const;  //Really volume
	float getPerimeter() const; //Really Surface Area

	//Overload for <<
	friend ostream& operator << (ostream& outStream, const Cylinder& cylinderToPrint);

	//Destructor
	~Cylinder();
};
