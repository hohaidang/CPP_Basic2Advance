#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
using PAIR = pair<int, int>;

class MyPriorityQueue {
private:
	vector<PAIR> Queue;
public:
	void push(PAIR data) {
		Queue.push_back(data);
		int i = Queue.size() - 1;
		while (i >= 1 && Queue[i / 2].second > Queue[i].second) {
			swap(Queue[i / 2], Queue[i]);
			i = i / 2;
		}
	}

	void pop() {
		if (Queue.empty()) {
			cout << "Cannot remove as queue is empty";
			return;
		}
		int size = Queue.size();
		Queue[0] = Queue[size - 1];
		Queue.pop_back();
		min_heapify(0);
	}

	int size() {
		return Queue.size();
	}

	PAIR top() {
		return Queue[0];
	}

	bool empty() {
		return Queue.empty();
	}

private:
	void min_heapify(int i) {
		int N = Queue.size();
		int minest_idx = i;
		int left = 2 * i;
		int right = 2 * i + 1;
		if (left < N && Queue[left].second < Queue[i].second)
			minest_idx = left;
		if (right < N && Queue[right].second < Queue[minest_idx].second)
			minest_idx = right;
		if (minest_idx != i) {
			swap(Queue[minest_idx], Queue[i]);
			min_heapify(minest_idx);
		}
	}
};

/**
 * Find and return list of ids base on largest numeric value
 *
 * @param[in] path: path of file input data.
 * @param[in] Xlargest: number of largest value
 * @return list of the unique ids
 */
vector<int> findSubArrayLargest(const string &path, const int XLargest) {
	vector<int> answer;
	ifstream inFile;
	inFile.open(path);
	if (!inFile) {
		cout << "\nUnable to open file";
		return answer;
	}
	MyPriorityQueue PriorityQueue = MyPriorityQueue();
	int ids = 0, val = 0;
	while (inFile >> ids >> val) {
		PriorityQueue.push(PAIR(ids, val));
		if (PriorityQueue.size() > XLargest)
			PriorityQueue.pop();
	}

	while (!PriorityQueue.empty()) {
		answer.push_back(PriorityQueue.top().first);
		PriorityQueue.pop();
	}
	return answer;
}

void showOutput(const vector<int> &answer) {
	for (const auto &data : answer)
		cout << data << endl;
}

int main() {
	string path;
	int XLargest = 0;
	cout << "Enter input data path: ";
	cin >> path;
	cout << "\nEnter number of largest value (X-largest): ";
	cin >> XLargest;
	auto answer = findSubArrayLargest(path, XLargest);
	cout << "Data output:" << endl;
	showOutput(answer);

	return 0;
}