#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	using Mymap = unordered_map<string, double>;
	Mymap umap;

	// inserting values by using [] operator
	umap["PI"] = 3.14;
	umap["root2"] = 1.414;
	umap["root3"] = 1.732;
	umap["log10"] = 2.302;
	umap["loge"] = 1.0;

	// inserting value by insert function
	umap.insert(make_pair("e", 2.718));
	string key = "PI";

	// Find key in map
	if (umap.find(key) == umap.end())
		cout << key << " not found\n\n";
	else
		cout << "Found " << key << "\n\n";

	Mymap::iterator itr;
	cout << "\nAll Elements: \n";
	for (itr = umap.begin(); itr != umap.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}


	return 0;
}