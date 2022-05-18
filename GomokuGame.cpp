/*
Eric Tabuchi, Arden Chen, Rajat Nepal
e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
Team EAR
GomokuGame.cpp:
Defines Gomoku Game constructors, insertion operator, done, draw, turn functions. 

*/

#include "GomokuGame.h"
#include "Useful.h"

using namespace std;

//set string constants
//default constructor
GomokuGame::GomokuGame() :
	GameBase(gomo_height, gomo_width, false, gomo_setwidth, gomoku),
	black("B"), white("W"), numTurns(first_turn), winCount(win_count) { }


//EC: constructor if length of board is passed in
GomokuGame::GomokuGame(int numLength) :
	GameBase(numLength +2, numLength + 2, false, gomo_setwidth, gomoku),
	black("B"), white("W"), numTurns(first_turn), winCount(win_count) { }

//EC: constructor if length of board and win number is passed in
GomokuGame::GomokuGame(int numLength, int winNumber) :
	GameBase(numLength + 2, numLength + 2, false, gomo_setwidth, gomoku),
	black("B"), white("W"), numTurns(first_turn), winCount(winNumber) { }


//prints the board
void GomokuGame::print() {
	cout << *this << endl;
}


//defines << operator
ostream& operator<< (ostream& o, GomokuGame& game) {
	for (int r_index = (int)game.height_ - 1; r_index >= 0; r_index--)
	{
		o << std::setw(game.longestOut_) <<r_index;

		for (unsigned c_index = 0; c_index < game.width_; c_index++)
		{
			unsigned int index = game.width_ * r_index + c_index;
			o << std::setw(game.longestOut_) << game.board_[index].symbol_;
		}

		// Print new line to begin work on horizontal axis labeling
		o << endl;
	}

	// Move the horizontal axis forward a bit to align with the first column
	o << "   ";

	for (size_t c = 0; c < game.width_; c++)
	{
		o << std::setw(game.longestOut_) << c ;
	}

	o << endl;

	return o;
}

