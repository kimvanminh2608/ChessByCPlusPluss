#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:

    Bishop(string color) : ChessPiece("Bishop", color) {}

    bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest, vector<vector<ChessPiece*>> _board) const override
    {
        if (abs(startRow - endRow) != abs(startCol - endCol) || (dest != nullptr && !isOpponent(dest)))
            return false;

        int rowStep = (endRow > startRow) ? 1 : -1;
        int colStep = (endCol > startCol) ? 1 : -1;

        int row = startRow + rowStep;
        int col = startCol + colStep;
        while (row != endRow && col != endCol) 
        {
            ChessPiece* piece = _board[row][col];
            if (piece != nullptr) {
                return false; // A piece is in the way
            }
            row += rowStep;
            col += colStep;
        }

        return true;
    }
};