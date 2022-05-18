// Useful.cpp
// Author: Eric Yelong Tabuchi
// Email: e.tabuchi@wustl.edu
// The purpose of this source file is to define the helper functions
// that were declared in Useful.h in order to assist in guiding the user
// on how to use the program as well as interpreting user input which will
// be implemented in TicTacToe.cpp

#include "Useful.h"

using namespace std;

// Outputs usage message if an error occurs during execution
void usage(char* program_name, string message, return_values error_type)
{
    if (error_type == num_arg_error) 
    {
        cout << "How to use: " << program_name << endl;
    }
    else 
    {
        cout << "Error " << error_type << endl;
    }
    cout << message;
}

// Changes input text into lowercase
void toLowerCase(string& input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        // Check if any of the characters in the string are uppercase letters
        if ('A' <= input[i] && input[i] <= 'Z')
        {
            input[i] = input[i] + 32; // Change to lowercase using binary addition
        }
    }
}

// Uses isdigit to check if the characters in a string or entirely numerical
bool is_number(string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }
    return true;
}

// Formats a set of coordinates of the form "0, 0" into "0 0"
// Also checks if the user had a comma to begin with to make it acceptable
bool formatCoor(string& input)
{
    // Even though our formatted string will not have a comma, the user 
    // should still follow the rules behind the program. They need a comma in their
    // coordinate response. Otherwise, the program will not accept it.

    bool hasComma = false; // This bool checks if the string contains a comma
    int commaCounter = 0;
    // Loop throughout string and find the comma character
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' '; // replace commas with spaces
            hasComma = true;
            commaCounter++;
        }
    }

    return hasComma && commaCounter == 1;
}