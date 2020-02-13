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
};