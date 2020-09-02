class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(auto &num : nums) {
            hashMap[num] += 1;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> answer;
        for(auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};