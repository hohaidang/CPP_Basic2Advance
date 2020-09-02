#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>> & matrix) {
		if(matrix.empty()) {
			return {};
		}
		vector<int> answer;
		int N = matrix.size();
		int M = matrix[0].size();
		for(int s = 0; s < N + M - 1; ++s) {
			for(int x = 0; x <= s; ++x) {
				int i = x;
				int j = s - i;
				if(s % 2 == 0) {
					swap(i, j);
				}
				if(i >= N || j >= M) continue;
				answer.push_back(matrix[i][j]);
			}
		}
		return answer;
	}
};

int main() {
	vector<vector <int>> array = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution sol = Solution();
	auto answer = sol.findDiagonalOrder(array);
	auto show = [&answer](){
		for(int i = 0; i < answer.size(); ++i) {
			cout << answer[i] << "  ";
		}
	};
	show();
	return 0;
}