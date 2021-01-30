#include "NumberList.h"

//Constructor for Number List
//Creates a vector with the given numbers
//Generates a random target number between 100 and 1000 as well
NumberList::NumberList()
{
	for (int i = 1; i <= 10; i++)
	{
		GivenNumber* num = new GivenNumber(i);
		NumList.push_back(num);
		MemoryLocations.push_back(num);
	}

	//Run this code as long as certain criteria has been met
	do
	{
		targetNumber = calculateSolution();
	} while (targetNumber == NULL);
}

//Destructor for Number List
//Deletes all the members of the vector allocated on the heap
//Deletes targetNumber along with it
NumberList::~NumberList()
{
	for (int i = 0; i < MemoryLocations.size(); i++)
	{
		delete MemoryLocations[i];
	}

	delete targetNumber;
}

//Function to add two numbers from the list
void NumberList::add(int x, int y)
{
	//Variables needed to add
	int index1 = findNumber(x); //Index of first number
	std::vector<Number*>::iterator iter1; //Iterator variable for first number - Used for deleting entry in vector
	int index2 = findNumber(y); //Index of second number
	std::vector<Number*>::iterator iter2; //Iterator variable for second number - Used for deleting entry in vector
	bool fail = false; //Boolean variable that will be set to true in case the user enters the same number for input, and no second number of same value exists

	//If the values passed through the function are the same
	//Search the program for any second number of the same value
	//Set fail to true if not found
	if (x == y)
	{
		index1 = findNumber(x);
		if (index1 != -1)
		{
			index2 = findNumber(x, index1);
			if (index2 == -1)
			{
				std::cout << "You have tried to add a number to itself. Please try again." << std::endl;
				fail = true;
			}
		}
	}


	//If the index returned is -1, no such number exists in the list
	if (index1 == -1)
	{
		std::cout << "The number " << x << " that you have entered does not exist within the list. Please try again." << std::endl;
	}
	//If the index returned is -1, no such number exists in the list
	//Also, print this statement only if fail is set to false
	if (index2 == -1 && !fail)
	{
		std::cout << "The number " << y << " that you have entered does not exist within the list. Please try again." << std::endl;
	}

	//If the indices returned are both not -1, addition will be performed upon the values
	if (index1 != -1 && index2 != -1)
	{
		std::cout << "The numbers " << x << " and " << y << " will now be added." << std::endl;

		CompositeNumber* num = new CompositeNumber(NumList.at(index1), NumList.at(index2), '+');
		NumList.push_back(num);
		MemoryLocations.push_back(num);

		iter1 = iterator(x);
		NumList.erase(iter1);

		iter2 = iterator(y);
		NumList.erase(iter2);
	}
}

//Function to subtract two numbers from the list
void NumberList::subtract(int x, int y)
{
	//Variables needed to subtract
	int index1 = findNumber(x); //Index of first number
	std::vector<Number*>::iterator iter1; //Iterator variable for first number - Used for deleting entry in vector
	int index2 = findNumber(y); //Index of second number
	std::vector<Number*>::iterator iter2; //Iterator variable for second number - Used for deleting entry in vector
	bool fail = false; //Boolean variable that will be set to true in case the user enters the same number for input, and no second number of same value exists

	//If the values passed through the function are the same
	//Search the program for any second number of the same value
	//Set fail to true if not found
	if (x == y)
	{
		index1 = findNumber(x);
		if (index1 != -1)
		{
			index2 = findNumber(y, index1);
			if (index2 == -1)
			{
				std::cout << "You have tried to subtract a number from itself. Please try again." << std::endl;
				fail = true;
			}
		}
	}

	//If the index returned is -1, no such number exists in the list
	if (index1 == -1)
	{
		std::cout << "The number " << x << " that you have entered does not exist within the list. Please try again." << std::endl;
	}

	//If the index returned is -1, no such number exists in the list
	//Also, print this statement only if fail is set to false
	if (index2 == -1 && !fail)
	{
		std::cout << "The number " << y << " that you have entered does not exist within the list. Please try again." << std::endl;
	}

	//Check to see if the first integer is smaller than the second
	if (index1 != -1 && index2 != -1 && x < y)
	{
		std::cout << "That would result in a negative number. Hence, you cannot subtract from a larger number" << std::endl;
	}

	//Check to see if the first integer is equal to the second
	//Also, print this statement only if fail is set to false
	if (index1 != -1 && index2 != -1 && x == y && !fail)
	{
		std::cout << "That would result in a zero. Hence, you cannot subtract from an equal number" << std::endl;
	}

	//If the indices returned are both not -1 and first integer is greater than second, perform subtraction upon the values
	if (index1 != -1 && index2 != -1 && x > y)
	{
		std::cout << "The number " << y << " has been subtracted from " << x << "." << std::endl;

		CompositeNumber* num = new CompositeNumber(NumList.at(index1), NumList.at(index2), '-');
		NumList.push_back(num);
		MemoryLocations.push_back(num);

		iter1 = iterator(x);
		NumList.erase(iter1);

		iter2 = iterator(y);
		NumList.erase(iter2);
	}
}

