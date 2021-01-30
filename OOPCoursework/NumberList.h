#pragma once
#include "Number.h"
#include <ctime>
#include <cstdlib>

class NumberList
{
	Number* targetNumber; // Integer that holds the target number that the user needs to reach at
	std::vector<Number*> NumList; // Vector of Number* that holds the numbers
	std::vector<Number*> MemoryLocations; // Vector of Number* that holds all the memory locations of the numbers that have been created so far

//Public Functions for NumberList class
public:

	NumberList(); // Constructor
	~NumberList(); // Destructor

	void add(int x, int y); // Function to add two numbers in the number list
	void subtract(int x, int y); // Function to subtract two numbers in the number list
	void multiply(int x, int y); // Function to multiply two numbers in the number list
	void divide(int x, int y); // Function to divide two numbers in the number list
	void split(int x); // Function to split a composite number

	Number* at(int index); // Function to return number at given index in the vector -  Temporary for now
	std::vector<Number*>& returnVector(); // Function to create a copy of the NumList vector

	bool targetFound(); // Function that returns a boolean if the target number is found
	void print(); // Prints all the elements in the vector along with the target number

	int findNumber(int number); // Function that finds a number and returns the index of the number from the list
	int findNumber(int number, int index); // Overloaded version of findNumber. To be run if the user enters the same values in the command
	std::vector<Number*>::iterator iterator(int number); // Function that finds a number and returns the iterator associated with this number

	std::string sampleSolution(); //Function to return a sample solution
	Number* calculateSolution(); //Function to calculate a target number along with an example solution
	
};