#pragma once
#include "ChessPiece.h"
using namespace std;
class Queen :
    public ChessPiece
{
public:
    Queen(string color) : ChessPiece("Queen", color)
    {

    }

    bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest) const override
    {
        return (startRow == endRow || startCol == endCol || abs(startRow - endRow) == abs(startCol - endCol)) &&
            (dest == nullptr || isOpponent(dest));
    }
};

