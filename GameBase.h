// GameBase.h
//Eric Tabuchi, Arden Chen, Rajat Nepal
//e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
//Team EAR
// The purpose of this header file should be to declare a GameBase class
// that will act as a base class for an abstract 2D game such that pieces
// are placed on a grid board where a winner is declared depending on the 
// number of adjacent pieces that exist. The member variables are pieces of
// information common to these types of games with most methods being pure virtual.
// The ones that are not are universal between 2-player games: prompt() and play().

#pragma once

#include "Game_Board.h"
#include "Useful.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

//gameBase class infor
class GameBase {

protected:
	std::vector<piece> board_; // The game board of pieces
	unsigned int width_;       // # of columns
	unsigned int height_;	   // # of rows
	unsigned int longestOut_;  // Longest number of characters
	unsigned int gameType_;    // Type of game (gomoku or tictactoe?)
	bool turnPlayer_;		   // Is set to true or false to determine who is the starting player (X or O?, B or W?)
public:
	// Constructor
	GameBase(unsigned int width, unsigned int height, bool turnPlayer, unsigned int longestOut, unsigned int gameType);
	
	// Destructor
	virtual ~GameBase() = default;
	
	// Pure virtual functions related to all games of GameBase
	virtual void print() = 0; // Prints out game board
	virtual bool done() = 0;  // Checks if the game is done
	virtual bool draw() = 0;  // Checks if the game is a draw / noone can win regardless of the available pieces
	virtual int turn() = 0;   // Goes over how a player's turn works

	// All games will use these implementations of the following functions
	int prompt(unsigned int& horiz, unsigned int& vert); // Prompts user to input a valid location for game piece
	int play(); // Plays the game

	static std::shared_ptr<GameBase> chooseGame(int argc, char* argv[]); // Picks which game to start up
};
