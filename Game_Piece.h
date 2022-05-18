// Game_Piece.h
// Author: Eric Yelong Tabuchi
// Email: e.tabuchi@wustl.edu
// The purpose of t his header file is to declare a struct of
// what a game piece is. For the previous lab assignment, a struct had
// a color, symbol, and name. Based on what was read regarding the instructions
// for this assignment, all that was needed was the symbol. At the same time,
// treating this as if it were an actual commercial product, additional features
// such as piece color and name could be implemented in the future. As such,
// the struct implementation of a game piece was kept instead of simply using
// strings to represent the game pieces.

#pragma once

#include <iostream>

// A structure of what a game piece contains
struct piece
{
	piece(std::string symbol); // Constructor
	std::string symbol_;	   // Every piece has a symbol
};