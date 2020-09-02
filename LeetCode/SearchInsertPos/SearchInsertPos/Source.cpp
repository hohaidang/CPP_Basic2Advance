#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int pre = 0, pos = nums.size() - 1;
		int mid = (pos + pre) / 2;
		int count = 0;
		while (count <= nums.size() / 2) {
			if (nums[mid] > target)
			{
				pos = mid - 1;
				mid = (pos + pre) / 2;
			}
			else if (nums[mid] < target)
			{
				pre = mid + 1;
				mid = (pos + pre) / 2;
			}
			else
			{
				// found
				return mid;

			}
			++count;
		}
		auto idx = nums.begin();
		// pre <= pos;
		if (target < nums[pre])
		{
			nums.insert(idx, target);
			return 0;
		}
		else if (target > nums[pos])
		{
			nums.insert(idx + nums.size(), target);
			return nums.size() - 1;
		}
		else
		{
			nums.insert(idx + pre + 1, target);
			return pre + 1;
		}
	}
public:
	int searchInsert2(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int mid, l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
			else
			{
				return mid;
			}

		}

		auto it = nums.begin();
		nums.insert(it + l, target);
		return l;
	}
};

int main()
{
	Solution sol = Solution();
	vector<int> a = { 1,3,5,6 };
	auto pos = sol.searchInsert2(a, 9);
	return 0;
}