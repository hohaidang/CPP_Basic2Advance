/// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
/// Author : liuyubobobo
/// Time   : 2018-05-31

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	std::vector<Node *> children;
	Node() {}
	Node(int _val) { val = _val; }
	Node(int _val, std::vector<Node *> _children) {
		val = _val;
		children = _children;
	}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// same level right, next level left
class Codec {
public:
	TreeNode* encode(Node *root) {
		if (!root) {
			return nullptr;
		}
		auto node = new TreeNode(root->val);
		// recurse next level first
		if (!root->children.empty()) {
			node->left = encode(root->children[0]);
		}
		auto cur = node->left; 
		for (auto i = 1; i < root->children.size(); ++i) {
			cur->right = encode(root->children[1]);
			cur = cur->right;
		}
		return node;
	}

};

int main() {
	Node *n_tree = new Node(1);
	n_tree->children.push_back(new Node(2));
	n_tree->children.push_back(new Node(3));
	n_tree->children.push_back(new Node(4));

	n_tree->children[0]->children.push_back(new Node(5));
	n_tree->children[0]->children.push_back(new Node(6));
	n_tree->children[0]->children.push_back(new Node(7));

	n_tree->children[2]->children.push_back(new Node(8));
	n_tree->children[2]->children.push_back(new Node(9));
	n_tree->children[2]->children.push_back(new Node(10));

	Codec sol;
	auto binary_tree = sol.encode(n_tree);
	return 0; 
}