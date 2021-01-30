#include "Number.h"

//Base Class Number Functions
//Constructor for base Number class
Number::Number(int _value, bool _splittable) : value(_value), splittable(_splittable), stringRepresentation(std::to_string(_value)) {}

//Function to return the value of the number to the user
int Number::getValue()
{
	return value;
}

//Function to return whether a number is splittable or not to the user
bool Number::isSplittable()
{
	return splittable;
}

//Function to split a Number
void Number::split(std::vector<Number*>& myNumbers, std::vector<Number*>::iterator iter) {}

//Function to print the value of a Number
void Number::printMe()
{
	std::cout << value;
}

//Function to return the string representation of a Number
std::string Number::stringRep()
{
	return stringRepresentation;
}

//Derived Class GivenNumber Functions
//Constructor for GivenNumber class
GivenNumber::GivenNumber(int _value) : Number::Number(_value, false)
{
}

//Function to return the value of the GivenNumber to the user
int GivenNumber::getValue()
{
	return GivenNumber::value;
}

//Function to return whether a GivenNumber is splittable or not to the user (Always false in the case of a given number)
bool GivenNumber::isSplittable()
{
	return GivenNumber::splittable;
}

//Function to split a GivenNumber (Always gives an error message in the case of a given number)
void GivenNumber::split(std::vector<Number*>& myNumbers, std::vector<Number*>::iterator iter)
{
	std::cout << "You cannot split a given number. Please try using another command." << std::endl;
}

//Function to print the value of a GivenNumber
void GivenNumber::printMe()
{
	std::cout << GivenNumber::getValue();
}

//Function to return the string representation of a GivenNumber
std::string GivenNumber::stringRep()
{
	return GivenNumber::stringRepresentation;
}

//Derived Class CompositeNumber Functions
//Constructor for CompositeNumber class
CompositeNumber::CompositeNumber(Number* _value1, Number* _value2, char _operation) : Number::Number(0, true), value1(_value1), value2(_value2), operation(_operation)
{
	int result = 0;
	switch (operation)
	{
	case '+':
		result = _value1->getValue() + _value2->getValue();
		break;
	case '-':
		if (_value2->getValue() > _value1->getValue())
		{
			std::cout << "You cannot subtract a greater number from a smaller one " << std::endl;
			std::cout << "Please try again" << std::endl;
			break;
		}
		result = _value1->getValue() - _value2->getValue();
		break;
	case '*':
		result = _value1->getValue() * _value2->getValue();
		break;
	case '/':
		if (_value1->getValue() % _value2->getValue() != 0)
		{
			std::cout << "You cannot divide by a number that will result in a remainder " << std::endl;
			std::cout << "Please try again" << std::endl;
			break;
		}
		result = _value1->getValue() / _value2->getValue();
		break;
	}
	this->setValue(result);
	stringRepresentation = '(' + value1->stringRep() + operation + value2->stringRep() + ')';
}


//Function to return the value of a CompositeNumber to the user
int CompositeNumber::getValue()
{
	return CompositeNumber::value;
}

//Function to return whether a CompositeNumber is splittable or not to the user (Always true in the case of a CompositeNumber)
bool CompositeNumber::isSplittable()
{
	return CompositeNumber::splittable;
}

//Function to set the value of a CompositeNumber
//Used in constructor
void CompositeNumber::setValue(int _value)
{
	CompositeNumber::value = _value;
}

//Function to split a CompositeNumber
void CompositeNumber::split(std::vector<Number*>& myNumbers, std::vector<Number*>::iterator iter)
{
	Number* num1 = value1;
	Number* num2 = value2;

	myNumbers.push_back(num1);
	myNumbers.push_back(num2);

	myNumbers.erase(iter);
}

//Function to print the value of a CompositeNumber
void CompositeNumber::printMe()
{
	std::cout << CompositeNumber::getValue() << "=" << stringRepresentation;
}

//Function to return the string representation of a CompositeNumber
std::string CompositeNumber::stringRep()
{
	return CompositeNumber::stringRepresentation;
}