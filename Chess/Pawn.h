#pragma once
#include "ChessPiece.h"
using namespace std;
class Pawn :
    public ChessPiece
{
public:
	Pawn(string color) : ChessPiece("Pawn", color)
	{
	}

    bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest) const override {
        if (_color == "White") {
            if (startCol == endCol && startRow - endRow == 1 && dest == nullptr)
                return true;
            if (startCol == endCol && startRow == 6 && endRow == 4 && dest == nullptr)
                return true;
            if (abs(startCol - endCol) == 1 && startRow - endRow == 1 && isOpponent(dest))
                return true;
        }
        else {
            if (startCol == endCol && endRow - startRow == 1 && dest == nullptr)
                return true;
            if (startCol == endCol && startRow == 1 && endRow == 3 && dest == nullptr)
                return true;
            if (abs(startCol - endCol) == 1 && endRow - startRow == 1 && isOpponent(dest))
                return true;
        }
        return false;
    }
};

