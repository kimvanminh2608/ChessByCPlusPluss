#pragma once
#include "ChessPiece.h"
using namespace std;
class Knight :
    public ChessPiece
{
public:
	Knight(string color) : ChessPiece("Knight", color)
	{
	}

	bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest, vector<vector<ChessPiece*>> _board) const override
	{
		return ((abs(startRow - endRow) == 2 && abs(startCol - endCol) == 1) ||
			(abs(startRow - endRow) == 1 && abs(startCol - endCol) == 2)) 
			&& (dest == nullptr || isOpponent(dest));
	}
};

