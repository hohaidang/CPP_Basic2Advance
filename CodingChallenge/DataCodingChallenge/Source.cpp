#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
using namespace std;
using PAIR = pair<int, int>;

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
	auto cmp = [](const PAIR &a, const PAIR &b) {
		return a.second > b.second;
	};
	priority_queue<PAIR, vector<PAIR>, decltype(cmp)> PriorityQueue(cmp);

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