class Solution {
public:   
    int partition(vector<int> &nums, int left, int right) {
        int pivot_idx = left + (rand() % (right - left + 1));
        std::swap(nums[pivot_idx], nums[right]);
        int pivot = nums[right];
        int i = left - 1;
        for(int j = left; j <= right; ++j) {
            if(nums[j] < pivot) {
                ++i;
                std::swap(nums[j], nums[i]);
            }
        }
        std::swap(nums[i + 1], nums[right]);
        return (i + 1);
    }
    
    int quick_select(vector<int> &nums, int left, int right, int k) {
        int pos = partition(nums, left, right);
        if(pos == k) {
            return pos;
        } else if(pos < k) {
            return quick_select(nums, pos + 1, right, k);
        } else {
            return quick_select(nums, left, pos -1 , k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];
        return nums[quick_select(nums, 0, nums.size() - 1, nums.size() - k)];
    }
};