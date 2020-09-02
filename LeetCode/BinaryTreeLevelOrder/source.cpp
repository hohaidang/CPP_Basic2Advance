#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class Solution {
public:
	vector<vector <int>> levelOrder(TreeNode *root) {
		vector<vector <int>> answer;
		if(root == nullptr) 
			return answer;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			int size = q.size();
			vector<int> temp;
			for(int i = 0; i < size; ++i) {
				root = q.front();
				q.pop();
				temp.push_back(root->val);
				if(root->left != nullptr)
					q.push(root->left);
				if(root->right != nullptr)
					q.push(root->right);
			}
			answer.push_back(temp);
		}
		return answer;
	}
	
	vector<vector<int>> levelOrderRecur(TreeNode *root) {
		vector<vector<int>> answer;
		if(root == nullptr)
			return answer;
		int level = 0;
		helper(root, level, answer);
		return answer;
	}
	
	void helper(TreeNode *root, int level, vector<vector<int>> &answer) {
		if(level == answer.size())
			answer.push_back({root->val});
		else
			answer[level].push_back(root->val);
		if(root->left != nullptr) {
			helper(root->left, level + 1, answer);
		}
		if(root->right != nullptr) {
			helper(root->right, level + 1, answer);
		}
	}
};

int main(int argc, char *argv[]) {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution sol = Solution();
	auto answer = sol.levelOrderRecur(root);
	for(int i = 0; i < answer.size(); ++i) {
		for(int j = 0; j < answer[i].size(); ++j) {
			cout << answer[i][j] << "  " ;
		}
		cout << endl;
	} 
	return 0;
}