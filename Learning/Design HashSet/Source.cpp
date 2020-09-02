#include <iostream>
#include <list>
using namespace std;

class HashSet {
public:
	int bucket;
	list<int> *table;
	/*Initialize your data structure here. */
public:
	HashSet() {
		bucket = 1000;
		table = new list<int>[bucket];
	}

	void add(int key) {
		int hashkey = key % bucket;
		table[hashkey].push_back(key);
	}

	void remove(int key) {
		int index = key % bucket;
		list <int> ::iterator i;
		for (i = table[index].begin(); i != table[index].end(); i++) {
			if (*i == key)
				break;
		}

		// if key is found in hash table, remove it 
		if (i != table[index].end())
			table[index].erase(i);
	}

	/*Return true if this set contains the specified element*/
	bool contains(int key) {
		int hashKey = key % bucket;
		for (auto &it : table[hashKey]) {
			if (it == key) return true;
		}
		return false;
	}

	void displayHash() {
		for (int i = 0; i < 5; i++) {
			cout << i;
			for (auto x : table[i])
				cout << " --> " << x;
			cout << endl;
		}
	}
};

int main() {
	HashSet hashSet = HashSet();
	hashSet.add(1);
	hashSet.add(4);
	hashSet.add(2);
	hashSet.displayHash();
	hashSet.remove(2);
	//cout << hashSet.contains(2);    // returns false (already removed)


	return 0;
}