/*
This boolean method returns true when a player wins. False when there is no win, and game can continue (or there is a draw, this still returns false)
It has four separate loops, for horizontal, vertical, right diagonal, left diagonal. This differs from TicTacToe, because even if the program finds an empty square,
there can still be a win later on in the row/column/diagonal, so we need to keep checking.
*/
bool GomokuGame::done() {
	string piece = ""; // used to keep track of the piece to find a line of the same. empty string means we reset it
	int wincounter = 0; // used to keep track of streak of the same pieces. if this equals wincount, we found a win.
	// In these loops, only check the inner square, so ignore the edges (start one unit further and end one unit earlier

	// check columns first
	for (int i = height_ - 2; i > 0; i--) { // loop through rows, from top to bottom
		// loop through the current row
		for (unsigned int j = 1; j < width_ - 1; j++) { // loop through columns, from left to right
			int index = width_ * j + i; // calculate index for traversing board vector
			string current = board_[index].symbol_; // running variable to hold the piece we are on right now, to compare to piece string
			if (current == "-") {
				// empty string, means there is an empty space. we reset the wincounter, and skip to the next piece
				wincounter = 0;
				continue;
			}
			else if (!(piece == current)) {
				// here, current piece is not empty but is a different piece. reset wincounter to 1 (now we have effectively "1 piece in a row", as opposed to an empty spot.)
				wincounter = 1;
				piece = current;
				continue;
			}
			else {
				// here, piece == current. add to the streak.
				wincounter++;
			}

			piece = current; // if the piece changed, this will update the piece. if we are on a streak, this will do nothing.

			if (wincounter == winCount) {
				// found a win, return immediately
				cout << "Win on column: " << i << endl;
				return true;
			}
		}
		// reset piece and wincounter for next row
		piece = "";
		wincounter = 0;
	}

	// check rows; apart from loops, inner logic is same.
	for (unsigned int j = 1; j < width_ - 1; j++) { // loop through columns, left to right
		// loop through the current column
		for (int i = height_ - 2; i > 0; i--) {// loop through rows, from top to bottom
			int index = width_ * j + i; // calculate index for traversing board vector
			string current = board_[index].symbol_; // running variable to hold the piece we are on right now, to compare to piece string
			if (current == "-") {
				// empty string, means there is an empty space. we reset the wincounter, and skip to the next piece
				wincounter = 0;
				continue;
			}
			else if (!(piece == current)) {
				// here, current piece is not empty but is a different piece. reset wincounter to 1 (now we have effectively "1 piece in a row", as opposed to an empty spot.)
				wincounter = 1;
				piece = current;
				continue;
			}
			else {
				// here, piece == current. add to the streak.
				wincounter++;
			}

			piece = current; // if the piece changed, this will update the piece. if we are on a streak, this will do nothing.

			if (wincounter == winCount) {
				// found a win, return immediately
				cout << "Win on row: " << j << endl;
				return true;
			}
		}
		// reset piece for next row
		piece = "";
		wincounter = 0;
	}
	// check diagonals. these each need a triple loop (maybe could be better). We loop through the subset of the game board where the start of the diagonal is valid (this is to avoid
	// having a diagonal run out of bounds of the game board, which would both waste time and potentially cause an out of bounds error.) This uses a double loop. The third loop runs for k = wincount
	// (default is 5), and checks k values to see if they are the same.

	// start top left
	for (int i = height_ - 2; i >= static_cast<int>(winCount); i--) { // loop through rows, from top to bottom, but skip the last winCount rows because they can't have a win anyways
		for (unsigned int j = 1; j < width_ - static_cast<int>(winCount); j++) { // loop through columns, from left to right, skip last winCount columns too
			wincounter = 0; // reset wincounter before checking 5 values
			int index = width_ * i + j; // calculate index for traversing board vector
			piece = board_[index].symbol_; // set the piece to current value
			if (piece == "-") {
				// only continue checking if this piece is an actual piece, so if we are here, skip the next for loop
				continue;
			}
			else {
				wincounter++;// this is the beginning of the streak, wincounter = 1 after.
			}
			for (unsigned int k = 1; k < winCount; k++) { // loop for k = winCount cycles
				int index2 = static_cast<int>(width_) * (i - k) + (j + k); // calculate index for traversing board vector (rename because index exists above)
				string current = board_[index2].symbol_; // running variable to hold the piece we are on right now, to compare to piece string
				if (!(piece == current)) {
					// here, current piece is not empty but is a different piece. reset wincounter to 1 (now we have effectively "1 piece in a row", as opposed to an empty spot.)
					wincounter = 1;
					piece = current;
					continue;
				}
				else {
					// here, piece == current. add to the streak.
					wincounter++;
				}

				piece = current; // if the piece changed, this will update the piece. if we are on a streak, this will do nothing.

				if (wincounter == static_cast<int>(winCount)) {
					// found a win, return immediately
					cout << "Win on left to right diagonal starting at: " << j << "," << i << endl;
					return true;
				}
			}
		}
	}

	// start top right
	piece = "";
	wincounter = 0;
	for (int i = height_ - 2; i >= static_cast<int>(winCount); i--) { // loop through rows, from top to bottom, but skip the last winCount rows because they can't have a win anyways
		for (int j = width_ - 2; j >= static_cast<int>(winCount); j--) { // loop through columns, from left to right
			wincounter = 0; // reset wincounter before checking 5 values
			int index = width_ * i + j; // calculate index for traversing board vector
			piece = board_[index].symbol_; // set the piece to current value
			if (piece == "-") {
				// only continue checking if this piece is an actual piece, so if we are here, skip the next for loop
				continue;
			}
			else {
				wincounter++;// this is the beginning of the streak, wincounter = 1 after.
			}
			for (int k = 1; k < static_cast<int>(winCount); k++) { // loop for k = winCount cycles
				int index2 = width_ * (i - k) + (j - k); // calculate index for traversing board vector
				string current = board_[index2].symbol_; // running variable to hold the piece we are on right now, to compare to piece string
				if (!(piece == current)) {
					// here, current piece is not empty but is a different piece. reset wincounter to 1 (now we have effectively "1 piece in a row", as opposed to an empty spot.)
					wincounter = 1;
					piece = current;
					continue;
				}
				else {
					// here, piece == current. add to the streak.
					wincounter++;
				}

				piece = current; // if the piece changed, this will update the piece. if we are on a streak, this will do nothing.

				if (wincounter == static_cast<int>(winCount)) {
					// found a win, return immediately
					cout << "Win on right to left diagonal starting at: " << j << "," << i << endl;
					return true;
				}
			}
		}
	}
	// if here, no winner, return false.
	return false;
}
/*
This boolean method checks to see if there is a draw or not. We cannot just see if the entire board is filled.
The algorithm will be very similar to the done() function. We can treat empty spaces as "winning" symbols, so that if there are any 5 in a row of empty space and one color, the game is not yet
forced to be a draw.

Since anything (empty squares or actual pieces) can start a draw sequence, we initialize piece to be whatever the first item in row/column/diag is so we can start counting immediately
*/
bool GomokuGame::draw() {
	string piece = ""; // used to keep track of the piece to find a line of the same. empty string means we reset it
	int drawcounter = 0; // used to keep track of streak of the same pieces. if this equals wincount, we found a possible win.
	// In these loops, only check the inner square, so ignore the edges (start one unit further and end one unit earlier

	// check columns first
	for (int i = height_ - 2; i > 0; i--) { // loop through columns, from left to right
		// loop through the current row
		for (unsigned int j = 1; j < width_ - 1; j++) { // loop through rows, from top to bottom
			int index = width_ * j + i; // calculate index for traversing board vector
			string current = board_[index].symbol_; // running variable to hold the piece we are on right now, to compare to piece string
			if (j == 1) {
				// If this is the first piece, piece variable will still be "", and we want to set it to whatever the first item is (current). Drawcounter is also 1.
				// There is no way for a possible to win to happen, so we can continue loop.
				piece = current;
				drawcounter = 1;
				continue;
			}
			// Here, must be past first piece. If piece is currently holding empty square, we haven't found an actual piece yet to set it to that. Therefore, if that is the case
			// set the piece to be this new piece. If the new piece is still empty, this block will do nothing, but it is not necessary to continue checking if
			// current piece is a real piece. And no matter what the current piece is, we increment draw counter.
			if (piece == "-") {
				piece = current;
				drawcounter++;
			}
			else {
				// here, piece is not empty; we have previously found a real piece and are on a streak
				if (current == "-" || current == piece) {
					// here, the current piece is empty or is the same piece. either case functions the same and we only increment draw.
					drawcounter++;
				}
				else {
					// here, we found another piece and it must not be the same piece. reset drawcounter and change piece to hold this instead.
					drawcounter = 1;
					piece = current;
				}
			}

			if (drawcounter == winCount) {
				// found a possible win, no draw.
				return false;
			}
		}
		// reset piece and wincounter for next row
		piece = "";
		drawcounter = 0;
	}

	// check rows; apart from loops, inner logic is same.
	for (unsigned int j = 1; j < width_ - 1; j++) { // loop through rows, from top to bottom
		// loop through the current column
		for (int i = height_ - 2; i > 0; i--) {// loop through columns, from left to right
			int index = width_ * j + i; // calculate index for traversing board vector
			string current = board_[index].symbol_; // running variable to hold the piece we are on right now, to compare to piece string			
			if (i == height_ - 2) {
				// If this is the first piece, piece variable will still be "", and we want to set it to whatever the first item is (current). Drawcounter is also 1.
				// There is no way for a possible to win to happen, so we can continue loop.
				piece = current;
				drawcounter = 1;
				continue;
			}
			// Here, must be past first piece. If piece is currently holding empty square, we haven't found an actual piece yet to set it to that. Therefore, if that is the case
			// set the piece to be this new piece. If the new piece is still empty, this block will do nothing, but it is not necessary to continue checking if
			// current piece is a real piece. And no matter what the current piece is, we increment draw counter.
			if (piece == "-") {
				piece = current;
				drawcounter++;
			}
			else {
				// here, piece is not empty; we have previously found a real piece and are on a streak
				if (current == "-" || current == piece) {
					// here, the current piece is empty or is the same piece. either case functions the same and we only increment draw.
					drawcounter++;
				}
				else {
					// here, we found another piece and it must not be the same piece. reset drawcounter and change piece to hold this instead.
					drawcounter = 1;
					piece = current;
				}
			}

			if (drawcounter == winCount) {
				// found a possible win, means no draw.
				return false;
			}
		}
		// reset piece for next row
		piece = "";
		drawcounter = 0;
	}
	// check diagonals. these each need a triple loop (maybe could be better). We loop through the subset of the game board where the start of the diagonal is valid (this is to avoid
	// having a diagonal run out of bounds of the game board, which would both waste time and potentially cause an out of bounds error.) This uses a double loop. The third loop runs for k = wincount
	// (default is 5), and checks k values to see if they are the same.

	// start top left
	for (int i = height_ - 2; i >= static_cast<int>(winCount); i--) { // loop through rows, from top to bottom, but skip the last winCount rows because they can't have a win anyways
		for (unsigned int j = 1; j < width_ - static_cast<int>(winCount); j++) { // loop through columns, from left to right, skip last winCount columns too
			drawcounter = 1; // start drawcounter at 1
			int index = width_ * j + i; // calculate index for traversing board vector
			piece = board_[index].symbol_; // set the piece to current value
			for (size_t k = 1; k < winCount; k++) { // loop for k = winCount cycles
				int index2 = static_cast<int>(width_ * (j + k) + (i - k)); // calculate index for traversing board vector (rename because index exists above)
				string current = board_[index2].symbol_; // running variable to hold the piece we are on right now, to compare to piece string			
				if (j == 1) {
					// If this is the first piece, piece variable will still be "", and we want to set it to whatever the first item is (current). Drawcounter is also 1.
					// There is no way for a possible to win to happen, so we can continue loop.
					piece = current;
					drawcounter = 1;
					continue;
				}
				// Here, must be past first piece. If piece is currently holding empty square, we haven't found an actual piece yet to set it to that. Therefore, if that is the case
				// set the piece to be this new piece. If the new piece is still empty, this block will do nothing, but it is not necessary to continue checking if
				// current piece is a real piece. And no matter what the current piece is, we increment draw counter.
				if (piece == "-") {
					piece = current;
					drawcounter++;
				}
				else {
					// here, piece is not empty; we have previously found a real piece and are on a streak
					if (current == "-" || current == piece) {
						// here, the current piece is empty or is the same piece. either case functions the same and we only increment draw.
						drawcounter++;
					}
					else {
						// here, we found another piece and it must not be the same piece. reset drawcounter and change piece to hold this instead.
						drawcounter = 1;
						piece = current;
					}
				}


				if (drawcounter == winCount) {
					// found a possible win, means no draw.
					cout << "left to right diag win start: " << j << " " << i << endl;
					return false;
				}
			}
		}
	}

	// start top right
	piece = "";
	drawcounter = 0;
	for (int i = height_ - 2; i >= static_cast<int>(winCount); i--) { // loop through rows, from top to bottom, but skip the last winCount rows because they can't have a win anyways
		for (unsigned int j = width_ - 2; j >= static_cast<int>(winCount); j--) { // loop through columns, from left to right
			drawcounter = 1; // start drawcounter at 1
			int index = width_ * j + i; // calculate index for traversing board vector
			piece = board_[index].symbol_; // set the piece to current value
			for (size_t k = 1; k < winCount; k++) { // loop for k = winCount cycles
				int index2 = static_cast<int>(width_ * (j - k) + (i - k)); // calculate index for traversing board vector
				string current = board_[index2].symbol_; // running variable to hold the piece we are on right now, to compare to piece string			
				if (j == width_ - 2) {
					// If this is the first piece, piece variable will still be "", and we want to set it to whatever the first item is (current). Drawcounter is also 1.
					// There is no way for a possible to win to happen, so we can continue loop.
					piece = current;
					drawcounter = 1;
					continue;
				}
				// Here, must be past first piece. If piece is currently holding empty square, we haven't found an actual piece yet to set it to that. Therefore, if that is the case
				// set the piece to be this new piece. If the new piece is still empty, this block will do nothing, but it is not necessary to continue checking if
				// current piece is a real piece. And no matter what the current piece is, we increment draw counter.
				if (piece == "-") {
					piece = current;
					drawcounter++;
				}
				else {
					// here, piece is not empty; we have previously found a real piece and are on a streak
					if (current == "-" || current == piece) {
						// here, the current piece is empty or is the same piece. either case functions the same and we only increment draw.
						drawcounter++;
					}
					else {
						// here, we found another piece and it must not be the same piece. reset drawcounter and change piece to hold this instead.
						drawcounter = 1;
						piece = current;
					}
				}

				if (drawcounter == winCount) {
					// found a possible win, means no draw.
					cout << "right to left diag win start: " << j << " " << i << endl;					
					return false;
				}
			}
		}
	}
	// if here, no possible win found, draw.
	cout << "No possible wins for either side. Draw." << endl;
	return true;
}


