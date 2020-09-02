// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void ShowStr(const string& str) {
	cout << str << endl;
}

class Store {
private:
	ofstream& ofs;
public:
	Store(ofstream& fout) :ofs(fout) {}
	void operator()(const string& str)const;
};

void Store::operator()(const string& str)const {
	int len = str.length();
	ofs.write((char*)&len, sizeof(int));
	ofs.write(str.data(), len);
}

void GetStrs(ifstream& ifs, vector<string>& vs) {
	int len;
	char* str;
	while (ifs.read((char*)&len, sizeof(int))) {
		str = new char[len + 1];
		ifs.read(str, len);
		str[len] = '\0';
		vs.push_back(string(str));
		delete str;
	}
}

int main() {
	vector<string> vostr;
	string temp;

	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0') vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("17_7_string.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	vector<string> vistr;
	ifstream fin("17_7_string.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open()) {
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}
