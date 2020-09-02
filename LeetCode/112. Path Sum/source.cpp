/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }
        stack<pair<TreeNode *, int>> s;
        s.push(make_pair(root, sum));
        while(!s.empty()) {
            TreeNode *node = s.top().first;            
            int complement = s.top().second - node->val;
            if(complement == 0 && !node->left && !node->right) {
                return true;
            }
            s.pop();
            if(node->right) {
                s.push(make_pair(node->right, complement));
            }
            if(node->left) {
                s.push(make_pair(node->left, complement));
            }

        }
        return false;
    }
	
	bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        sum -= root->val;
        if(!root->left && !root->right) {
            return (sum == 0);
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};