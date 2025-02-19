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
		return (abs(startRow - endRow) <= 1 ||
			abs(startCol - endCol) <= 1) ||
			(dest == nullptr || isOpponent(dest));
	}
};

