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

		return true;
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


	bool IsCanPutNumber(vector<vector<char>>& board, char x, char y, char number)
	{
		bool isCanPut = IsCanPutInRow(board, x, y, number);
		if (isCanPut == false) {
			return isCanPut;
		}

		isCanPut = IsCanPutInCol(board, x, y, number);
		if (isCanPut == false) {
			return isCanPut;
		}

		isCanPut = IsCanPutInBox(board, x, y, number);
		if (isCanPut == false) {
			return isCanPut;
		}

		return true;
	}

	bool PutNumber(vector<vector<char>>& board, char x, char y, char number)
	{
		bool isCanPut = IsCanPutNumber(board, x, y, number);
		if (isCanPut == true) {
			board[y][x] = number;
		}

		return isCanPut;
	}

	struct available
	{
		vector<char> unused;
		vector<char> used;

		bool isAvailable()
		{
			if (unused.empty() && used.empty())
				return false;
			else
				return true;
		}

		void recover()
		{
			size_t count = used.size();
			for (size_t i = 0; i < count; i++) {
				unused.push_back(used[i]);
			}
			used.clear();
		}
	};


	bool Solve(vector<vector<char>>& board, vector<vector<available>>& availables, char x, char y)
	{
		while (!availables[y][x].isAvailable())
		{
			x++;
			if (x == 9) {
				y++;
				x = 0;
				if (y == 9) return true;//complete
			} 
		}

		available& data = availables[y][x];
		while (!data.unused.empty())
		{
			char number = data.unused.back();
			data.unused.pop_back();
			data.used.push_back(number);
			bool isPuted = PutNumber(board, x, y, number);
			if (isPuted)
			{
				char nextX=x;
				char nextY=y;
				nextX++;
				if (nextX == 9) {
					nextY++;
					nextX = 0;
					if (nextY == 9) return true;//complete
				}

				bool isNextSolved = Solve(board, availables, nextX, nextY);
				if (isNextSolved) {
					return true;
				} 
			} 
		}

		data.recover();
		board[y][x] = '.';
		return false;
	}

}

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {

		vector<vector<available>> availables;
		availables.resize(9);
		for (char j = 0; j < 9; j++) {
			availables[j].resize(9);
			for (char i = 0; i < 9; i++) {
				if (board[j][i] != '.') continue;
				for (char k = 0; k < 9; k++) {
					char value = '1' + k;
					bool isCanPut = IsCanPutNumber(board, i, j, value);
					if (isCanPut == false) continue;
					availables[j][i].unused.push_back(value);
				}
			}
		}

		Solve(board, availables, 0, 0);

		for (char j = 0; j < 9; j++) {
			for (char i = 0; i < 9; i++) {
				printf("%c,", board[j][i]);
			}
			printf("\n");
		}

	}
};

//int main()
//{
//	vector<vector<char>> board = { 
//		{'5','3','.','.','7','.','.','.','.'},
//		{'6','.','.','1','9','5','.','.','.'},
//		{'.','9','8','.','.','.','.','6','.'},
//		{'8','.','.','.','6','.','.','.','3'},
//		{'4','.','.','8','.','3','.','.','1'},
//		{'7','.','.','.','2','.','.','.','6'},
//		{'.','6','.','.','.','.','2','8','.'},
//		{'.','.','.','4','1','9','.','.','5'},
//		{'.','.','.','.','8','.','.','7','9'}};
//
//	Solution so;
//	so.solveSudoku(board);
//
//	system("pause");
//
//	return 0;
//
//}