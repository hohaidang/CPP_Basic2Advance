class Solution {
public:
	// Slide Windows hash set
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		set<char> hashSet;
		int ans = 0, i = 0, j = 0;
		while (i < n && j < n) {
			if (hashSet.count(s[j]) == 0) {
				hashSet.insert(s[j++]);
				ans = max(ans, j - i);
			}
			else {
				hashSet.erase(s[i++]);
			}
		}
		return ans;
	}
	
	// Optimize Slide Windows hash set
	int lengthOfLongestSubstring(string s) {
		int n = s.size(), ans = 0;
		unordered_map<char, int> hashMap;
		for (int j = 0, i = 0; j < n; ++j) {
			if (hashMap.count(s[j]) > 0) {
				i = max(i, hashMap[s[j]]);
			}
			ans = max(ans, j - i + 1);
			hashMap[s[j]] = j + 1;
		}
		return ans;
	}
};