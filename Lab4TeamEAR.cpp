/*
Eric Tabuchi, Arden Chen, Rajat Nepal
e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
Team EAR
Lab4
Lab4TeamEAR.cpp : This file contains the 'main' function.Program execution begins and ends there.
Also includes multiple helper functions :
a lowercase function to make strings lowercase
an error message function describing errors
a usage message function telling a user how to use the program
(1)This program builds on the parsing code from Lab 1 and the gameboard from Lab 2.
(2)This program allows two users to play tic tac toe
(3)This program can recognize ties, wins, and quittting the game in the middle
(4)This program also spots errors such as not inputting the correct arguments to run
It gives a helpful error messageand usage message if this happens.
*/



#include "Game_Piece.h"
#include "Game_Board.h"
#include "GameBase.h"
#include "TicTacToe.h"
#include "Useful.h"
#include <iostream>
#include <sstream>

using namespace std;

return_values execution = success;

rel_info title = program_name;
rel_info arg = game_name;
rel_info comm_arg = expect_arg;

int main(int argc, char* argv[])
{
	// Extra Credit: One Parameter
	if (argc == expect_arg_g1)
	{
		// If the first parameter is not an integer, return error
		if (!is_number(argv[game_num_length]))
		{
			execution = string_err;
			string string_err = "You should only input numerical / integer values.";
			usage(argv[program_name], string_err, execution);
			// Similar to the cases below it, if the main function is not returned, a debug assertion error is thrown
			// when attempting to create a game board with the string value as a dimension size; that and to prevent multiple
			// errors from being returned at once
			return execution; 
		}
	}
	else if (argc == expect_arg_g2)
	{
		// Extra Credit: Two Parameters
		if (!is_number(argv[game_num_length]) || !is_number(argv[game_num_win]))
		{
			execution = string_err;
			string string_err = "You should only input numerical / integer values.";
			usage(argv[program_name], string_err, execution);
			return execution;
		}
	}
	bool num_passed = false; // if it passes the check for the correct number of arguments
	if (argc != expect_arg && argc != expect_arg_g1 && argc != expect_arg_g2)
	{
		// Number argument error
		execution = num_arg_error;
		string usage_message = "This function should take in 2, 3, or 4 arguments (as well as the program's name) in the following form: \n 'Lab4TeamEAR.exe TicTacToe', 'Lab4TeamEAR.exe Gomoku', 'Lab4TeamEAR.exe Gomoku 4', or 'Lab4TeamEAR.exe Gomoku 18 4'";
		usage(argv[program_name], usage_message, execution);
		return execution;
	}
	else
	{
		string title = argv[game_name];
		toLowerCase(title);
		if (title != "gomoku" && argc != 2) {
			execution = num_arg_error;
			string usage_message = "This function should take in 2, 3, or 4 arguments (as well as the program's name) in the following form: \n 'Lab4TeamEAR.exe TicTacToe', 'Lab4TeamEAR.exe Gomoku', 'Lab4TeamEAR.exe Gomoku 4', or 'Lab4TeamEAR.exe Gomoku 18 4'";
			usage(argv[program_name], usage_message, execution);
			return execution;
		}
		num_passed = true;
	}

	shared_ptr<GameBase> game;

	if (num_passed)
	{
		// Create pointer to base game
		game = GameBase::chooseGame(argc, argv);

		// Return usage function if singular pointer
		if (game == 0)
		{
			string title = argv[game_name];
			toLowerCase(title);

			// Expect 2 command args for tic-tac-toe and 4 for gomoku extra credit
			if (title != "tictactoe" && title != "gomoku")
			{
				// Name error
				execution = name_error; // (2) - Invalid game name
				string name_error = "Unrecognized game title. Only TicTacToe and Gomoku is available to be played. Please try again.";
				usage(argv[game_name], name_error, execution);
				return execution;
			}
		}
		else
		{
			// Else play the game
			execution = (return_values)game->play();
		}
	}

	if (game == 0)
	{
		execution = extra_err;
		string extra_err = "You inputted wrong parameter values for this special case of gomoku. You need STRICTLY integer / numerical values for this program to work.";
		usage(argv[game_name], extra_err, execution);
	}

	return execution;
}