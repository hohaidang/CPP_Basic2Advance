#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <sstream> 
#include <string>
#include <iomanip>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distribution(1000000000, 2000000000);
	ofstream myFile;
	myFile.open("LargeData.txt");
	
	for (int i = 0; i < 10000000; ++i) {
		int ids = distribution(gen);
		myFile << ids << " " << rand() << endl;
	}
	return 0;
}