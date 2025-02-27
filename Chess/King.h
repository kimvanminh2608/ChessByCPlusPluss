#include <string>
#include "ChessPiece.h"
using namespace std;
class King :
    public ChessPiece
{
public:
	King(string color) : ChessPiece("King", color)
	{
		
	}

	bool isValidMove(int startRow, int startCol, int endRow, int endCol, ChessPiece* dest, vector<vector<ChessPiece*>> _board) const override
	{
        // Check if the move is within one square in any direction
        if (abs(startRow - endRow) > 1 || abs(startCol - endCol) > 1) {
            return false;
        }

        // Check if the destination is either empty or occupied by an opponent's piece
        if (dest != nullptr && !isOpponent(dest)) {
            return false;
        }

        return true;
	}
};

