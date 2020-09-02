#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    	unordered_map<string, int> hashMap;
    	for(int i = 0; i < list1.size(); ++i) {
    		hashMap.insert(make_pair(list1[i], i));
    	}

    	int sum_min = INT_MAX, sum = 0;
    	vector<string> answer;
    	for(int i = 0; i < list2.size(); ++i) {
    		auto found = hashMap.find(list2[i]);
    		if(found != hashMap.end()) {
    			sum = i + found->second;
    			if(sum < sum_min) {
    				// Restaunrent co priority thap hon
    				answer.clear();
    				answer.push_back(found->first);
    				sum_min = sum;
    			}
    			else if(sum == sum_min) {
    				// restaurent co cung priority thap nhat
    				answer.push_back(found->first);
    			}
    		}
    	}
    	return answer;
    }
};

int main() {
	vector<string> l1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> l2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	Solution sol = Solution();
	auto answer = sol.findRestaurant(l1, l2);
	for(auto &data : answer) {
		cout << data;
	}
	return 0;
}
