#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int minCost(vector<vector<int>> &costs) {
		int totalCost = 0;
		int preMinIdx = -1;
		for (int i = 0; i < costs.size(); ++i) {
			auto min_idx = distance(costs[i].begin(), min_element(costs[i].begin(), costs[i].end()));
			int minVal = costs[i][min_idx];
			if (min_idx != preMinIdx) {
				totalCost += minVal;
			}
			else {
				int temp = INT_MAX;
				for (int j = 0; j < costs[i].size(); ++j) {
					if (j == min_idx) continue;
					if (costs[i][j] < temp) {
						min_idx = j;
						temp = costs[i][j];
					}
				}
				/*costs[i].erase(costs[i].begin() + min_idx, costs[i].begin() + min_idx + 1);
				min_idx = distance(costs[i].begin(), min_element(costs[i].begin(), costs[i].end()));*/
				minVal = costs[i][min_idx];
				totalCost += minVal;
				
			}
			preMinIdx = min_idx;
		}
		return totalCost;
	}
};

int main()
{
	Solution sol = Solution();
	vector<vector <int>> cost = { {5, 8, 6}, {19, 14, 13}, {7, 5, 12}, {14, 15, 17}, {3, 20, 10} };
	cout << "cost = " << sol.minCost(cost) << endl;
	return 0;
}