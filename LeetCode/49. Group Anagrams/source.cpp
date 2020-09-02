class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for(auto &str : strs) {
            auto temp = str;
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(str);
        }
        vector<vector<string>> answer;
        for(auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            answer.push_back(it->second);
        }
        return answer;
    }
};