#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using PAIR = pair<int, int>;

class MyPriorityQueue {
private:
	vector<PAIR> Queue;
public:
	/**
	 * Push new element into heap
	 *
	 * @param[in] data: new data
	 * @return: void
	 */
	void push(const PAIR data) {
		Queue.push_back(data);
		int i = Queue.size() - 1;
		/* Re-structure heap, min data become root */
		while (i >= 1 && Queue[i / 2].second > Queue[i].second) {
			swap(Queue[i / 2], Queue[i]);
			i = i / 2;
		}
	}

	/**
	 * pop heap with higest priority (minimum number)
	 *
	 * @param: void
	 * @return: void
	 */
	void pop() {
		if (Queue.empty()) {
			cout << "Cannot remove as queue is empty";
			return;
		}
		int size = Queue.size();
		Queue[0] = Queue[size - 1];
		Queue.pop_back();
		min_heapify(0); /* Re-structure heap, min data become root */
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
	/**
	 * Re-structure heap, min data become root
	 *
	 * @param[in]: start index for checking
	 * @return: void
	 */
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
		cout << "\nUnable to open file. Please check path again!" << endl;
		return answer;
	}
	MyPriorityQueue PriorityQueue = MyPriorityQueue();
	int ids = 0, val = 0;

	/* We call n is the size of data input and k is number of largest output (XLargest).
	   We will have time complexity for this while loop:
	   The time complexity of adding an element in to heap is O(logk)
	   The time complexity of looping all input data is O(n)
	   Total time complexity: O(logk) + O(n) = O(Nlogk)	
	   Total space complexity: O(k) to store heap element
	*/
	while (inFile >> ids >> val) {
		PriorityQueue.push(PAIR(ids, val));
		if (PriorityQueue.size() > XLargest)
			PriorityQueue.pop();
	}

	/* The time complexity for pop all data from heap is O(k) if k small -> O(k) ~ O(1)*/
	while (!PriorityQueue.empty()) {
		answer.push_back(PriorityQueue.top().first);
		PriorityQueue.pop();
	}

	/* Total:
	   Time complextity: O(Nlogk) + O(k)
	   Space complexity: O(k)
	*/
	return answer;
}

void showOutput(const vector<int> &answer) {
	for (const auto &data : answer)
		cout << data << endl;
}

int main(int argc, char *argv[]) {
	string path;
	int XLargest = 0;
    if (argc == 3) {
        path = argv[1];
        istringstream iss(argv[2]);
        iss >> XLargest;
    }
    else {
    	cout << "Enter input data path: ";
		cin >> path;
		cout << "Enter number of largest value (X-largest): ";
		cin >> XLargest;	
    }

	auto answer = findSubArrayLargest(path, XLargest);
	cout << "Data output:" << endl;
	showOutput(answer);

	return 0;
}