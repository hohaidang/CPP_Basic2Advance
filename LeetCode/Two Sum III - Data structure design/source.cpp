class TwoSum {
public:
    /** Initialize your data structure here. */
    // Tu lam
    multiset<int> hashSet;
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        hashSet.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if(hashSet.empty()) {
            return false;
        }
        auto left = hashSet.begin();
        auto right = --hashSet.end();
        while (left != right) {
            int sum = *left + *right;
            if(sum > value) {
                --right;
            }
            else if (sum < value) {
                ++left;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */