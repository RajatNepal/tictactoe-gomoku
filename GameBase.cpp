// GameBase.cpp
//Eric Tabuchi, Arden Chen, Rajat Nepal
//e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
//Team EAR
// The purpose of this source file is to implement the constructor and methods
// of the base game class such that its derived classes (gomoku and tic-tac-toe)
// are able to use the same methods and member variables but with different
// implementations and values. The prompt() and play() functions from the previous
// lab have been moved over to this class so that both derived classes can use it.
// A chooseGame() function has also been implemented to choose the specific game to run
// when running from the command-line.

#include "GameBase.h"
#include "Game_Board.h"
#include "TicTacToe.h"
#include "GomokuGame.h"

using namespace std;

// Constructor
GameBase::GameBase(unsigned int width, unsigned int height, bool turnPlayer, unsigned int longestOut, unsigned int gameType) :
	width_(width), height_(height), turnPlayer_(turnPlayer), longestOut_(longestOut), gameType_(gameType)
{
	vector<piece> tictactoe_board;
	board_ = tictactoe_board;
	initBoard(board_, height_, width_);
}

// This function will prompt the user for coordinate values until they "quit" or place in a set of coordinates
int GameBase::prompt(unsigned int& horiz, unsigned int& vert)
{
	cout << "Input 'quit' to exit program or input a coordinate in the following form: '0, 0'." << endl;

	// This bool checks if the user has answered the prompt
	bool answered = false;

	// While the user has not answered the prompt, loop until they do. 
	while (!answered)
	{
		string response;

		// Get the line and transfer it into the response string
		getline(cin, response);

		// Convert to lowercase for the case it may be "quit"
		toLowerCase(response);

		// Check if the response was valid and repeat until they get it right
		if (response == "quit") // Did the user input "quit" ?
		{
			answered = true;
			return game_quit; // (3) - Player(s) have quit
		}
		else if (formatCoor(response)) // Did the user have a comma in their response (a characteristic of a coordinate)? 
		{
			// The response had a comma in it so now we check if it is valid according to our conditions:
			// 1. Must be of length 3 (Do not want user inputting something like '0, ' or '0, 4 44')
			// 2. Entries must be digits where we will check with our is_number() function

			string temp_x, temp_y, extra; // will temporarily store the values to check if they are numbers
			unsigned int x, y;  // will be used for the values of horiz and vert if they are valid

			istringstream iss(response);

			if (iss >> temp_x && iss >> temp_y && !(iss >> extra))
			{
				// Check if the first two extracted values were numbers
				if (is_number(temp_x) && is_number(temp_y))
				{
					istringstream iss_x(temp_x);
					istringstream iss_y(temp_y);
					iss_x >> x;
					iss_y >> y;

					// Next check if those numbers are valid coordinate positions
					if (x > 0 && x < width_ - 1 && y > 0 && y < height_ - 1 && board_[width_ * y + x].symbol_ == "-")
					{
						// They passed all tests so now x and y get passed as the values for horiz and vert
						horiz = x;
						vert = y;
						answered = true;
					}
					else
					{
						if ((x > 0 && x < width_ - 1 && y > 0 && y < height_ - 1 && board_[width_ * y + x].symbol_ != "-"))
						{
							cout << "Location already contains a game piece. Try again." << endl;
						}
						else 
						{
							cout << "Invalid coordinates. Try again." << endl;
						}
					}
				}
				else
				{
					cout << "Non-numerical values detected. Try again." << endl;
				}
			}
			else
			{
				cout << "Too many arguments inputted. Try again." << endl;
			}
		}
		else
		{
			cout << "Invalid input. Please try again." << endl;
		}
	}

	return success; // (0) - Turn has successfully finished
}


//caled when game is played
//returns 0 if successful
int GameBase::play()
{
	// Turn count keeps track of # of turns played
	unsigned int turnCount = 0;

	this->print();

	// While noone has won or a draw has not happened...
	while (!done() && !draw())
	{
		// Increment turn count
		turnCount++;

		cout << "Turn " << turnCount << endl;

		// Repeatedly call the turn() method unless the player(s) have quit
		if (turn() == game_quit)
		{
			// State which player initiated the quit
			if (turnPlayer_)
			{
				if (gameType_ == tictactoe)
				{
					cout << "Player O has quit the game. ";
				}
				else if (gameType_ == gomoku)
				{
					cout << "Player W has quit the game. ";
				}
			}
			else
			{
				if (gameType_ == tictactoe)
				{
					cout << "Player X has quit the game. ";
				}
				else if (gameType_ == gomoku)
				{
					cout << "Player B has quit the game. ";
				}
			}

			cout << turnCount;

			if (turnCount == 1)
			{
				cout << " turn was played in the process." << endl;
			}
			else
			{
				cout << " turns were played in the process." << endl;
			}

			return game_quit;
		}
		else
		{
			// Call the done() and draw() method to check if anything has changed.
			if (done())
			{
				if (turnPlayer_)
				{
					if (gameType_ == tictactoe)
					{
						cout << "Player O has won the game!";
					}
					else if (gameType_ == gomoku)
					{
						cout << "Player B has won the game!";
					}
				}
				else
				{
					if (gameType_ == tictactoe)
					{
						cout << "Player X has won the game!";
					}
					else if (gameType_ == gomoku)
					{
						cout << "Player W has won the game!";
					}
				}
				return success;
			}
			else if (draw())
			{
				cout << "No winning moves can be made. " << turnCount << " turns were played in the process." << endl;
				return game_draw;
			}
		}
	}

	return success;
}