//Function to multiply two numbers from the list
void NumberList::multiply(int x, int y)
{
	//Variables needed to multiply
	int index1 = findNumber(x); //Index for first number
	std::vector<Number*>::iterator iter1; //Iterator variable for first number - Used for deleting entry in vector
	int index2 = findNumber(y); //Index for second number
	std::vector<Number*>::iterator iter2; //Iterator variable for second number - Used for deleting entry in vector 
	bool fail = false; //Boolean variable that will be set to true in case the user enters the same number for input, and no second number of same value exists

	//If the values passed through the function are the same
	//Search the program for any second number of the same value
	//Set fail to true if not found
	if (x == y)
	{
		index1 = findNumber(x);
		if (index1 != -1)
		{
			index2 = findNumber(y, index1);
			if (index2 == -1)
			{
				std::cout << "You have tried to multiply a number with itself. Please try again." << std::endl;
				fail = true;
			}
		}
	}

	//If the index returned is -1, no such number exists within the list
	if (index1 == -1)
	{
		std::cout << "The number " << x << " that you have entered does not exist within the list. Please try again." << std::endl;
	}

	//If the index returned is -1, no such number exists within the list
	//Also, print this statement only if fail is set to false
	if (index2 == -1 && !fail)
	{
		std::cout << "The number " << y << " that you have entered does not exist within the list. Please try again." << std::endl;
	}

	//If the indices returned are both not -1, multiplication will be performed upon the values
	if (index1 != -1 && index2 != -1)
	{
		std::cout << "The numbers " << x << " and " << y << " will now be multiplied." << std::endl;

		CompositeNumber* num = new CompositeNumber(NumList.at(index1), NumList.at(index2), '*');
		NumList.push_back(num);
		MemoryLocations.push_back(num);

		iter1 = iterator(x);
		NumList.erase(iter1);

		iter2 = iterator(y);
		NumList.erase(iter2);
	}
}

//Function to divide two numbers from the list
void NumberList::divide(int x, int y)
{
	//Variables needed for divide
	int index1 = findNumber(x); //Index for first number
	std::vector<Number*>::iterator iter1; //Iterator variable for first number - Used for deleting entry in vector
	int index2 = findNumber(y); //Index for second number
	std::vector<Number*>::iterator iter2; //Iterator variable for second number - Used for deleting entry in vector
	bool fail = false; //Boolean variable that will be set to true in case the user enters the same number for input, and no second number of same value exists

	//If the values passed through the function are the same
	//Search the program for any second number of the same value
	//Set fail to true if not found
	if (x == y)
	{
		index1 = findNumber(x);
		if (index1 != -1)
		{
			index2 = findNumber(y, index1);
			if (index2 == -1)
			{
				std::cout << "You have tried to divide a number by itself. Please try again." << std::endl;
				fail = true;
			}
		}
	}

	//If the index returned is -1, no such number exists within the list
	if (index1 == -1)
	{
		std::cout << "The number " << x << " that you have entered does not exist within the list. Please try again." << std::endl;
	}

	//If the index returned is -1, no such number exists within the list
	//Also, print this statement only if fail is set to false
	if (index2 == -1 && !fail)
	{
		std::cout << "The number " << y << " that you have entered does not exist within this list. Please try again." << std::endl;
	}

	//If indices returned are both not -1
	//Check to see if dividing x by y would result in a remainder
	//Also, print this statement only if fail is set to false
	if (index1 != -1 && index2 != -1 && x % y != 0 && !fail)
	{
		std::cout << "That would result in a remainder. Hence, you cannot divide by a number that would result in a remainder." << std::endl;
	}

	//If indices returned are both not -1 and dividing x by y would not result in a remainder
	//Perform division with the values
	if (index1 != -1 && index2 != -1 && x % y == 0)
	{
		std::cout << x << " will now be divided by " << y << "." << std::endl;

		CompositeNumber* num = new CompositeNumber(NumList.at(index1), NumList.at(index2), '/');
		NumList.push_back(num);
		MemoryLocations.push_back(num);

		iter1 = iterator(x);
		NumList.erase(iter1);

		iter2 = iterator(y);
		NumList.erase(iter2);
	}
}

