// TicTacToe.cpp
// Eric Tabuchi, Arden Chen, Rajat Nepal
//e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
//Team EAR
// The purpose of this source file is to define the constructor, accessor
// methods, and main functions that will be needed to create a TicTacToe game
// done() and draw() return true if a winner has been made or a draw occurred respectively
// prompt() prompts the user for coordinate input unless they quit
// turn() calls prompt() to represent a player's turn
// play() call turn() to simulate a game that lasts until a player has won,
// quit, or a draw happened

#include "TicTacToe.h"
#include "Game_Board.h"
#include "Useful.h"
#include <sstream>

using namespace std;

// Constructor for a TicTacToe game
TicTacToe::TicTacToe() : GameBase(ttt_width, ttt_height, true, ttt_setwidth, tictactoe) { }

//prints tictactoe board
void TicTacToe::print()
{
	cout << *this << endl;
}

// Overloaded extraction operator to work with cout
ostream& operator<< (ostream& o, const TicTacToe& game)
{
	for (int r_index = static_cast<int>(game.height_) - 1; r_index >= 0; r_index--)
	{
		o << std::setw(game.longestOut_) << r_index;

		for (size_t c_index = 0; c_index < game.width_; c_index++)
		{
			unsigned int index = static_cast<unsigned int>(game.width_ * r_index + c_index);
			o << std::setw(game.longestOut_) << game.board_[index].symbol_;
		}

		// Print new line to begin work on horizontal axis labeling
		o << endl;
	}
	
	// Move the horizontal axis forward a bit to align with the first column
	o << "  ";

	for (size_t c = 0; c < game.width_; c++)
	{
		o << std::setw(game.longestOut_) << c;
	}

	o << endl;
	
	return o;
}


// Methods to implement TicTacToe game
bool TicTacToe::done() // true = player has won, false = noone has won yet
{
	// A winner has occurred if there is either: 1) A horizontal straight line, 2) Vertical straight line, or 3) Diagonal of the same symbol

	// Horizontal line
	for (size_t r_index = 1; r_index < height_ - 1; r_index++)
	{
		// Create vector of strings to store symbols of a single row
		vector<string> row;

		for (size_t c_index = 1; c_index < width_ - 1; c_index++)
		{
			unsigned int index = static_cast<unsigned int>(width_ * r_index + c_index);
			row.push_back(board_[index].symbol_);
		}

		// Set the first entry in the vector as the string we must compare with and check if it has an X or O
		string first = row[0];

		// Create a counter that, if it reaches # columns means that it is a straight line / winning game state
		unsigned int horizCounter = 1;

		if (first != "-")
		{
			for (size_t v_index = 1; v_index < row.size(); v_index++)
			{
				if (row[v_index] == first)
				{
					horizCounter++;
				}
			}

			if (horizCounter == row.size())
			{
				return true;
			}
		}
	}

	// Vertical line / column of Xs and Os check
	for (size_t c_index = 1; c_index < width_ - 1; c_index++)
	{
		// Create vector of strings to store symbols of a column
		vector<string> column;

		for (size_t r_index = 1; r_index < height_ - 1; r_index++)
		{
			unsigned int index = static_cast<unsigned int>(width_ * r_index + c_index);
			column.push_back(board_[index].symbol_);
		}

		// Like with horizontal row checking, set the first value of the vector as the one we will compare with
		string first = column[0];

		// Likewise, also create a counter to store the number of similar elements in the column
		unsigned int vertCounter = 1;

		if (first != "-")
		{
			for (size_t v_index = 1; v_index < column.size(); v_index++)
			{
				if (column[v_index] == first)
				{
					vertCounter++;
				}
			}

			if (vertCounter == column.size())
			{
				return true;
			}
		}
	}

	// Diagonal line check from top left to bottom right. Start by declaring a pair of coordinates to represent value we want to check.
	// Top left represented by the value located in the first column at the top row
	unsigned int x = 1; // 1st column
	unsigned int y = height_ - 2; // top row (that is valid and not an empty border)

	if (board_[width_ * y + x].symbol_ != "-")
	{
		// Save the first entry to compare with the other entries in the diagonal
		string first = board_[width_ * y + x].symbol_;

		// Create a counter to store the number of matching values to first
		unsigned int diaCounter = 0;

		// Using a while loop that will stop executing once x and y reach the last entry of the diagonal
		while (x <= width_ - 2 && y >= 1)
		{
			unsigned int index = width_ * y + x;
			if (board_[index].symbol_ == first)
			{
				diaCounter++;
			}

			x++;
			y--;
		}

		if (diaCounter == width_ - 2)
		{
			return true;
		}
	}

	// Diagonal line check from bottom left to top right. Implemented similarly to the previous diagonal check
	x = 1; // 1st column
	y = 1; // top row (that is valid and not an empty border)

	if (board_[width_ * y + x].symbol_ != "-")
	{
		// Save the first entry to compare with the other entries in the diagonal
		string first = board_[width_ * y + x].symbol_;

		// Create a counter to store the number of matching values to first
		unsigned int diaCounter = 0;

		while (x <= width_ - 2 && y <= height_ - 2)
		{
			unsigned int index = width_ * y + x;
			if (board_[index].symbol_ == first)
			{
				diaCounter++;
			}

			x++;
			y++;
		}

		if (diaCounter == width_ - 2)
		{
			return true;
		}
	}

	return false;
}

