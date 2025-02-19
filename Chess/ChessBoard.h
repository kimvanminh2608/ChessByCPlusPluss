#pragma once
#include "ChessPiece.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class ChessBoard
{
private:
	//Array vector 2D
	vector<vector<ChessPiece*>> _board;
public:
	ChessBoard()
	{
		_board.resize(8, vector<ChessPiece*>(8, nullptr));
		initializeBoard();
	}

	~ChessBoard()
	{
		for (auto& row : _board) {
			for (auto& piece : row) {
				delete piece;
			}
		}
	}

	//Create ChessPiece 8x8
	//0 1 2 3 4 5 6 7
	//1
	//2
	//3
	//4
	//5
	//6
	//7
	void initializeBoard()
	{
		_board[0] = { new Rook("Black"), new Knight("Black"), new Bishop("Black"), new Queen("Black"),
					new King("Black"), new Bishop("Black"), new Knight("Black"), new Rook("Black") };
		_board[1] = { new Pawn("Black"), new Pawn("Black"), new Pawn("Black"), new Pawn("Black"),
					new Pawn("Black"), new Pawn("Black"), new Pawn("Black"), new Pawn("Black") };

		_board[6] = { new Pawn("White"), new Pawn("White"), new Pawn("White"), new Pawn("White"),
					new Pawn("White"), new Pawn("White"), new Pawn("White"), new Pawn("White") };
		_board[7] = { new Rook("White"), new Knight("White"), new Bishop("White"), new Queen("White"),
					new King("White"), new Bishop("White"), new Knight("White"), new Rook("White") };
		
	}

	//Print ChessBoard
	void printBoard()
	{
		for (int row = 0; row < 8; ++row) {
			cout << (8 - row) << " ";
			for (int col = 0; col < 8; ++col) {
				if (_board[row][col] != nullptr) {
					cout << _board[row][col]->toString() << " ";
				}
				else {
					cout << ".  ";
				}
			}
			cout << endl;
		}
		cout << "   a  b  c  d  e  f  g  h" << endl;
	}

	// Check if any piece can attack the king
	bool isKingInCheck(string color) {
		int kingRow, kingCol;
		// Find the king's position
		for (int row = 0; row < 8; ++row) {
			for (int col = 0; col < 8; ++col) {
				if (_board[row][col] != nullptr && _board[row][col]->_name == "King" && _board[row][col]->_color == color) {
					kingRow = row;
					kingCol = col;
					break;
				}
			}
		}
		// Check if any opponent piece can attack the king
		for (int row = 0; row < 8; ++row) {
			for (int col = 0; col < 8; ++col) {
				ChessPiece* piece = _board[row][col];
				if (piece != nullptr && piece->_color != color) {
					if (piece->isValidMove(row, col, kingRow, kingCol, _board[kingRow][kingCol], _board)) {
						return true;
					}
				}
			}
		}
		return false;
	}

	// Simulate a move to check if it results in check
	bool simulateMoveAndCheck(string start, string end, string color) {
		int startRow = 8 - (start[1] - '0');
		int startCol = start[0] - 'a';
		int endRow = 8 - (end[1] - '0');
		int endCol = end[0] - 'a';

		ChessPiece* piece = _board[startRow][startCol];
		ChessPiece* dest = _board[endRow][endCol];

		// Simulate the move
		_board[endRow][endCol] = piece;
		_board[startRow][startCol] = nullptr;

		bool kingInCheck = isKingInCheck(color);

		// Undo the move
		_board[startRow][startCol] = piece;
		_board[endRow][endCol] = dest;

		return kingInCheck;
	}

	void movePiece(string start, string end) {
		int startRow = 8 - (start[1] - '0');
		int startCol = start[0] - 'a';
		int endRow = 8 - (end[1] - '0');
		int endCol = end[0] - 'a';

		ChessPiece* piece = _board[startRow][startCol];
		ChessPiece* dest = _board[endRow][endCol];

		if (piece != nullptr && piece->isValidMove(startRow, startCol, endRow, endCol, dest, _board)) {
			string playerColor = piece->_color;
			if (!simulateMoveAndCheck(start, end, playerColor)) {
				_board[endRow][endCol] = piece;
				_board[startRow][startCol] = nullptr;

				if (isKingInCheck(piece->_color == "White" ? "Black" : "White")) {
					cout << "Check!" << endl;
				}
			}
			else {
				cout << "Invalid move! Your King would be in check." << endl;
			}
		}
		else {
			cout << "Invalid move!" << endl;
		}
	}


};

