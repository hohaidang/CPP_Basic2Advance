/*
 * main.cpp
 *
 *  Created on: Jun 15, 2020
 *      Author: prnsoft
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void showVector(vector<vector<int>> v) {
	for(int i = 0; i < v.size(); ++i) {
		for(int j = 0; j < v[i].size(); ++j) {
			cout << v[i][j] << " "  << endl;
		}
	}
}

class Solution {
public:
    vector<vector<int>> threeSumTimeLimited(vector<int>& nums) {
        set<pair<int, int>> found;
        vector<vector<int>> answer;

        for(int i = 0; i < nums.size(); ++i) {
            unordered_set<int> seem;
            for(int j = i + 1; j < nums.size(); ++j) {
                int complement = -nums[j] - nums[i];
                if(seem.count(complement) > 0) {
                    // v1, v2 is key, related to max and min in 3 number
                    int v1 = min(nums[i], min(complement, nums[j]));
                    int v2 = max(nums[i], max(complement, nums[j]));
                    if(found.insert(make_pair(v1, v2)).second == true) {
                        // First seen
                        answer.push_back({nums[i], nums[j], complement});
                    }
                }
                seem.insert(nums[j]);
            }
        }
        return answer;
    }
    vector<vector<int>> threeSumOpimize(vector<int> &nums) {
    	vector<vector<int>> res;
    	set<pair<int, int>> found;
    	unordered_set<int> dups;
    	unordered_map<int, int> seen;
    	for(int i = 0; i < nums.size(); ++i) {
    		if(dups.insert(nums[i]).second) {
    			for(int j = i + 1; j < nums.size(); ++j) {
    				int complement = -nums[i] - nums[j];
    				auto it = seen.find(complement);
    				if(it != seen.end() && it->second == i) {
    					int v1 = min(nums[i], min(complement, nums[j]));
    					int v2 = max(nums[i], max(complement, nums[j]));
    					if(found.insert({v1, v2}).second) {
    						res.push_back({nums[i], complement, nums[j]});
    					}
    				}
    				seen[nums[j]] = i;
    			}
    		}
    	}
    	return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
    	set<pair<int, int>> hashSet;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) {
            if(i == 0 || nums[i] != nums[i - 1]) { // ignore duplicate of i
                checkSum(nums, i, answer);
            }

        }
        return answer;
    }

    void checkSum(vector<int> &nums, int i, vector<vector<int>> &answer) {
        int j = i + 1, k = nums.size() - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0 || (j > i + 1 && nums[j] == nums[j - 1])) { // ignore duplicate
                ++j;
            }
            else if (sum > 0 || ((k < nums.size() - 1) && nums[k] == nums[k + 1])) {
                --k;
            }
            else {
                answer.push_back({nums[i], nums[j++], nums[k--]});
            }
        }
    }
};

int main()
{
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	Solution sol = Solution();
	auto result = sol.threeSumOpimize(nums);
	for(int i = 0; i < result.size(); ++i) {
		for(int j = 0; j < result[i].size(); ++j) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