// Returns true if no more moves can be made, false if there still are moves
bool TicTacToe::draw()
{
	for (size_t r_index = 0; r_index < height_; r_index++)
	{
		for (size_t c_index = 0; c_index < width_; c_index++)
		{
			unsigned int index = static_cast<unsigned int>(width_ * r_index + c_index);
			if (r_index != 0 && r_index != height_ - 1 && c_index != 0 && c_index != width_ - 1)
			{
				// If a valid spot on the board does not have an X or an O, there still are available moves
				if (board_[index].symbol_ != "X" && board_[index].symbol_ != "O")
				{
					return false;
				}
			}
		}
	}
	// If we get through the entire loop and not a single valid entry is empty, then no more winning moves are available
	return true;
}

//this simulates one turn in a tictactoe game
//returns 0 if successful
int TicTacToe::turn()
{
	if (turnPlayer_)
	{
		cout << "Player X, it is your turn to input something." << endl;
	}
	else
	{
		cout << "Player O, it is your turn to input something." << endl;
	}

	unsigned int x, y; // x = horizontal / column index, y = vertical / row index

	if (prompt(x, y) == game_quit)
	{
		return game_quit; 
	}
	else
	{
		if (turnPlayer_)
		{
			board_[width_ * y + x].symbol_ = "X";
		}
		else
		{
			board_[width_ * y + x].symbol_ = "O";
		}

		cout << *this << endl;

		// Blank line to divide outputs
		cout << endl;

		if (turnPlayer_)
		{
			cout << "Player X: ";
		}
		else
		{
			cout << "Player O: ";
		}

		// Loop through and output the coordinates that match the current player's symbol
		for (size_t r = 0; r < height_; r++)
		{
			for (size_t c = 0; c < width_; c++)
			{
				if (turnPlayer_)
				{
					if (board_[width_ * r + c].symbol_ == "X")
					{
						cout << c << ", " << r << "; ";
					}
				}
				else
				{
					if (board_[width_ * r + c].symbol_ == "O")
					{
						cout << c << ", " << r << "; ";
					}
				}
			}
		}

		// '\b' to backspace and remove the ; from the last coordinate output
		cout << '\b' << '\b' << " " << endl;

		// Now it is the other person's turn
		turnPlayer_ = !turnPlayer_;
	}

	// Unless the player quit, the return value should be for a sucessful value
	return success;
}
