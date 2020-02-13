#include "Shape.h"

using namespace std;

Shape::Shape(string newName) {
	name = newName;
}

void Shape::setName(string newName) {
	name = newName;
}

string Shape::getName() const {
	return name;
}