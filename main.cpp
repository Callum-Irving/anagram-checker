#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void delSpaces(std::string& str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

void convertToLower(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
}

int main()
{
	bool done = false;

	//GET INPUTS
	std::string firstString;
	std::cout << "First phrase: ";
	std::getline(std::cin, firstString);
	delSpaces(firstString);
	convertToLower(firstString);

	std::string secondString;
	std::cout << "Second phrase: ";
	std::getline(std::cin, secondString);
	delSpaces(secondString);
	convertToLower(secondString);

	//CONVERT STRINGS TO ARRAYS
	std::vector<char> firstVector(firstString.length());
	std::vector<char> secondVector(secondString.length());

	unsigned int i = 0;
	unsigned int n = 0;

	for (i = 0; i < firstVector.size(); i++)
	{
		firstVector[i] = firstString[i];
	}

	for (i = 0; i < secondVector.size(); i++)
	{
		secondVector[i] = secondString[i];
	}

	//CHECK IF LENGTHS ARE SAME
	if (firstVector.size() != secondVector.size())
	{
		std::cout << "Not anagram" << std::endl;
		done = true;
	}

	//TURN COMMON CHARACTERS INTO 0s
	char a;

	for (i = 0; i < secondVector.size(); i++)
	{
		a = secondVector[i];
		for (n = 0; n < firstVector.size(); n++)
		{
			if (firstVector[n] == a)
			{
				firstVector[n] = '0';
				break;
			}
		}
	}

	//CREATE AN ARRAY THE SIZE OF FIRST ARRAY AND FILL WITH 0s SO THAT THEY CAN BE COMPARED
	std::vector<char> final_test(firstVector.size());
	for (i = 0; i < final_test.size(); i++)
	{
		final_test[i] = '0';
	}

	//COMPARE ARRAYS
	bool is_anagram = true;

	for (i = 0; i < firstVector.size(); i++)
	{
		if (firstVector[i] != final_test[i])
		{
			is_anagram = false;
		}
	}

	//DISPLAY FINAL ANSWER
	if (done == false)
	{
		if (is_anagram == true)
		{
			std::cout << "Is anagram" << std::endl;
		}
		else
		{
			std::cout << "Not anagram" << std::endl;
		}
	}

	std::cin.get();
}
