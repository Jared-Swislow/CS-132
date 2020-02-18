#pragma once
#include <string>

using namespace std;

class Shape {
private:
	string name;
protected:
	//Constructor with new name
	Shape(string newName);

public:
	//Mutator for name
	void setName(string newName);

	//Accessor for name
	string getName() const;

	//Calculate Area and perimeter
	virtual float getArea() const = 0;
	virtual float getPerimeter() const = 0;

	//Virtual method for cout
	//virtual friend ostream& operator << (ostream& outStream, const Rectangle& rectToPrint) = 0;

	virtual ~Shape();
};