#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		sort(nums.begin(), nums.end());
		auto temp = nums[0];
		for (auto i = nums.begin() + 1; i != nums.end();)
		{
			if (*i == temp)
			{
				i = nums.erase(i);
			}
			else
			{
				temp = *i;
				i++;
			}
		}
		return nums.size();
	}
	int removeElement(vector<int>& nums, int val) {
		if (nums.empty()) return 0;
		int i = 0;
		for (int j = 0; j < nums.size(); ++j) {
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				++i;
			}
		}
		return i;
	}

	int removeDuplicates3(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int j = 1;
		int temp = nums[0];

		for (int i = 1; i < nums.size(); ++i)
		{
			if (temp != nums[i])
			{
				nums[j] = nums[i];
				temp = nums[i];
				++j;
			}
		}
		return j;
	}

};

int main()
{
	vector<int> a = { 0,0,1,1,1,2,2,3,3,4 };
	Solution sol = Solution();
	/*sol.removeDuplicates(a);*/
	//vector <int> b = { 0,1,2,2,3,0,4,2 };
	//sol.removeElement(b, 2);
	sol.removeDuplicates3(a);
	return 0;
}