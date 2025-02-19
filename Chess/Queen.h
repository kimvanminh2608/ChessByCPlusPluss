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

    bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest, vector<vector<ChessPiece*>> _board) const override
    {
        if (!(startRow == endRow || startCol == endCol || abs(startRow - endRow) == abs(startCol - endCol)) ||
            (dest != nullptr && !isOpponent(dest))) {
            return false;
        }

        if (startRow == endRow) // move <-->
        { 
            int step = (endCol > startCol) ? 1 : -1;
            for (int y = startCol + step; y != endCol; y += step)
            {
                if (_board[startRow][y] != nullptr) {
                    return false; // A piece is in the way
                }
            }
        }
        else if (startCol == endCol) { // Up down move
            int step = (endRow > startRow) ? 1 : -1;
            for (int x = startRow + step; x != endRow; x += step) {
                if (_board[x][startCol] != nullptr) {
                    return false; // A piece is in the way
                }
            }
        }
        else { // >< move
            int rowStep = (endRow > startRow) ? 1 : -1;
            int colStep = (endCol > startCol) ? 1 : -1;
            int row = startRow + rowStep;
            int col = startCol + colStep;
            while (row != endRow && col != endCol) {
                if (_board[row][col] != nullptr) {
                    return false; // A piece is in the way
                }
                row += rowStep;
                col += colStep;
            }
        }
        return true;
    }
};

