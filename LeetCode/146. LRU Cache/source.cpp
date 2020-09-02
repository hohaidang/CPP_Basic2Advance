#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

void showList(list<pair<int, int>> l) {
	for(auto it = l.begin(); it != l.end(); ++it) {
		cout << it->first << ":" << it->second << "   ";
	}
	cout << endl;
}

class LRUCache {
private:
	size_t m_capacity;
	unordered_map<int, list<pair<int, int>>::iterator> m_map;
	list<pair<int, int>> m_list;
public:
	LRUCache(size_t capacity) : m_capacity(capacity) {}
	
	int get(int key) {
		auto found_iter = m_map.find(key);
		if(found_iter == m_map.end())
			return -1;
		// move to front
		m_list.splice(m_list.begin(), m_list, found_iter->second);
		cout << "get" << endl;
		showList(m_list);
		return found_iter->second->second;
	}
	
	void put(int key, int value) {
		auto found_iter = m_map.find(key);
		if(found_iter != m_map.end()) {
			// move to front
			m_list.splice(m_list.begin(), m_list, found_iter->second);
			found_iter->second->second = value; // update value
			return;
		}
		if(m_map.size() == m_capacity) {
			int key_to_del = m_list.back().first;
			m_list.pop_back(); // remove node in list
			m_map.erase(key_to_del); // remove key in map
		}
		m_list.emplace_front(key, value); // create new node list
		m_map[key] = m_list.begin(); // create correspondence between key and node
		showList(m_list);
	}
};

int main() {
	LRUCache cache = LRUCache(2); // 2 capacity
	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1); // get value of key 1
	cache.put(3, 3); // key 2 is remove because least recent used
	cache.get(2); // return -1, not found;
	return 0;
}