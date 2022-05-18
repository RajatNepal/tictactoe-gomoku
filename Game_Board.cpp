// Game_Board.cpp
// Author: Eric Yelong Tabuchi
// Email: e.tabuchi@wustl.edu
// The purpose of this source file is to implement
// the initBoard() function that populates a vector
// of game pieces with an outer border of empty spaces
// with all pieces inside the border starting out with
// "-" to signify they are not taken yet.

#include "Game_Board.h"

using namespace std;

// Initialize the game board as a row x column grid with its outer border empty and its inner pieces empty
void initBoard(vector<piece>& game_board, unsigned int row, unsigned int column)
{
	// Create a default game piece that is empty. Assume that they are not at any of the borders.
	piece def_piece = piece("-");

	for (unsigned int piece_index = 0; piece_index < row * column; piece_index++)
	{
		game_board.push_back(def_piece);
	}

	for (unsigned int r_index = 0; r_index < row; r_index++)
	{
		for (unsigned int c_index = 0; c_index < column; c_index++)
		{
			unsigned int index = column * r_index + c_index;

			// The outer square should be empty which will be when the index is at 0 or index - 1 for horizontal and vertical respectively
			if (r_index == 0 ||  c_index == 0 || r_index == row - 1 || c_index == column - 1)
			{
				game_board[index].symbol_ = " ";   
			}
		}
	}
}