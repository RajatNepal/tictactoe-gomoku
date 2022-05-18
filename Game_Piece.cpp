// Game_Piece.cpp
// Author: Eric Yelong Tabuchi
// Email: e.tabuchi@wustl.edu
// The purpose of this source file is to define the constructor
// for the game piece which just sets the symbol for said piece.

#include "Game_Piece.h"
#include <iostream>

using namespace std;

//piece struct
piece::piece(string symbol) : symbol_(symbol) {}