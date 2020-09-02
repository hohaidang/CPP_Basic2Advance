#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
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
		cout << "\nUnable to open file. Please check path again!" << endl;
		return answer;
	}
	auto cmp = [](const PAIR &a, const PAIR &b) {
		return a.second > b.second;
	};
	priority_queue<PAIR, vector<PAIR>, decltype(cmp)> PriorityQueue(cmp);

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