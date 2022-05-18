Eric Tabuchi, Arden Chen, Rajat Nepal
e.tabuchi@wustl.edu, arden.c@wustl.edu, nepal@wustl.edu
Team EAR

CSE 332S Fall 2021
Lab 4

---------------------------------------------------------------------------------------------------------

Overview:
This program allows the player to play TicTacToe, Default Gomoku, and generalized gomoku (explained more in extra credit section)

For TicTacToe:
It creates a 5x5 board (only middle 3x3 playable).
Team X and Team O take turns moving and th board program checks to see
if either player has won, tied, or quit after every move.
Either player can quit by typing "quit" as the input rather than valid coordinates

For Gomoku:
It creates a 21x21 board (only middle 19X19 playable).
Team Black and White take turns moving and the board program checks to see 
if either player has won, tied, or quit after every move.
Either player can quit by typing "quit" as thew input rather than valid coordinates

(1)This program builds on the parsing code from Lab 1 and the gameboard from Lab 2.

(2)This program also refractors code from Lab 3 and adds a new game, gomoku

(3)This program allows two users to play tic tac toe or gomoku

(4)This program can recognize ties, wins, and quittting the game in the middle

(5)This program also spots errors such as not inputting the correct arguments to run
   It gives a helpful error message and usage message if this happens.


What Each Team Member Did:

Eric: Refactored tictactoe code from Lab 3
	  basic troubleshooting
	  added additional comments and helped with ReadMe

Arden: Implemented Gomoku using refactored code
	   Copied a bunch of tictactoe but generalizing code to be workable for any size and wincount changed things
	   Redid draw() function to check for possible wins, not just if entire board is full
	   implemented extra credit

Rajat: Refractored tictactoe code from Lab 3,
	   helped with certain errors, 
	   helped implement drawboard
	   basic troubleshooting
	   implemented extra credit
	   helped with ReadMe

---------------------------------------------------------------------------------------------------------


Errors Encountered:

1. Kept getting errors when using ints throughout the program. I checked online and this was because
   ints were not big enough in some cases. I used a data type called size_t instead.
   This seemed to fix the problem. (same as Lab 2/3 problem)

2. multiple scoping errors for enums. This lab had us use a lot of enums, and some were ambiguous, like 
   in Lab1 and Lab 2. The simple fix was just scoping into the enums when using them.

3. Lots of array out of bound index errors, these were solved by changing values in loops.
   Many errors resulted from edge cases, so adding or subtracting 1 fixed most.



Warnings Encountered:

1. I kept getting warnings saying i was comparing unsigned ints to signed ints
   I fixed this by casting supposedly signed ints int unsigned ints. (same as Lab 2/3)

2. Enum type is unscoped warning. I keep getting this warning when trying to catch
   errors in try-catch blocks in Lab3.cpp. I was told by the TA that scoped vs unscoped
   warnings do not cause a loss of points. (same as Lab 2/3)


---------------------------------------------------------------------------------------------------------

Files Included:

	For details on the enums and functions declared/defined in each file, please visit actual file.
	All ffiles are given descriptions at the top of them.
	How each function/method works is described above each function/method.

	1. Lab4TeamEAR.cpp
		Includes the main function that runs on execution
		Includes multiple helper functions

	2. Useful.h
		Includes enums for results (return_values)
				 enums for program info (rel_info)
				 enums for game type (game_type)
		Declares functions used in Lab4TeamEAR.cpp
		
	3. Game_Piece.cpp
		Includes functions regarding individual pieces
		Defines constructors for piece struct

	4. Game_Piece.h
		Includes the piece struct
		Declares functions used in Piece.cpp
		Contains enums for color types

	5. Game_Board.cpp
		Includes function regarding the board

	6. Game_Board.h
		Declares function used in Board.cpp

	7. GameBase.cpp
		Includes the base class that both tictactoe and gomoku derive from
		Defines constructor and methods for class GameBase
		Includes functions regarding the game (pure virtual and not)


	8. GameBase.h
		Includes the class GameBase
		Declares constructor and methods for this class used in GameBase.cpp
		

	7. tictactoe.cpp
		Includes functions regarding the game
		Defines constructor and methods for class TicTacToeGame
	
	8. tictactoe.h
		Includes the class TicTacToeGame
		Declares constructor and methods for class TicTacToeGame used in tictactoe.cpp

	9. GomokuGame.cpp
		Includes functions regarding gomoku
		Defines constructor and methods for class GomokuGame
	
	10. GomokuGame.h
		Includes the class GomokuGame
		Declares constructor and methods for class GomokuGame used in GomokuGame.cpp
		

