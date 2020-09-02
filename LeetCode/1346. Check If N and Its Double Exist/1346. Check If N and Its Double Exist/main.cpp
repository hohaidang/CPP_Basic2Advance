#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;



class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hashSet;
        for(auto &element : arr) {
            int mul = element * 2;
            int div = element / 2;
            if(hashSet.count(mul) > 0){
                return true;
            }
            else if(hashSet.count(div) > 0 && element % 2 == 0) {
                return true;
            }
            else {
                hashSet.insert(element);
            }
        }
        return false;
    }
};

int main () {
    vector<int> array = {10, 2, 5, 3};
    Solution sol = Solution();
    sol.checkIfExist(array);
    return 0;
}

int minSubArrayLen(int s, vector<int>& nums) {
    int left = 0;
    int sum = 0;
    int min_len = INT_MAX;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        while(sum >= s) {
            min_len = min(min_len, i - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return (min_len == INT_MAX) ? 0 : min_len;
}