// Returns either singular pointer (0) or pointer to derived game class object
//checs to see which game to implement
//also checks for extra credit stuff here
shared_ptr<GameBase> GameBase::chooseGame(int argc, char* argv[])
{
	// Will be returned if argument count is unexpected or game name is incorrect
	shared_ptr<GameBase> singular = 0;

	// If there is the expected number of command-line arguments
	if (argc == expect_arg)
	{
		string game_type = argv[game_name];
		toLowerCase(game_type);
		
		// Check if the game name typed in was either tictactoe or gomoku
		if (game_type == "tictactoe")
		{
			shared_ptr<GameBase> tictactoe_game(new TicTacToe());
			return tictactoe_game;
		}
		else if (game_type == "gomoku")
		{
			// if gomoku with default values
			shared_ptr<GameBase> gomoku_game(new GomokuGame());
			return gomoku_game;
		}
	}

	//check if 3 arguments passed in

	else if (argc == expect_arg_g1)
	{
		
		string game_type = argv[game_name];
		toLowerCase(game_type);
		if (game_type == "gomoku") {
			int numLength = std::stoi(argv[game_num_length]);

			if (numLength < 3 || numLength >64) {
				cout << "Make sure when entering the length of the board, it is 3 or more and 64 or less. You entered: " << numLength << endl;
				cout << "Please try again." << endl;
				return singular;
			}

			if (numLength == 3) {	
				cout << "You entered 3 for game size. This is the same as playing Tic Tac Toe. So we are running Tic Tac Toe " << endl;
				shared_ptr<GameBase> tictactoe_game(new TicTacToe());
				return tictactoe_game;
			}

			if (numLength == 4) {
				shared_ptr<GameBase> gomoku_game(new GomokuGame(numLength, numLength));
				return gomoku_game;
			}
			// Insert gomoku code later once tictactoe is successfully finished
			shared_ptr<GameBase> gomoku_game(new GomokuGame(numLength));
			return gomoku_game;	
		}
		return singular; // will return singular otherwise
	}

	//check if 4 arguments passed in
	else if (argc == expect_arg_g2)
	{
		string game_type = argv[game_name];
		toLowerCase(game_type);
		if (game_type == "gomoku") {
			int numLength = std::stoi(argv[game_num_length]);
			int numWin = std::stoi(argv[game_num_win]);

			if (numLength < 3 || numLength > 64) {
				cout << "Make sure when entering the length of the board, it is 3 or more and 64 or less. You entered : " << numLength << endl;
				return singular;
			}
			if (numWin < 2) {
				cout << "Make sure your win count is 2 or more. Otherwise the game will be unfair or unplayable." << endl;
				return singular;
			}
			if (numWin > numLength) {
				cout << "Make sure your number of pieces needed to win is less than the gameboard side size." << endl;
				cout << "If you need more pieces in a row to win than the length of your board, no one will ever be able to win!" << endl;
				cout << "You entered " << numLength << " for game board length and " << numWin << " pieces in a row for a win." << endl;
				cout << "Since " << numLength << " is less than " << numWin << ", this is an impossible game." << endl;

				return singular;
			}
			if (game_type == "gomoku")
			{
				if (numLength == 3) {
					cout << "You entered 3 for game size. This is the same as playing Tic Tac Toe. So we are running Tic Tac Toe." << endl;

					shared_ptr<GameBase> tictactoe_game(new TicTacToe());
					return tictactoe_game;
				}

				// Insert gomoku code later once tictactoe is successfully finished
				shared_ptr<GameBase> gomoku_game(new GomokuGame(numLength, numWin));
				return gomoku_game;
			}
			else
			{
				return singular; // will return singular otherwise
			}
		}
	}
	return singular; // will return singular otherwise
}