---------------------------------------------------------------------------------------------------------

Return Values Enums (return_values):

These enums are the values returned when certain methods return

	success,	    // (0) - successful execution (i.e. a player won a game of tic-tac-toe)
	num_arg_error,  // (1) - incorrect number of command line arguments
	name_error,     // (2) - did not input TicTacToe / not a viable game name
	game_quit,      // (3) - player ended game early by quitting
	game_draw,      // (4) - neither player ended up winning
    string_err,     // (5) - inputted string instead of integer input
	extra_err,      // (6) - input error with extra credit gomoku parameters (i.e. too small of a game board)


Relevant Information Enums (rel_info):

These enums are for the different constants needed for playing both games

	program_name = 0,		// (0) - index 0 of argv (i.e. program's name)
	game_name = 1,			// (1) - index 1 of argv (i.e. game's name)
	game_num_length = 2,	// (2) index 2 of argv (i.e. gomoku length of board sides)	
	game_num_win = 3,		// (3) index 3 of argv (i.e. gomoku win number)
	expect_arg = 2,			// (2) - number of arguments on the command line
	expect_arg_g1 = 3,		// (3) - number of expected arguments on command line for gomoku (assuming extra credit, 1 extra)
	expect_arg_g2 = 4,		// (4) - number of expected arguments on command line for gomoku (assuming extra credit, 2 extra)
	ttt_width = 5,			// (5) - # of columns for tic-tac-toe game board
	ttt_height = 5,			// (5) - # of rows for tic-tac-toe game board
	gomo_width = 21,		// (19) - default # of columns for gomoku board
	gomo_height = 21,		// (19) - default # of rows for gomoku board
	first_turn = 1,			// (1) - first turn is turn number 1
	win_count = 5,			// (5) - number of pieces needed to win in gomoku
	ttt_setwidth = 2,		// (2) - used with setw for spacing
	gomo_setwidth = 3		// (3) - used with setw for spacing


Game Type Enums (game_type)
	
	tictactoe,        // (0) - tictactoe is game 1
	gomoku,           // (1) - gomoku is game 2



---------------------------------------------------------------------------------------------------------

Sample Inputs/Outputs:


General tests (not for gomoku or tictactoe, but the program itself)


