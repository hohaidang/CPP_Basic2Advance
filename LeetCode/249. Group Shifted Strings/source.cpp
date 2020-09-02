class Solution {
public:
    void convertStringToKey(string &str) {
        while(str[0] != 'a') {
            for(int i = 0; i < str.size(); ++i) {
                str[i] += 1;
                if(str[i] > 'z') {
                    str[i] = 'a';
                }
            }
        }    
    }
    
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashMap;
        for(auto &str : strings) {
            string temp = str;
            convertStringToKey(temp);
            hashMap[temp].push_back(str);
        }
        
        vector<vector<string>> answer;
        for(auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            answer.push_back(it->second);
        }
        return answer;
    }
};