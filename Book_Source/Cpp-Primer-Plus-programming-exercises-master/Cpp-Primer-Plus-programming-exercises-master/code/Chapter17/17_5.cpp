// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iterator>

using namespace std;

vector<string> mat;
vector<string> pat;
vector<string> both;

int main() {
	ifstream fin;
	string temp;
	fin.open("17_5_mat.dat");
	while (getline(fin, temp)) mat.push_back(temp);
	sort(mat.begin(), mat.end());
	cout << "Mat's friends:\n";
	for (string s : mat) cout << "    " << s << endl;
	cout << endl;
	fin.close();
	fin.open("17_5_pat.dat");
	while (getline(fin, temp)) pat.push_back(temp);
	sort(pat.begin(), pat.end());
	cout << "Pat's friends:\n";
	for (string s : pat) cout << "    " << s << endl;
	cout << endl;
	copy(mat.begin(), mat.end(), insert_iterator<vector<string> >(both, both.begin()));
	copy(pat.begin(), pat.end(), insert_iterator<vector<string> >(both, both.end()));
	sort(both.begin(), both.end());
	auto uniend = unique(both.begin(), both.end());

	ofstream fout;
	fout.open("17_5_matnpat.dat");

	for_each(both.begin(),uniend,[&fout](string s){fout << s << endl;});
	cout << "Union of their friends:\n";
	for_each(both.begin(), uniend, [](string s) {cout << " " << s << endl; });

	return 0;
}

