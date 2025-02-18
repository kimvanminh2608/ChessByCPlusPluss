#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:

    Bishop(string color) : ChessPiece("Bishop", color) {}

    bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest) const override
    {
        return abs(startRow - endRow) == abs(startCol - endCol) && (dest == nullptr || isOpponent(dest));
    }
};