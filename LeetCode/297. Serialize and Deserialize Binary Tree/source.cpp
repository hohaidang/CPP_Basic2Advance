/*
 * main.cpp
 *
 *  Created on: Jun 15, 2020
 *      Author: prnsoft
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
		ostringstream out;
		serialize(root, out);
		return out.str();
	}

    TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserialize(in);
    }

private:
	void serialize(TreeNode *root, ostringstream &out) {
		if(root) {
			out << root->val << " ";
			serialize(root->left, out);
			serialize(root->right, out);
		}
		else {
			out << "# ";
		}
	} 
	
	TreeNode* deserialize(istringstream &in) {
		string val;
		in >> val;
		if(val == "#") {
			return nullptr;
		}
		TreeNode *curNode = new TreeNode(stoi(val, nullptr, 10));
		curNode->left = deserialize(in);
		curNode->right = deserialize(in);
		return curNode;
	}
};

void showTree(TreeNode *tree) {
	if(!tree) {
		cout << "null, ";
		return;
	}
	cout << tree->val << ", ";
	showTree(tree->left);
	showTree(tree->right);
}

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	Codec sol = Codec();
	auto data = sol.serialize(root);
	cout << "data serialize = " << data << endl;
	showTree(sol.deserialize(data));
	return 0;
}
