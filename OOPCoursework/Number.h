#pragma once
#include <iostream>
#include <vector>
#include <string>

//Base Class Number
class Number
{
protected:
	int value; //Integer value of the Number
	bool splittable; //Boolean that holds whether a Number is splittable or not
	std::string stringRepresentation; //String representation of the Number
public:
	Number(int _value, bool _splittable); //Constructor
	virtual int getValue(); //Returns the value of the Number to the user
	virtual bool isSplittable(); //Returns the value of splittable to the user
	virtual void split(std::vector<Number*>& myNumbers, std::vector<Number*>::iterator iter); //Adds the numbers from which this Number was composed to the list of numbers
	virtual void printMe(); //Prints the value of the Number to the user
	virtual std::string stringRep(); //Function to return the string representation of the Number
};

//Derived Class GivenNumber
class GivenNumber : public Number
{
private:

public:
	GivenNumber(int _value); //Constructor
	virtual int getValue(); //Returns the value of GivenNumber to the user
	virtual bool isSplittable(); //Returns the value of splittable to the user (Always false for a GivenNumber)
	virtual void split(std::vector<Number*>& myNumbers, std::vector<Number*>::iterator iter); //Adds the numbers from which this GivenNumber was composed to the list of numbers (Always prints an error message when run)
	virtual void printMe(); //Prints the value of the GivenNumber to the user
	virtual std::string stringRep(); //Function to return the string representation of the GivenNumber
};

//Derived Class CompositeNumber
class CompositeNumber : public Number
{
private:
	char operation; //Operation used to obtain CompositeNumber
	Number* value1; //Value 1 used to obtain CompositeNumber
	Number* value2; //Value 2 used to obtain CompositeNumber
public:
	CompositeNumber(Number* _value1, Number* _value2, char _operation); //Constructor
	void setValue(int _value); //Function to set the value of the CompositeNumber
	virtual int getValue(); //Returns the value of the CompositeNumber to the user
	virtual bool isSplittable(); //Returns the value of splittable to the user (Always true for a CompositeNumber)
	virtual void split(std::vector<Number*>& myNumbers, std::vector<Number*>::iterator iter); //Adds the numbers from which this CompositeNumber was composed to the list of numbers (Always runs the split operation when run)
	virtual void printMe(); //Prints the value of the CompositeNumber to the user
	virtual std::string stringRep(); //Function to return the string representation of the CompositeNumber
};