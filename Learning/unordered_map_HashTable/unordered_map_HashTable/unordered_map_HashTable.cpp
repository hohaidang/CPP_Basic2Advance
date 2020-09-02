// unordered_map_HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int temp()
{
	using Mymap = unordered_map<string, int>;
	Mymap umap;

	// insert values using [] operator
	umap["Geeks for Geeks"] = 10;
	umap["Practice"] = 20;
	umap["Contribute"] = 30;

	// Traversing an unordered map
	/*for (auto x : umap)
		cout << umap_Iter->first << " " << umap_Iter->second << endl;*/
	for (Mymap::const_iterator it = umap.begin();
		it != umap.end(); ++it)
		cout << " [" << it->first << ", " << it->second << "]";
	cout << endl;
	return 0;
}
