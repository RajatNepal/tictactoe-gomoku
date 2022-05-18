/*
Eric Tabuchi, Arden Chen, Rajat Nepal
e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
Team EAR
Lab 4
GomokuGame.h
Header file

*/
#pragma once

#include "GameBase.h"
#include "Game_Piece.h"

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

//Declaring class GomokuGame, its methods, and member variables.
class GomokuGame : public GameBase {

	friend std::ostream& operator << (std::ostream& ostr, GomokuGame& game);

public:
	GomokuGame(); //Default constructor

	//constructors for extra credit (1 parameter and 2 parameters)
	GomokuGame(int numLength);
	GomokuGame(int numLength, int winNumber);

	//destructor
	~GomokuGame() = default;

	virtual void print() override; // Prints game board
	virtual bool done() override;  // Checks if a player has won the game
	virtual bool draw() override;  // Checks if it is possible for a player to win at all
	virtual int turn() override;   // Simulates a player's turn in the game


	//String constants for symbols to avoid hardcoding later on
	const std::string black;
	const std::string white;
	
	// to store the moves in order to be printed out by the turn() function
	// since an X move is pushed, then an O move, then X, etc, the order is preserved, just have to jump
	std::vector<std::string> moves;

	unsigned int numTurns; // number of turns that have happened

	const unsigned int winCount; // set to 5 for regular gomoku, but this can be generalized to any number

};

std::ostream& operator << (std::ostream& ostr, GomokuGame& game);