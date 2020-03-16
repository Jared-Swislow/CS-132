// File Name:  MergeSortDriver.cpp
// Author:  Cliff Snyder (csnyder@everett.edu)
// Description:  Driver for a function that implements a merge sort
//
// Top Down Design
//    Load an array with random numbers
//    Display the array contents (comment out for larger arrays)
//    Sort the array with MergeSort
//    Display the array contents (comment out for larger arrays)

#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include "mergesort.h"
using namespace std;

// Global types

// Global consts
const int NUM_INTS(250000);

// Global function declarations
void displayArray(string name, int array[], int numElements, bool isSorted = false);

int main()
{
	//  Initialize variables
	static int array[NUM_INTS];
	srand(static_cast<unsigned int> (time(0)));

	cout << "Sorting int array of " << NUM_INTS << " elements." << endl;

	// Load random numbers into the array
	for (int i = 0; i < NUM_INTS; i++)
	{
		array[i] = rand();
	}
	//displayArray("Before: ", array, NUM_INTS); // comment out for large data sets

	// start timing here
	time_t startTime = clock();
	mergeSort(array, NUM_INTS);
	time_t endTime = clock();
	// end timing here

	//displayArray("After : ", array, NUM_INTS, true);  // comment out for large data sets - 3rd parameter confirms list is sorted

	// Display the total time taken
	cout << "Sort took " << endTime - startTime << " ticks" << endl;

	return 0;
}

// Functions

// Function to display the contents of an array & optionally confirm list is sorted
void displayArray(string name, int array[], int numElements, bool isSorted)
{
	cout << name;
	for (int i = 0; i < numElements; i++)
	{
		if (isSorted && i > 0)
		{
			assert(array[i - 1] <= array[i]);
		}
		cout << array[i];
		if (i < numElements - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}
