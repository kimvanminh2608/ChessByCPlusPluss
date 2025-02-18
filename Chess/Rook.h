#pragma once
#include "ChessPiece.h"
using namespace std;
class Rook :
    public ChessPiece
{
public:
	Rook(string color) : ChessPiece("Rook", color)
	{
	}

	bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest) const override {
		return (startRow == endRow || startCol == endCol) && (dest == nullptr || isOpponent(dest));
	}
};

