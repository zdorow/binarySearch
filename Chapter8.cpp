// Chapter8.cpp : 



#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int binarySearch(string [], int, string);

const int SIZE = 10;

int main()
{
	const int NUM_NAMES = 10;
	string names[NUM_NAMES] = { "baboon", "giraffe", "hippopotamus", "lion", "monkey", "rhinoceros", "tapir", "tiger", "wildebeest", "zebra" };
		// Insert your code to complete this program
	
	string name;
	int results;

	cout << "Please type what animal you are searching for: \n";
	cin >> name;

	results = binarySearch(names, NUM_NAMES, name);
	// If results contains -1 the name was not found.
	if (results == -1)
		cout << "That animal is not at this zoo. Please try again. \n";
	else
	{
		cout << "Congratgulations! That animal is in pen " << results << " in the Zoo.\n";
	}

	system("PAUSE");

	return 0;
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************

int binarySearch(string names[], int size, string value)
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (names[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (names[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half
	}
	return position;
}
