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
		int step = 0;
		bool result = true;
		if ((dest == nullptr || isOpponent(dest)))
		{
			if (startRow == endRow) // move <-->
			{
				step = (endCol > startCol) ? 1 : -1;
				for (int y = startCol + step; y != endCol; y+= step)
				{
					ChessPiece* piece = _board[startRow][y];
					if (piece != nullptr)
					{
						if (!isOpponent(piece))
						{
							return false; // An ally piece is in the way
						}
					}
				}
			}

			if (startCol == endCol) // move up and down
			{
				step = (endRow > startRow) ? 1 : -1;
				for (int x = startRow + step; x != endRow; x += step)
				{
					ChessPiece* piece = _board[x][startCol];
					if (piece != nullptr)
					{
						if (!isOpponent(piece))
						{
							return false; // An ally piece is in the way
						}
					}
				}
			}
			
		}
		else
		{
			result = false;
		}
		
		return result;
	}
};

