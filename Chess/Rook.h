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

	bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest, vector<vector<ChessPiece*>> _board) const override
	{
        if (startRow != endRow && startCol != endCol) {
            return false; // Rook can only move in straight lines
        }

        if (dest != nullptr && !isOpponent(dest)) {
            return false; // Destination is occupied by an ally piece
        }

        if (startRow == endRow) { // Horizontal move
            int step = (endCol > startCol) ? 1 : -1;
            for (int y = startCol + step; y != endCol; y += step) {
                if (_board[startRow][y] != nullptr) {
                    return false; // A piece is in the way
                }
            }
        }
        else if (startCol == endCol) { // Vertical move
            int step = (endRow > startRow) ? 1 : -1;
            for (int x = startRow + step; x != endRow; x += step) {
                if (_board[x][startCol] != nullptr) {
                    return false; // A piece is in the way
                }
            }
        }

        return true; // No pieces in the way
	}
};

