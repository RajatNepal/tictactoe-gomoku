// TicTacToe.h
// Author: Eric Yelong Tabuchi
// Email: e.tabuchi@wustl.edu
// The purpose of this header file is to declare the TicTacToe class
// that has private member variables, an overloaded << operator to
// work with cout, a constructor, accessor methods, and bool and int
// functions to implement a game of tic-tac-toe based on the experience
// from Lab2 and the functions implemented in the game piece and game board
// sections of the project

#pragma once

#include "GameBase.h"
#include "Game_Piece.h"
#include <iostream>
#include <vector>

#include <sstream>
#include <iomanip>

// For the TicTacToe game, it will be a 5 x 5 game board
class TicTacToe : public GameBase
{
	public:
		// Constructor for TicTacToe game
		TicTacToe();

		// Methods for game implementation
		virtual bool done(); // Checks if the game is finished / if someone has won
		virtual bool draw(); // Checks if the game has tied
		virtual int turn(); // Alternates between the player with Xs and player with Os where it will prompt user with prompt() 
		virtual void print();

		// Extraction operator treated as friend class to access parts of TicTacToe
		friend std::ostream& operator<< (std::ostream& o, const TicTacToe& game);
};

// Overloading the << operator in order to print out the game via cout << TicTacToe << endl;
std::ostream& operator<< (std::ostream& o, const TicTacToe& game);
