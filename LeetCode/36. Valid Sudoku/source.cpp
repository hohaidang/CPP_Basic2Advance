#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// hashTable
	bool isValidSudokuHash(vector<vector<char> > &board)
	{
		unordered_map<char, int> rows[9], cols[9], boxs[9];
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board.size(); ++j) {
				if (board[i][j] != '.') {
					continue;
				}
				int boxIdx = (i / 3) * 3 + j / 3;
				char data = board[i][j];
				rows[i][data] += 1;
				cols[j][data] += 1;
				boxs[boxIdx][data] += 1;
				if (rows[i][data] > 1 || cols[j][data] > 1 || boxs[boxIdx][data] > 1) {
					return false;
				}
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>> &board) {
		int rows[9][9] = { 0 }, cols[9][9] = { 0 }, boxs[9][9] = { 0 };
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0' - 1; // because idx of array go from 0
					int boxIdx = (i / 3) * 3 + j / 3;
					if (rows[i][num] == 1 || cols[j][num] == 1 || boxs[boxIdx][num] == 1) {
						return false;
					}
					rows[i][num] = cols[j][num] = boxs[boxIdx][num] = 1;
				}
			}
		}
		return true;
	}
};

int main(){
	vector<vector<char>> input = { { '5','5','.','.','5','.','.','1','.' },
								   { '.','4','.','4','.','.','.','.','.' },
								   { '.','.','.','.','.','3','.','.','1' },
								   { '8','.','.','.','.','.','.','2','.' },
								   { '.','.','2','.','7','.','.','.','.' },
								   { '.','1','5','.','.','.','.','.','.' },
								   { '.','.','.','.','.','2','.','.','.' },
								   { '.','2','.','9','.','.','.','.','.' },
								   { '.','.','4','.','.','.','.','.','.' } };
	Solution sol = Solution();
	cout << sol.isValidSudoku(input);
	system("pause");
	return 0;
}