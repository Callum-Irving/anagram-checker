#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string delSpaces(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

std::string convert_to_lower(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
    return str;
}

int main()
{
    bool done = false;

    //GET INPUTS
    std::string first_string;
    std::cout << "First phrase: ";
    std::getline(std::cin, first_string);
    first_string = delSpaces(first_string);
    first_string = convert_to_lower(first_string);

    std::string second_string;
    std::cout << "Second phrase: ";
    std::getline(std::cin, second_string);
    second_string = delSpaces(second_string);
    second_string = convert_to_lower(second_string);

    //CONVERT STRINGS TO ARRAYS
    std::vector<char> firstVector(first_string.length());
    std::vector<char> secondVector(second_string.length());

    unsigned int i = 0;
    unsigned int n = 0;

    for (i = 0; i < firstVector.size(); i++)
    {
        firstVector[i] = first_string[i];
    }

    for (i = 0; i < secondVector.size(); i++)
    {
        secondVector[i] = second_string[i];
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
