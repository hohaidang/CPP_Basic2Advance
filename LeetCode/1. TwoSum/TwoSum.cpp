#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> RetData = {};
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if ((nums[i] + nums[j]) == target)
				{
					RetData.push_back(i);
					RetData.push_back(j);
					break;
				}
			}
		}
		
		return RetData;
	}

public:
	vector<int> twoSum2(vector<int>& nums, int target)
	{
		using MyMap = unordered_map<int, int>;
		MyMap myTable;
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i)
		{
			myTable.insert(make_pair(nums[i], i));
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			int complement = target - nums[i];
			auto find = myTable.find(complement);
			if (find != myTable.end() && find->second != i)
			{
				ret.push_back(i);
				ret.push_back(find->second);
				break;
			}
		}
		return ret;
	}

};

int main() {
	vector<int> input = { 3, 2, 4 };
	Solution sol = Solution();
	vector<int> solution(2, 0);

	/*auto data = sol.twoSum(input, 6);
	for (auto i = data.begin(); i < data.end(); ++i)
	{
		cout << *i << " ";
	}*/
	auto data2 = sol.twoSum2(input, 6);
	for (auto i = data2.begin(); i < data2.end(); ++i)
	{
		cout << *i << " ";
	}

}