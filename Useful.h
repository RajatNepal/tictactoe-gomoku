// Useful.h
// Eric Tabuchi, Arden Chen, Rajat Nepal
//e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
//Team EAR
// The purpose of this header file is to store useful / relevant information
// for the user to have. This relevant information takes the form of two enumerations
// containing labels for return_values that are possible throughout the function and
// relevant information to avoid hard coding as many values as possible. Other helpful
// aspects to the project are located here such as the usage function to output a helpful
// message to guide a user on how to use the function as well as helper functions to 
// assist when the game is running.

#pragma once

#include <iostream>

// Return values that the program will output depending on how the game ended up (or if an error occurred)
enum return_values 
{
	success,	    // (0) - successful execution (i.e. a player won a game of tic-tac-toe)
	num_arg_error,  // (1) - incorrect number of command line arguments / invalid numerical inputs
	name_error,     // (2) - did not input a viable game name
	game_quit,      // (3) - player ended game early by quitting
	game_draw,      // (4) - neither player ended up winning
	string_err,     // (5) - inputted string instead of integer input
	extra_err,      // (6) - input error with extra credit gomoku parameters (i.e. too small of a game board)
};

// Relevant information to the program
enum rel_info
{
	program_name = 0,     // (0) - index 0 of argv (i.e. program's name)
	game_name = 1,		  // (1) - index 1 of argv (i.e. game's name)
	game_num_length = 2,  // (2) index 2 of argv (i.e. gomoku length of board sides)	
	game_num_win = 3,	  // (3) index 3 of argv (i.e. gomoku win number)
	expect_arg = 2,		  // (2) - number of arguments on the command line
	expect_arg_g1 = 3,
	expect_arg_g2 = 4, // (4) - number of expected arguments on command line for gomoku (assuming extra credit)
	ttt_width = 5,     // (5) - # of columns for tic-tac-toe game board
	ttt_height = 5,    // (5) - # of rows for tic-tac-toe game board
	gomo_width = 21,   // (19) - default # of columns for gomoku board
	gomo_height = 21,  // (19) - default # of rows for gomoku board
	first_turn = 1,    // (1)
	win_count = 5,     // (5) - number of pieces needed to win in gomoku
	ttt_setwidth = 2,  // (2) - used with setw for spacing
	gomo_setwidth = 3, // (3) - used with setw for spacing
};

// IDs for game type to differentiate between them
enum game_type
{
	tictactoe,        // (0)
	gomoku,           // (1)
};

// Usage function to let user know about different errors that occurred during execution / non-successful cases
void usage(char* program_name, std::string message, return_values error_type);

// Changes input text into lowercase
void toLowerCase(std::string& input);

// Uses isdigit to check if the characters in a string or entirely numerical
bool is_number(std::string input);

// Formats a set of coordinates of the form "0, 0" into "0 0"
// Will return true if the formatted coordinates are acceptable and false otherwise
bool formatCoor(std::string& input);