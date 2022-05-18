// Game_Board.h
// Author: Eric Yelong Tabuchi
// Email: e.tabuchi@wustl.edu
// The purpose of this header file is to declare initBoard()
// which populates a game board of size row x column into a vector
// of game pieces in order to initialize the board before play can occur.

#pragma once

#include "Game_Piece.h"
#include <iostream>
#include <vector>

// Initialize a game board of game pieces of size row x columns
void initBoard(std::vector<piece>& game_board, unsigned int row, unsigned int column);