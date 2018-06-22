//-------------------------------------------------------------------------
//136. Single Number
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//A sudoku solution must satisfy all of the following rules:
//
//Each of the digits 1-9 must occur exactly once in each row.
//Each of the digits 1-9 must occur exactly once in each column.
//Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//Empty cells are indicated by the character '.'.
//Note:
//
//The given board contain only digits 1-9 and the character '.'.
//You may assume that the given Sudoku puzzle will have a single unique solution.
//The given board size is always 9x9.
//---------------------------------------------------------------------------


#include <vector>
#include <algorithm> 

using namespace std;

namespace
{
	bool IsCanPutInRow(const vector<vector<char>>& board, char x, char y, char input)
	{
		for (char i = 0; i < 9; i++) {
			if (board[y][i] == input) return false;
		}

		return true;
	}

	bool IsCanPutInCol(const vector<vector<char>>& board, char x, char y, char input)
	{
		for (char i = 0; i < 9; i++) {
			if (board[i][x] == input) return false;
		}

		return false;
	}


	bool IsCanPutInBox(const vector<vector<char>>& board, char x, char y, char input)
	{
		char idxX = x / 3;
		char idxY = y / 3;

		for (char i = idxX * 3; i < ((idxX + 1) * 3); i++) {
			for (char j = idxY * 3; j < ((idxY + 1) * 3); j++) {
				if (board[j][i] == input) return false;
			}
		}

		return true;
	}


	void PutNumber(const vector<vector<char>>& board, char x, char y, char number)
	{

	}
}

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {

		vector<vector<char>> solid;
		solid.resize(9);
		for (char j = 0; j < 9; j++) {
			solid[j].resize(9,false);
			for (char i = 0; i < 9; i++) {
				if (board[j][i] != '.') {
					solid[j][i] = true;
				}
			}
		}


	}
};

int main()
{
	vector<vector<char>> board = { 
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};

	Solution so;
	so.solveSudoku(board);

	return 0;

}