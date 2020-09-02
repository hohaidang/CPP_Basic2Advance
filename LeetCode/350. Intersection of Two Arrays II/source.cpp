class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> hashMap;
        for(auto &num : nums1) {
            hashMap[num] += 1;
        }
        
        int k = 0;
        for(auto &num : nums2) {
            auto found = hashMap.find(num);
            // Better utilize array 1
            if(found != hashMap.end() && --found->second >= 0) {
                nums1[k++] = num;
            }
         }
        return vector<int>(nums1.begin(), nums1.begin() + k);
    }
};