#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;
	Node() = default;
	Node(int _val) : val(_val) {}
	Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
public:
	vector<int> preorder(Node *root) {
		vector<int> answer;
        if(root == nullptr)
            return answer;
		preorder(root, answer);
		return answer;
	}

	void preorder(Node* root, vector<int> &answer) {
		answer.push_back(root->val);
		for(int i = 0; i < root->children.size(); ++i) {
			preorder(root->children[i], answer);
		}
	}
	
	vector<int> preorderIteration(Node* root) {
        vector<int> answer;
        if(root == nullptr)
            return answer;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            root = s.top();
            s.pop();
            answer.push_back(root->val);
            for(auto i = root->children.rbegin(); i != root->children.rend(); ++i) {
                s.push(*i);
            }
        }
        return answer;
    }
};

void builtTree(int *arr, int n, int &idx, Node *root) {
	for (; idx < n; ++idx) {
		if(arr[idx] == NULL) {
			for(int j = 0; j < root->children.size(); ++j) {
				builtTree(arr, n, ++idx, root->children[j]);
			}
			break;
		}
		root->children.push_back(new Node(arr[idx]));
	}
}

Node* builtTree(int *arr, int n) {
	Node *root = new Node(arr[0]);
	int idx = 2;
	builtTree(arr, n, idx, root);
	return root;
}


int main() {
	 Node *root = new Node(1);
	 // TODO: make this one automactically.
	 root->children.push_back(new Node(3));
	 root->children.push_back(new Node(2));
	 root->children.push_back(new Node(4));
	 root->children[0]->children.push_back(new Node(5));
	 root->children[0]->children.push_back(new Node(6));

//	auto root = builtTree(arr, 8);
	Solution sol = Solution();
	auto out = sol.preorder(root);
	for_each(out.begin(), out.end(), [](const int &data) {
		cout << data << "  ";
	});
	cout << endl;
	return 0;
}
