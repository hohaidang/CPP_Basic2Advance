class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> hashMap;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashMap.count(val) > 0) 
            return false;
        nums.push_back(val);
        hashMap[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashMap.count(val) == 0) 
            return false;
        int last = nums.back();
        hashMap[last] = hashMap[val];
        nums[hashMap[last]] = last;
        nums.pop_back();
        hashMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */