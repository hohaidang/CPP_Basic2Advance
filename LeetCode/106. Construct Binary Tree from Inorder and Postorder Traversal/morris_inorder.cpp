/// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
/// Author : liuyubobobo
/// Time   : 2018-05-31

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void morris_inorder(TreeNode *root) {
	TreeNode *current = root;
	while (current != nullptr) {
		if (current->left == nullptr) {
			std::cout << current->val << " ";
			current = current->right;
		}
		else {
			TreeNode* predecessor = current->left;
			while (predecessor->right != current && predecessor->right != nullptr) {
				predecessor = predecessor->right;
			}

			if (predecessor->right == nullptr) {
				predecessor->right = current;
				current = current->left;
			}
			else {
				predecessor->right = nullptr;
				std::cout << current->val << " ";
				current = current->right;
			}
		}
	}
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->left->right->right = new TreeNode(8);
	root->left->left = new TreeNode(-2);
	root->left->left->right = new TreeNode(2);
	root->left->left->right->left = new TreeNode(-1);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(30);

	morris_inorder(root);
	return 0;
}