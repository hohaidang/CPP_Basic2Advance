#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class Solution {
public:
	void pre_order(TreeNode *root, vector<int> &answer) {
		if (root == nullptr)
			return;
		answer.push_back(root->val);
		pre_order(root->left, answer);
		pre_order(root->right, answer);
	}

	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> answer;
		if (root == nullptr)
			return answer;
		pre_order(root, answer);
		return answer;
	}

	void inorderTraversal(TreeNode *root, vector<int> &answer) {
		if (root == nullptr)
			return;
		inorderTraversal(root->left, answer);
		answer.push_back(root->val);
		inorderTraversal(root->right, answer);
	}

	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> answer;
		if (root == nullptr) 
			return answer;
		inorderTraversal(root, answer);
		return answer;
	}

	void postorderTraversal(TreeNode *root, vector<int> &answer)
	{
		if (root == nullptr)
			return;
		postorderTraversal(root->left, answer);
		postorderTraversal(root->right, answer);
		answer.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> answer; 
		if (root == nullptr)
			return answer;
		postorderTraversal(root, answer);
		return answer;
	}

	vector<int> preorderIterate(TreeNode *root) {
		vector<int> answer;
		stack<TreeNode*> s;
		if (root != nullptr) {
			s.push(root);
		}
		while (!s.empty()) {
			root = s.top();
			s.pop();
			answer.push_back(root->val);
			if(root->right != nullptr) {
				s.push(root->right);
			}
			if (root->left != nullptr) {
				s.push(root->left);
			}
		}
		return answer;
	}

	vector<int> inorderIterate(TreeNode *root) {
		vector<int> answer;
		stack<TreeNode *> s;
		TreeNode *cur = root;
		while ((!s.empty()) || cur != nullptr) {
			while (cur != nullptr) {
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			answer.push_back(cur->val);
			cur = cur->right;
		}
		return answer;
	}

	vector<int> postorderIterate(TreeNode *root) {
		vector<int> answer;
		stack<TreeNode *> s;
		if (root != nullptr)
			s.push(root);
		TreeNode *cur = root;
		while (!s.empty() || cur != nullptr) {
			while (cur != nullptr) {
				if (cur->right != nullptr) 
					s.push(cur->right);
				if (cur->left != nullptr)
				{
					s.push(cur->left);
					cur = cur->left;
					continue;
				}
				cur = cur->right;
			}
			cur = s.top();
			s.pop();
			answer.push_back(cur->val);
			cur = cur->right;
		}
		return answer;
	}
};


int temp2()
{

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(5);
	root->left->right->right = new TreeNode(6);
	root->right = new TreeNode(7);
	root->right->right = new TreeNode(8);
	root->right->right->left = new TreeNode(9);

	Solution sol = Solution();
	auto show = [](vector<int> &answer) {
		for_each(answer.begin(), answer.end(), [](auto &data){
			cout << data << "  ";
		});
		cout << "\n";
	};
	auto answer1 = sol.preorderTraversal(root);
	cout << "Preorder result: ";
	show(answer1);

	auto answer2 = sol.inorderTraversal(root);
	cout << "Inorder result: ";
	show(answer2);

	auto answer3 = sol.postorderTraversal(root);
	cout << "Postorder result:";
	show(answer3);

	auto answer4 = sol.preorderIterate(root);
	cout << "Stack Iterate Pre Order result:";
	show(answer4);

	auto answer5 = sol.inorderIterate(root);
	cout << "Stack Iterate In Order result: ";
	show(answer5);

	auto answer6 = sol.postorderIterate(root);
	cout << "Stack Iterate Post Order reulst:";
	show(answer6);

	return 0;
}
