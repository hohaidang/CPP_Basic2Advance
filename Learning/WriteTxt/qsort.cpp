#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <cstdlib>
using namespace std::chrono; 
using namespace std;
using PAIR = pair<int, int>;


void showOutput(const vector<int> &answer) {
	for (const auto &data : answer)
		cout << data << endl;
}

int main(int argc, char *argv[]) {
	string path = "LargeData.txt";
	int XLargest = 5;

	vector<int> answer;
	vector<PAIR> dataInput;
	ifstream inFile;
	inFile.open(path);
	if (!inFile) {
		cout << "\nUnable to open file. Please check path again!" << endl;
		return 0;
	}
	int ids = 0, val = 0;

	auto start = high_resolution_clock::now(); 
	while (inFile >> ids >> val) {
		dataInput.push_back(PAIR(ids,val));
	}

	
	sort(dataInput.begin(), dataInput.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b)
	{
	    return a.second < b.second;
	}
	);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start); 
	cout << "Run-time 10 million data input and " << XLargest << " data output: " << duration.count() << " microseconds" << endl;
	cout << "Data output:" << endl;
	for(int i = dataInput.size() - XLargest; i < dataInput.size(); ++i) {
		cout << dataInput[i].first << "   " << dataInput[i].second << endl; 
	}

	return 0;
}