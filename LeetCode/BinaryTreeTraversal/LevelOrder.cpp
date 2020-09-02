#include <iostream>
#include <vector>
#include <queue>
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

class Solution {

public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> answer;
		if (root == nullptr)
			return answer;
		int count = 0;
		levelOrder(root, answer, count);
		return answer;
	}

	void levelOrder(TreeNode* root, vector<vector<int>> &answer, int count) {
		if (count == answer.size()) {
			answer.push_back({ root->val });
		}
		else {
			answer[count].push_back(root->val);
		}
		if (root->left != nullptr) {
			levelOrder(root->left, answer, count + 1);
		}
		if (root->right != nullptr) {
			levelOrder(root->right, answer, count + 1);
		}
	}

	vector<vector<int>> levelOrderIterator(TreeNode *root) {
		vector<vector<int>> answer;
		if (root == nullptr)
			return answer;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			vector<int> temp;
			for (int i = 0; i < size; ++i) {
				root = q.front();
				temp.push_back(root->val);
				q.pop();

				if (root->left != nullptr) {
					q.push(root->left);
				}
				if (root->right != nullptr) {
					q.push(root->right);
				}
			}
			answer.push_back(temp);
		}
		return answer;
	}
};

/*vector< vector <int>> v;
if (root == NULL)
return v;
queue< TreeNode * >q;
q.push(root);
while (!q.empty())
{
	vector< int > an;
	int t = q.size();
	for (int i = 0; i < t; i++)
	{
		TreeNode *p = q.front();
		q.pop();
		an.push_back(p->val);
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	v.push_back(an);
}
return v;*/

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution sol = Solution();
	auto data = sol.levelOrder(root);
	cout << "Result Recursion: " << endl;
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data[i].size(); ++j) {
			cout << data[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Result Iterator: " << endl;
	auto data1 = sol.levelOrderIterator(root);
	for (int i = 0; i < data1.size(); ++i) {
		for (int j = 0; j < data1[i].size(); ++j) {
			cout << data1[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}