//Function to split a composite number from the list
void NumberList::split(int x)
{
	int index = findNumber(x);
	std::vector<Number*>::iterator iter = iterator(x);

	//If index returned is -1, no such number exists in the list
	if (index == -1)
	{
		std::cout << "The number " << x << " that you have entered does not exist within the list. Please try again." << std::endl;
	}
	//Else split the number depending on whether it is splittable or not
	else
	{
		if (!NumList[index]->isSplittable())
		{
			std::cout << "The first appearance of the number " << x << " you have entered is a given number." << std::endl;
			NumList[index]->split(NumList, iter);
		}
		else
		{
			std::cout << "The number " << x << " will now be split into its components" << std::endl;
			NumList[index]->split(NumList, iter);
		}
	}
}

//Function to check whether the target number is in the list
bool NumberList::targetFound()
{
	//If any number in the list matches with the value of the targetNumber, return a boolean accordingly
	for (int i = 0; i < NumList.size(); i++)
	{
		if (NumList[i]->getValue() == targetNumber->getValue())
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}

//Function to return the Number* at given index back to the user - Temp
Number* NumberList::at(int index)
{
	return NumList[index];
}

//Function to return a copy of the vector to the user
std::vector<Number*>& NumberList::returnVector()
{
	return NumList;
}

//Function to print the current vector along with the target number to the user
void NumberList::print()
{
	std::cout << "Your target number is " << targetNumber->getValue() << ". Your current numbers are ";

	for (int i = 0; i < NumList.size(); i++)
	{
		NumList[i]->printMe();
		if (i != NumList.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << '.';

	std::cout << std::endl;
}

//Function to find a number of given value for the user
//Returns the index of the first occurrence
int NumberList::findNumber(int number)
{
	for (int i = 0; i < NumList.size(); i++)
	{
		if (NumList[i]->getValue() == number)
		{
			return i;
		}
		else
		{
			continue;
		}
	}
	return -1;
}


//Function to find a number of given value for the user
//Overloaded version of findNumber function
//To be run if both numbers entered as input are the same
//Returns the index of the second occurrence after the given index
int NumberList::findNumber(int number, int index)
{
	for (int i = 0; i < NumList.size(); i++)
	{
		if (i == index && NumList[i]->getValue() == number)
		{
			continue;
		}
		else if (NumList[i]->getValue() == number)
		{
			return i;
		}
		else
		{
			continue;
		}
	}
	return -1;
}

//Function to return the iterator of the number of given value to the user
//Returns an iterator accordingly accordingly
std::vector<Number*>::iterator NumberList::iterator(int number)
{
	for (std::vector<Number*>::iterator it = NumList.begin(); it != NumList.end(); it++)
	{
		if ((*it)->getValue() == number)
		{
			return it;
		}
		else
		{
			continue;
		}
	}
}

//Function to return a sample solution to the user
std::string NumberList::sampleSolution()
{
	return targetNumber->stringRep();
}

//Function to calculate a target number along with an example solution
//Returns a Number* accordingly
Number* NumberList::calculateSolution()
{
	srand((unsigned)time(NULL));

	std::vector<Number*> numberList;
	std::vector<Number*> memoryLocations;

	int index1 = 0; //Index for first number
	int index2 = 0; //Index for second number
	char operation = ' '; //Operation to be performed on the numbers
	int command = 0; //Number to decide which operation will be performed

	int number1 = 0; //Value of first number
	int number2 = 0; //Value of second number

	bool fail = false; //Boolean variable that is set to true if a solution has not been produced

	bool target = false; //Boolean that is set to true if a suitable target has been found

	std::vector<Number*>::iterator iter1; //Iterator for first number
	std::vector<Number*>::iterator iter2; //Iterator for second number

	//Temporary Number* variables to initialise targetNum variable
	Number* temp1 = new GivenNumber(0);
	Number* temp2 = new GivenNumber(0);

	Number* targetNum = new CompositeNumber(temp1, temp2, '+');

	//Initialise numberList and memoryLocations variables
	for (int i = 1; i <= 10; i++)
	{
		GivenNumber* num = new GivenNumber(i);
		numberList.push_back(num);
		memoryLocations.push_back(num);
	}

	//Loop while target has not been found
	while (!target)
	{
		//Randomly generate either 0 or 1
		//If number generated is 0, perform addition
		//If number generated is 1, perform multiplication
		command = rand() % 2;
		if (command == 0)
		{
			operation = '+';
		}
		else
		{
			operation = '*';
		}

		//Loop while conditions have not been met
		while (true)
		{
			index1 = rand() % numberList.size();
			index2 = rand() % numberList.size();

			while (index2 == index1 || numberList[index2]->getValue() > 1000)
			{
				index2 = rand() % numberList.size();
			}
			break;
		}

		number1 = numberList[index1]->getValue();
		number2 = numberList[index2]->getValue();

		//If the product of number1 and number2 is greater than 999 and operation is equal to * , set operation to +
		//Because multiplying them would result in an invalid value
		if (number1 * number2 > 999 && operation == '*')
		{
			operation = '+';
		}
		
		//If operation is equal to +
		//Perform addition with the two values
		if (operation == '+')
		{
			CompositeNumber* num = new CompositeNumber(numberList[index1], numberList[index2], operation);
			numberList.push_back(num);
			memoryLocations.push_back(num);

			for (std::vector<Number*>::iterator it = numberList.begin(); it != numberList.end(); it++)
			{
				if ((*it)->getValue() == number1)
				{
					numberList.erase(it);
					break;
				}
			}

			for (std::vector<Number*>::iterator it = numberList.begin(); it != numberList.end(); it++)
			{
				if ((*it)->getValue() == number2)
				{
					numberList.erase(it);
					break;
				}
			}
		}
		//Else perform multiplication with the two values
		else
		{
			CompositeNumber* num = new CompositeNumber(numberList[index1], numberList[index2], operation);
			numberList.push_back(num);
			memoryLocations.push_back(num);

			for (std::vector<Number*>::iterator it = numberList.begin(); it != numberList.end(); it++)
			{
				if ((*it)->getValue() == number1)
				{
					numberList.erase(it);
					break;
				}
			}

			for (std::vector<Number*>::iterator it = numberList.begin(); it != numberList.end(); it++)
			{
				if ((*it)->getValue() == number2)
				{
					numberList.erase(it);
					break;
				}
			}
		}

		//Iterate throught the number list and check if any value produced meets the criteria
		//Set targetNum to this value in the case it does
		//Set target to true
		for (int i = 0; i < numberList.size(); i++)
		{
			if (numberList[i]->getValue() > 100 && numberList[i]->getValue() < 1000)
			{
				targetNum = numberList[i];
				target = true;
			}
		}

		//If the numberlist hits zero, it means the program has produced invalid values
		//Set fail to true and break out of loop
		if (numberList.size() == 1)
		{
			fail = true;
			break;
		}
	}

	//Deleting all the values stored in memoryLocations
	//Except for targetNum, as it needs to be returned
	for (int i = 0; i < memoryLocations.size(); i++)
	{
		if (memoryLocations[i]->getValue() != targetNum->getValue())
		{
			delete memoryLocations[i];
		}
	}
	//Delete the temporary variables allocated on the heap
	delete temp1;
	delete temp2;

	//If fail is true, return a NULL value to the function that has called this function
	if (fail)
	{
		return NULL;
	}

	//Return targetNum in the case that a value has been successfully produced
	return targetNum;
}