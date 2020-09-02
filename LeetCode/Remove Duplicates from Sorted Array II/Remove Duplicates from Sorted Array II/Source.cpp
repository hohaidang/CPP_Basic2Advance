#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int temp = nums[0], length = 1, count = 1, j = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == temp) {
				++count;
				if(count == 2)
					nums[j] = nums[i];
				if (count < 3) {
					++j;
				}
			}
			else {
				nums[j++] = nums[i];
				temp = nums[i];
				count = 1;
			}
		}
		return j;
	}
};

int main()
{
	Solution sol = Solution();
	vector<int> a = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 3, 3, 3 };

	cout << "length = " << sol.removeDuplicates(a) << endl;
	return 0;
}