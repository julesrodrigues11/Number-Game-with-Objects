#include "NumberList.h"

//Function to change the command passed to upper case
void toUpper(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

//Function to check whether the string passed through is only alphabets
//Returns a boolean accordingly
bool isAlpha(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 1 && isalpha(str[i]))
		{
			return true;
		}
		else if (isalpha(str[i]))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
}

//Function to check whether the string passed through is only digits
//Returns a boolean accordingly
bool isDigit(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i == str.length() - 1 && isdigit(str[i]))
		{
			return true;
		}
		else if (isdigit(str[i]))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
}

//Function to process string input
//Calls functions respectively depending upon what is passed through the function
//Takes the string to be processed and an object of type NumberList as parameters
std::string parseString(std::string str, NumberList& numberList)
{
	std::string temp = ""; //Temporary string variable to hold the current value of the string
	std::string command = ""; //Value to be returned at the end of the function
	int count = 0; //Counter variable to keep track
	int int1 = 0; //Variable to hold the value of the first number
	int int2 = 0; //Variable to hold the value of the second number

	bool fail = false; //Boolean that is set to true if the user enters an invalid value
	bool quit = false; //Boolean that is set to true if the user enters quit as input
    bool list = false; //Boolean that is set to true if the user enters list as input

    //For loop that iterates through the string
    for (int i = 0; i < str.length(); i++)
    {
        //If the current character is a ' ' and the count is equal to 0
        //Or if count is equal to 0 and it is the end of the string (in the event user enters "quit" or "list" as input)
        if ((str[i] == ' ' && count == 0) || (count == 0 && i == str.length() - 1))
        {
            if (count == 0 && i == str.length() - 1)
            {
                temp = temp + str[i];
            }
            count++;
            //Check if the user has entered any non-alphabets as input
            //Run function toUpper on temp if true
            //Set fail to true otherwise
            if (isAlpha(temp))
            {
                toUpper(temp);
                command = temp;
            }
            else
            {
                fail = true;
                break;
            }
            temp = "";
        }
        //If the current character is a ' ' and count is equal to 1
        //Or if count is equal to 1 and it is the end of the string (in the event user enters something like "split 8" as input)
        else if ((str[i] == ' ' && count == 1) || (count==1 && i == str.length() - 1))
        {
            if (i == str.length() - 1)
            {
                temp = temp + str[i];
            }

            //Check if the user has entered any non-digits as input
            //Assign value to int1 if true
            //Set fail to true otherwise
            if (isDigit(temp))
            {
                int1 = std::stoi(temp);
                count++;
                temp = "";
            }
            else
            {
                fail = true;
                break;
            }
        }
        //If the current character is a ' ' and count is equal to 2
        else if (count == 2 && i == str.length() - 1)
        {
            temp = temp + str[i];

            //Check if the user has entered any non-digits as input
            //Assign value to int2 if true
            //Set fail to true otherwise
            if (isDigit(temp))
            {
                int2 = std::stoi(temp);
                count++;
                temp = "";
            }
            else
            {
                fail = true;
                break;
            }
        }
        //Add the current character to the temp variable if none of the above checks are true
        else
        {
            temp = temp + str[i];
        }
    }

    //If the user has entered quit, set quit to true
    if (command == "QUIT")
    {
        quit = true;
    }
    //If the user has entered add, run the add function on int1 and int2
    else if (command == "ADD")
    {
        numberList.add(int1, int2);
    }
    //If the user has entered subtract, run the subtract function on int1 and int2
    else if (command == "SUBTRACT")
    {
        numberList.subtract(int1, int2);
    }
    //If the user has entered multiply, run the multiply function on int1 and int2
    else if (command == "MULTIPLY")
    {
        numberList.multiply(int1, int2);
    }
    //If the user has entered divide, run the divide function on int1 and int2
    else if (command == "DIVIDE")
    {
        numberList.divide(int1, int2);
    }
    //If the user has entered split, run the split function on int1
    else if (command == "SPLIT")
    {
        numberList.split(int1);
    }
    //If the user has entered list, set list to true
    else if (command == "LIST")
    {
        list = true;
    }
    //Set fail to true if the user has entered anything else as input
    else
    {
        fail = true;
    }

    //If fail is equal to true, print error message
    if (fail)
    {
        std::cout << "You have entered an invalid expression. Please try again" << std::endl;
    }

    //If the target number has been found, return "FOUND" to the function that has called this function
    if (numberList.targetFound())
    {
        return "FOUND";
    }

    //If the user has input list as a command, print the list to the user
    if (list)
    {
        std::cout << std::endl << "The number list will now be printed" << std::endl;
        numberList.print();
    }

    //Print the number list if the user hasn't entered either quit or list as input
    if (!quit)
    {
        std::cout << std::endl;
        //If the user has entered list, it would result in two printings. Hence, this check
        if (!list)
        {
            numberList.print();
        }
        else
        {
            list = false;
        }
    }

    //Return the command string to the function that has called this function
    return command;
}

//Function to handle the game loop
void gameLoop()
{
    //Create an object of class NumberList
    NumberList numList;

    //String variables
	std::string command; //For input
    std::string c; //To hold the value that is returned by parseString

    //Game instructions
    std::cout << "Enter 'ADD', 'SUBTRACT', 'MULTIPLY' or 'DIVIDE' to perform operations on the values given" << std::endl;
    std::cout << "Enter your command in the format 'ADD 5 6' to perform an addition on the values 5 and 6" << std::endl;
    std::cout << "Enter 'SPLIT' to split a number into two values" << std::endl;
    std::cout << "Enter your command in the format 'SPLIT 26' to perform a split on the value 26" << std::endl;
    std::cout << "Enter 'LIST' to print a list of the current numbers" << std::endl;
    std::cout << "Enter 'QUIT' to exit the application" << std::endl << std::endl;


    //Calling print function for numList before starting the game loop
    numList.print();

    //While loop that returns as long as user hasn't found the target number or entered quit as input
	while (true)
	{
        std::cout << "Enter your command here : ";
        std::getline(std::cin, command); //Input command
        c = parseString(command, numList); //Run parseString function

        //Break out of main loop if user entered quit as input
        //Print a possible solution to the user
        if (c == "QUIT")
        {
            std::cout << "\nYou have decided to quit the game without finding the solution" << std::endl;
            std::cout << "One possible solution was " << numList.sampleSolution() << std::endl;
            break;
        }
        //Break out of main loop if user has found the target number
        //Print the final list to the user
        if (c == "FOUND")
        {
            std::cout << "\nThe target number has been found. Good job!" << std::endl;
            std::cout << "This is your final list" << std::endl;
            numList.print();
            std::cout << std::endl << "The game will now shut down" << std::endl;
            break;
        }
	}
}

//Main function
//Runs the game loop and prints a goodbye message upon exiting the game
int main()
{ 
    gameLoop();

    std::cout << "\nThanks for playing this game! :)" << std::endl;

	return 1;
}