//simulates one turn 
int GomokuGame::turn() {
	string turn;
	if (turnPlayer_) {
		turn = "W";
	}
	else {
		turn = "B";
	}
	cout << "It is " + turn + "'s turn." << endl;
	unsigned int x, y; // coordinates
	int promptresult = prompt(x, y);
	if (promptresult == game_quit) {
		cout << "Game has been quit." << endl;
		return game_quit;
	}
	// edit the board and change the piece at these coordinates to the correct symbol.
	int index = width_ * y + x;// calculate index for traversing board vector
	board_[index].symbol_ = turn;
	// add formatted coordinates to the moves vector
	moves.push_back(to_string(x) + "," + to_string(y));
	cout << *this << endl << endl;

	// print moves from moves vector
	// Black moves are first, at 0, 2, 4, etc. indices
	cout << "Black's moves: ";
	for (int i = 0; i < static_cast<int>(moves.size()); i += 2) {
		cout << moves[i] << "; ";
	}
	cout << endl;
	// White moves now, at 1, 3, 5, etc. indices
	cout << "White's moves: ";
	for (int i = 1; i < static_cast<int>(moves.size()); i += 2) {
		cout << moves[i] << "; ";
	}
	cout << endl;
	turnPlayer_ = !turnPlayer_; // change player turn
	return success;
}