#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;
public:
	Node() = default;
	Node(int _val) : val(_val) {}
	Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

Node* BuildKaryTree(int A[], int n, int k, int h, int &ind) {
	if(n == 0)
		return nullptr;
	Node *node = new Node(A[ind]);

	// For adding k children to a node
	for(int i = 0; i < k; ++i) {
		if(ind < n - 1 && h > 1) {
			++ind;
			node->children.push_back(BuildKaryTree(A, n, k, h-1, ind));
		}
		else {
			node->children.push_back(nullptr);
		}
	}
	return node;
}

// Function to find the height of the tree
Node* BuildKaryTree(int *A, int n, int k, int ind) {
	int height = (int)ceil(log((double)n * (k-1) + 1) / log((double)k));
	return BuildKaryTree(A, n, k, height, ind);
}

// Function to print postorder traversal of the tree
void postord(Node *root, int k) {
	if(root == nullptr) return;
	for(int i = 0; i < k; ++i) {
		postord(root->children[i], k);
	}
	cout << root->val << "   ";
}


int temp() {
	int ind = 0;
	int k = 3, n = 10;
	int preorder[] = {1, 2, 5, 6, 7, 3, 8, 9, 10, 4};
	Node* root = BuildKaryTree(preorder, n, k, ind);
	cout << "Post order traversal of constructed full k-ary tree is: " << endl;
	postord(root, k);
	cout << endl;
	return 0;
}

