#pragma once
#include <string>

using namespace::std;

class MovieRole {
private:
	string title, role;
	int yearReleased;
public:
	MovieRole() {
		title = "";
		role = "";
		yearReleased = 0;
	}
	MovieRole(string newTitle, string newRole, int newYearReleased) {
		title = newTitle;
		role = newRole;
		yearReleased = newYearReleased;
	}

	//Accessors
	string getTitle() {
		return title;
	}
	string getRole() {
		return role;
	}
	int getYearReleased() {
		return yearReleased;
	}

	//Mutators
	void setTitle(string newTitle) {
		title = newTitle;
	}
	void setRole(string newRole) {
		role = newRole;
	}
	void setYearReleased(int newYearReleased) {
		yearReleased = newYearReleased;
	}

	//>> overload
	friend istream& operator >>(istream& in, MovieRole& movieRole) {
		string inputLine;
		const char tab(9);
		
		getline(in, inputLine, tab); // Try to read a title
		
		if (!in.eof()) { // If the read was successful
			movieRole.setTitle(inputLine);// Store the title
			getline(in, inputLine, tab);// Read the release year
			movieRole.setYearReleased(stoi(inputLine)); // Convert to int & store
			getline(in, inputLine);             // Read the role
			movieRole.setRole(inputLine);       // Store the role
		}
		return(in);
	}

	//<< overload
	friend ostream& operator << (ostream& outStream, const MovieRole& movieRole){
		outStream << movieRole.title << " was released in ";
		outStream << movieRole.yearReleased << " in which the actor played ";
		outStream << movieRole.role << "." << endl;
		return outStream;
	}
};