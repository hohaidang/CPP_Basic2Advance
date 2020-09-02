#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
    // co tham khao dap an
public:
    // map
    list<pair<int, int>> *hashMap;
    int sizeMap = 10000;
    
    /** Initialize your data structure here. */
    MyHashMap() {
        hashMap = new list<pair<int, int>>[sizeMap];
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = hashMap[key % sizeMap];
        for(auto &it : list) {
            if(it.first == key) {
                // key existed
                it.second = value; // change value
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &list = hashMap[key % sizeMap];
        for(auto &it : list) {
            if(it.first == key) {
                return it.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = hashMap[key % sizeMap];
		list.remove_if([key](auto n) {
			return n.first == key;
		});
    }
};

int main() {
	HashMap hashtable = HashMap();
	hashtable.put(1, 2);
	hashtable.put(1, 3);
	hashtable.put(2, 3);

	hashtable.remove(1);
	return 0;
}