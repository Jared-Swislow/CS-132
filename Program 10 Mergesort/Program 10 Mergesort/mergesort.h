//Jared Swislow
//Program 10: Mergesort
//My results from the program are in Timing results.txt, included in the Source files

#pragma once

using namespace std;

void merge(int a[], int numElements);

void mergeSort(int a[], int numElements) {
    if (numElements > 1) {
        //MergeSorts from the beginning of the array to the middle, rounding down
        mergeSort(a, static_cast<int>(floor(numElements / 2.0)));
        //MergeSorts from the middle of the array(starting at 
        // the address of the first element not called by the last
        // mergesort) to the end, rounding up
        mergeSort(&(a[static_cast<int>(floor(numElements / 2.0))]), static_cast<int>(ceil(numElements / 2.0)));
        merge(a, numElements);
    }
}

void merge(int a[], int numElements) {
    int* tempArray = new int[numElements];
    //Copying the two arrays into one array
    for (int i = 0; i < numElements; i++) {
        tempArray[i] = a[i];
    }
    int* leftPtr = &(tempArray[0]);
    int* rightPtr = &(tempArray[static_cast<int>(floor(numElements / 2.0))]);
    int* copyPtr = &(a[0]);
    //If we've copied all of both arrays (keeps repeating if either is in bounds)
    while ((leftPtr < &(tempArray[static_cast<int>(floor(numElements / 2.0))])) || (rightPtr < &(tempArray[numElements]))) {
        //If we've copied the whole left array (left is out of bounds)
        if (leftPtr >= &(tempArray[static_cast<int>(floor(numElements / 2.0))])) {
            *copyPtr = *rightPtr;
            copyPtr++;
            rightPtr++;
        }
        //If we've copied the whole right array
        else if (rightPtr >= &(tempArray[numElements])) {
            *copyPtr = *leftPtr;
            copyPtr++;
            leftPtr++;
        }
        //If the value at leftPtr < the value at rightPtr
        else if (*leftPtr < *rightPtr) {
            *copyPtr = *leftPtr;
            copyPtr++;
            leftPtr++;
        }
        //If the value at rightPtr < the value at leftPtr
        else {
            *copyPtr = *rightPtr;
            copyPtr++;
            rightPtr++;
        }
    }
    delete[] tempArray;
}