1. too little arguments:
input: Lab4TeamEAR.exe
output:
How to use: Lab4TeamEAR.exe
This function should take in 2, 3, or 4 arguments (as well as the program's name) in the following form:
 'Lab4TeamEAR.exe TicTacToe', 'Lab4TeamEAR.exe Gomoku', 'Lab4TeamEAR.exe Gomoku 4', or 'Lab4TeamEAR.exe Gomoku 18 4'

 2. too many arguments:
input: Lab4TeamEar.exe tictactoe gomoku
output:
How to use: Lab4TeamEAR.exe
This function should take in 2, 3, or 4 arguments (as well as the program's name) in the following form:
 'Lab4TeamEAR.exe TicTacToe', 'Lab4TeamEAR.exe Gomoku', 'Lab4TeamEAR.exe Gomoku 4', or 'Lab4TeamEAR.exe Gomoku 18 4'


3. Incorrect Game Name:
input: Lab4TeamEar.exe gomo
output:
Error 2
Unrecognized game title. Only TicTacToe and Gomoku is available to be played. Please try again.

--------------------------------------------------

Testing TicTacToe:

1. playing tictactoe and generating board
input: Lab4TeamEar.exe TicTacToe
output:
 4
 3   - - -
 2   - - -
 1   - - -
 0
   0 1 2 3 4

Turn 1
Player X, it is your turn to input something.
Input 'quit' to exit program or input a coordinate in the following form: '0, 0'.

---tests 2-7 assume tictac toe has been started successfullly---

2. Placing out of bounds:
input: 0,0
output:
Invalid coordinates. Try again.

3. invalid input:
input: 2
output:
Invalid input. Please try again.

4. piece already at specified location (there is already a piece at 1,1 in this example)
input: 1,1
output: 
Location already contains a game piece. Try again.

5. draw game:
input: ---kept going till a game was tied
output:
 4
 3   O X O
 2   X O X
 1   X O X
 0
   0 1 2 3 4


Player X: 1, 1; 3, 1; 1, 2; 3, 2; 2, 3
No winning moves can be made. 9 turns were played in the process.

---exits the program---

6. quiting game (assuming one turn has already been played:
input: quit
output:
Player O has quit the game. 1 turn was played in the process.

7. A player wins:
Diagonal Victory 1
 4
 3   - - X
 2   - X O
 1   X O -
 0
   0 1 2 3 4


Player X: 1, 1; 2, 2; 3, 3
Player X has won the game!

Diagonal Victory 2
 4
 3   O X X
 2     O  
 1   X   O
 0
   0 1 2 3 4


Player O: 3, 1; 2, 2; 1, 3
Player O has won the game!

Horizontal Victory
 4
 3       O
 2     O  
 1   X X X
 0
   0 1 2 3 4


Player X: 1, 1; 2, 1; 3, 1
Player X has won the game!

Vertical Victory
 4
 3   X   O
 2     X O
 1   X   O
 0
   0 1 2 3 4


Player O: 3, 1; 3, 2; 3, 3
Player O has won the game!

--------------------------------------------------

Testing Gomoku: 
1. running gomoku:
input: Lab4TeamEAR.exe gomoku
output:
 20
 19     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 18     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 17     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 16     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 15     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 14     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 13     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 12     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 11     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 10     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  9     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  8     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  7     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  6     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  5     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  4     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  3     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  2     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  1     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  0
     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

Turn 1
It is B's turn.
Input 'quit' to exit program or input a coordinate in the following form: '0, 0'.

---tests 2-7 assume tictac toe has been started successfullly---

2. Placing out of bounds:
input: 0,0
output:
Invalid coordinates. Try again.

3. invalid input:
input: 2
output:
Invalid input. Please try again.

4. piece already at specified location (there is already a piece at 1,1 in this example)
input: 1,1
output: 
Location already contains a game piece. Try again.

5. draw game:
---we first tested this by first making it a smaller 3x3 board, and then testing a draw
since testing with a full 19X19 board would take too long
the draw output is the same as tictac toe:
No winning moves can be made. 9 turns were played in the process.
--we then took the time to test the full 19x19 board
 20
 19     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  -
 18     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  -
 17     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  -
 16     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
 15     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
 14     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
 13     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
 12     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
 11     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
 10     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
  9     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
  8     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
  7     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
  6     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
  5     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
  4     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
  3     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
  2     W  B  W  B  B  W  W  B  W  B  B  W  W  B  W  B  B  W  W
  1     B  W  B  W  W  B  B  W  B  W  W  B  B  W  B  W  W  B  B
  0
     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20


Black's moves: 1,1; 1,3; 1,5; 1,7; 1,9; 1,11; 1,13; 1,15; 1,17; 1,19; 2,2; 2,4; 2,6; 2,8; 2,10; 2,12; 2,14; 2,16; 2,18; 3,1; 3,3; 3,5; 3,7; 3,9; 3,11; 3,13; 3,15; 3,17; 3,19; 4,2; 4,4; 4,6; 4,8; 4,10; 4,12; 4,14; 4,16; 4,18; 6,1; 6,3; 6,5; 6,7; 6,9; 6,11; 6,13; 6,15; 6,17; 6,19; 5,2; 5,4; 5,6; 5,8; 5,10; 5,12; 5,14; 5,16; 5,18; 7,1; 7,3; 7,5; 7,7; 7,9; 7,11; 7,13; 7,15; 7,17; 7,19; 8,2; 8,4; 8,6; 8,8; 8,10; 8,12; 8,14; 8,16; 8,18; 9,1; 9,3; 9,5; 9,7; 9,9; 9,11; 9,13; 9,15; 9,17; 9,19; 10,2; 10,4; 10,6; 10,8; 10,10; 10,12; 10,14; 10,16; 10,18; 12,1; 12,3; 12,5; 12,7; 12,9; 12,11; 12,13; 12,15; 12,17; 12,19; 11,2; 11,4; 11,6; 11,8; 11,10; 11,12; 11,14; 11,16; 11,18; 13,1; 13,3; 13,5; 13,7; 13,9; 13,11; 13,13; 13,15; 13,17; 13,19; 14,2; 14,4; 14,6; 14,8; 14,10; 14,12; 14,14; 14,16; 14,18; 15,1; 15,3; 15,5; 15,7; 15,9; 15,11; 15,13; 15,15; 15,17; 15,19; 16,2; 16,4; 16,6; 16,8; 16,10; 16,12; 16,14; 16,16; 16,18; 18,1; 18,3; 18,5; 18,7; 18,9; 18,11; 18,13; 18,15; 18,17; 18,19; 17,2; 17,4; 17,6; 17,8; 17,10; 17,12; 17,14; 17,16; 17,18; 19,1; 19,3; 19,5; 19,7; 19,9; 19,11; 19,13; 19,15;
White's moves: 1,2; 1,4; 1,6; 1,8; 1,10; 1,12; 1,14; 1,16; 1,18; 2,1; 2,3; 2,5; 2,7; 2,9; 2,11; 2,13; 2,15; 2,17; 2,19; 3,2; 3,4; 3,6; 3,8; 3,10; 3,12; 3,14; 3,16; 3,18; 4,1; 4,3; 4,5; 4,7; 4,9; 4,11; 4,13; 4,15; 4,17; 4,19; 6,2; 6,4; 6,6; 6,8; 6,10; 6,12; 6,14; 6,16; 6,18; 5,1; 5,3; 5,5; 5,7; 5,9; 5,11; 5,13; 5,15; 5,17; 5,19; 7,2; 7,4; 7,6; 7,8; 7,10; 7,12; 7,14; 7,16; 7,18; 8,1; 8,3; 8,5; 8,7; 8,9; 8,11; 8,13; 8,15; 8,17; 8,19; 9,2; 9,4; 9,6; 9,8; 9,10; 9,12; 9,14; 9,16; 9,18; 10,1; 10,3; 10,5; 10,7; 10,9; 10,11; 10,13; 10,15; 10,17; 10,19; 12,2; 12,4; 12,6; 12,8; 12,10; 12,12; 12,14; 12,16; 12,18; 11,1; 11,3; 11,5; 11,7; 11,9; 11,11; 11,13; 11,15; 11,17; 11,19; 13,2; 13,4; 13,6; 13,8; 13,10; 13,12; 13,14; 13,16; 13,18; 14,1; 14,3; 14,5; 14,7; 14,9; 14,11; 14,13; 14,15; 14,17; 14,19; 15,2; 15,4; 15,6; 15,8; 15,10; 15,12; 15,14; 15,16; 15,18; 16,1; 16,3; 16,5; 16,7; 16,9; 16,11; 16,13; 16,15; 16,17; 16,19; 18,2; 18,4; 18,6; 18,8; 18,10; 18,12; 18,14; 18,16; 18,18; 17,1; 17,3; 17,5; 17,7; 17,9; 17,11; 17,13; 17,15; 17,17; 17,19; 19,2; 19,4; 19,6; 19,8; 19,10; 19,12; 19,14; 19,16;
No possible wins for either side. Draw.
No winning moves can be made. 358 turns were played in the process.

---exits the program---

6. quiting game (assuming one turn has already been played):
input: quit
output:
Game has been quit.
Player B has quit the game. 1 turn was played in the process.

7. a player wins:
input: ---player turns are shown on bottom of output---
output:
 20
 19     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 18     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 17     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 16     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 15     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 14     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 13     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 12     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 11     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
 10     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  9     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  8     -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  7     -  -  -  -  -  W  -  -  -  -  -  -  -  -  -  -  -  -  -
  6     -  -  -  W  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  5     B  -  -  W  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  4     B  -  -  -  -  -  W  -  -  -  -  -  -  -  -  -  -  -  -
  3     B  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  2     B  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  1     B  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
  0
     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20


Black's moves: 1,1; 1,2; 1,3; 1,4; 1,5;
White's moves: 4,5; 6,7; 7,4; 4,6;
Win on column: 1
Player B has won the game!


---------------------------------------------------------------------------------------------------------
Extra Credit: 
 We implemented the extra credit as such:

 If one argument was passed, this was thought to be the board length:

	If board length was less than 3 or more than 64, we returned a null game and gave a helpful user message.
		If more than 64, we could not fit all the columns in one line of a full screen console app.

	If board length was 3, we just returned a tictactoe game since that is what a 3x3 gomoku board would be.

	if board length was 4, we set both the wincount and board length to 4 and returned a gomoku game with those parameters.

	if board length was 5 or more, wincount was set to 5 and board length was set to whatever was specified.
	

If two arguments were passed in: the first argument was the board length, and the second was the win count
	
	If board length was less than 3 or more than 64, we returned a null game and gave a helpful user message.
		If more than 64, we could not fit all the columns in one line of a full screen console app.

	If board length was 3, we just retruned a tictactoe game since that is what a 3x3 gomoku board would be.

	if board length was 4, we set both the wincount and board length to 4 and returned a gomoku game with those parameters.

	If wincount was more than board length, we returned a helpful message and a null pointer.

	If board length was 3 or 4, we did the same as what we said if 1 argument was passed in.

	If win count was less than 2, the game would be unplayable, so we said this and returned a null value



--------------------------------------------------

Test Cases: (1 extra argument)

1. Board length less than 3:
output: 
Make sure when entering the length of the board, it is 3 or more. You entered: 2
Please try again.

2. board length 3:
output:
You entered 3 for game size. This is the same as playing Tic Tac Toe. So we are running Tic Tac Toe
 4
 3   - - -
 2   - - -
 1   - - -
 0
   0 1 2 3 4

Turn 1
Player X, it is your turn to input something.
Input 'quit' to exit program or input a coordinate in the following form: '0, 0'.
---Runs as expected like a tictac toe game, see above for how tic tac toe runs---

3. board length anything higher than 3: (example - 12)
output:
 13
 12     -  -  -  -  -  -  -  -  -  -  -  -
 11     -  -  -  -  -  -  -  -  -  -  -  -
 10     -  -  -  -  -  -  -  -  -  -  -  -
  9     -  -  -  -  -  -  -  -  -  -  -  -
  8     -  -  -  -  -  -  -  -  -  -  -  -
  7     -  -  -  -  -  -  -  -  -  -  -  -
  6     -  -  -  -  -  -  -  -  -  -  -  -
  5     -  -  -  -  -  -  -  -  -  -  -  -
  4     -  -  -  -  -  -  -  -  -  -  -  -
  3     -  -  -  -  -  -  -  -  -  -  -  -
  2     -  -  -  -  -  -  -  -  -  -  -  -
  1     -  -  -  -  -  -  -  -  -  -  -  -
  0
     0  1  2  3  4  5  6  7  8  9 10 11 12 13

Turn 1
It is B's turn.
Input 'quit' to exit program or input a coordinate in the following form: '0, 0'.
---win count is 5, you can run the game and see that getting 5 in a row will be a win, 
as in regular gomoku, just a smaller board as seen below---

 13
 12     W  -  -  -  -  -  -  -  -  -  -  -
 11     -  -  -  -  -  -  -  -  -  -  -  -
 10     -  -  -  -  -  -  -  -  -  -  -  -
  9     -  -  -  -  -  -  -  -  -  -  -  -
  8     -  -  -  -  -  -  -  -  -  -  -  -
  7     -  -  -  -  -  -  -  -  -  -  -  -
  6     -  -  -  -  W  -  -  -  -  -  -  -
  5     -  -  -  W  B  -  -  -  -  -  -  -
  4     -  -  W  B  -  -  -  -  -  -  -  -
  3     -  -  B  -  -  -  -  -  -  -  -  -
  2     -  B  -  -  -  -  -  -  -  -  -  -
  1     B  -  -  -  -  -  -  -  -  -  -  -
  0
     0  1  2  3  4  5  6  7  8  9 10 11 12 13


Black's moves: 1,1; 2,2; 3,3; 4,4; 5,5;
White's moves: 1,12; 3,4; 4,5; 5,6;
Win on right to left diagonal starting at: 5,5
Player B has won the game!

4. Testing quit for board length not the size of default (19 x 19)

 13
 12     W  W  W  W  B  W  W  W  W  B  W  -
 11     B  B  B  B  W  B  B  B  B  W  B  -
 10     W  W  W  W  B  W  W  W  W  B  W  -
  9     B  B  B  B  W  B  B  B  B  W  B  B
  8     W  W  W  W  B  W  W  W  W  B  W  W
  7     B  B  B  B  W  B  B  B  B  W  B  B
  6     W  W  W  W  B  W  W  W  W  B  W  W
  5     B  B  B  B  W  B  B  B  B  W  B  B
  4     W  W  W  W  B  W  W  W  W  B  W  W
  3     B  B  B  B  W  B  B  B  B  W  B  B
  2     W  W  W  W  B  W  W  W  W  B  W  W
  1     B  B  B  B  W  B  B  B  B  W  B  B
  0
     0  1  2  3  4  5  6  7  8  9 10 11 12 13


Black's moves: 1,1; 1,3; 1,5; 1,7; 1,9; 1,11; 2,1; 2,3; 2,5; 2,7; 2,9; 2,11; 3,1; 3,3; 3,5; 3,7; 3,9; 3,11; 4,1; 4,3; 4,5; 4,7; 4,9; 4,11; 5,2; 5,4; 5,6; 5,8; 5,10; 5,12; 6,1; 6,3; 6,5; 6,7; 6,9; 6,11; 7,1; 7,3; 7,5; 7,7; 7,9; 7,11; 8,1; 8,3; 8,5; 8,7; 8,9; 8,11; 9,1; 9,3; 9,5; 9,7; 9,9; 9,11; 10,2; 10,4; 10,6; 10,8; 10,10; 10,12; 11,1; 11,3; 11,5; 11,7; 11,9; 11,11; 12,1; 12,3; 12,5; 12,7; 12,9;
White's moves: 1,2; 1,4; 1,6; 1,8; 1,10; 1,12; 2,2; 2,4; 2,6; 2,8; 2,10; 2,12; 3,2; 3,4; 3,6; 3,8; 3,10; 3,12; 4,2; 4,4; 4,6; 4,8; 4,10; 4,12; 5,1; 5,3; 5,5; 5,7; 5,9; 5,11; 6,2; 6,4; 6,6; 6,8; 6,10; 6,12; 7,2; 7,4; 7,6; 7,8; 7,10; 7,12; 8,2; 8,4; 8,6; 8,8; 8,10; 8,12; 9,2; 9,4; 9,6; 9,8; 9,10; 9,12; 10,1; 10,3; 10,5; 10,7; 10,9; 10,11; 11,2; 11,4; 11,6; 11,8; 11,10; 11,12; 12,2; 12,4; 12,6; 12,8;
No possible wins for either side. Draw.
No winning moves can be made. 141 turns were played in the process.

--------------------------------------------------

Test Cases (2 extra arguments)

1. Win count greater than length (length = 5, wincount = 6)
output:
Make sure your number of pieces needed to win is less than the gameboard side size.
If you need more pieces in a row to win than the length of your board, no one will ever be able to win!
You entered 5 for game board length and 6 pieces in a row for a win.
Since 5 is less than 6, this is an impossible game.
Will return an error code of 1 as the issue seems similar to the number of argument error (you have the wrong values / number for arguments)

2. having a length of 3 or 4 does the same thing as if given 1 argument of 3 or 4

3. win count less than 2 (example 1 or 0)
output:
Make sure your win count is 2 or more. Otherwise the game will be unfair or unplayable.
Will return an error code of 1 as the issue seems similar to the number of argument error (you have the wrong values / number for arguments)

4. a normal run (gameboard 10, win number 4)
(we went ahead and played, you can see what moves were played in the output)

 11
 10     -  -  -  -  -  -  -  -  -  -
  9     -  -  -  -  -  -  -  -  -  -
  8     -  -  W  -  -  -  -  -  -  -
  7     -  -  -  W  -  -  -  -  -  -
  6     -  -  -  -  -  -  -  -  -  -
  5     -  B  W  -  -  -  -  -  -  -
  4     -  B  -  -  -  -  -  -  -  -
  3     -  B  -  -  -  -  -  -  -  -
  2     -  B  -  -  -  -  -  -  -  -
  1     -  -  -  -  -  -  -  -  -  -
  0
     0  1  2  3  4  5  6  7  8  9 10 11


Black's moves: 2,2; 2,3; 2,5; 2,4;
White's moves: 3,5; 4,7; 3,8;
Win on column: 2
Player B has won the game!

5. Draw (gameboard 7, win number 5)
  8
  7     B  W  B  W  W  B  -
  6     W  B  W  B  B  W  -
  5     B  W  B  W  W  B  -
  4     W  B  W  B  B  W  W
  3     B  W  B  W  W  B  B
  2     W  B  W  B  B  W  W
  1     B  W  B  W  W  B  B
  0
     0  1  2  3  4  5  6  7  8


Black's moves: 1,1; 1,3; 1,5; 1,7; 2,2; 2,4; 2,6; 3,1; 3,3; 3,5; 3,7; 4,2; 4,4; 4,6; 6,1; 6,3; 6,5; 6,7; 5,2; 5,4; 5,6; 7,1; 7,3;
White's moves: 1,2; 1,4; 1,6; 2,1; 2,3; 2,5; 2,7; 3,2; 3,4; 3,6; 4,1; 4,3; 4,5; 4,7; 6,2; 6,4; 6,6; 5,1; 5,3; 5,5; 5,7; 7,2; 7,4;
No possible wins for either side. Draw.
No winning moves can be made. 46 turns were played in the process.