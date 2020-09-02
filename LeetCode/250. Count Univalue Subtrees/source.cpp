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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        if(!root) {
            return 0;
        }
        auto data = BFS(root, count);
        return count;
    }
    
    bool BFS(TreeNode *root, int &count) {
        if(!root->left && !root->right) {
            ++count;
            return true;
        }
        bool isUnique = true;
        if(root->left) {
            isUnique = isUnique & BFS(root->left, count) & (root->left->val == root->val);
        }
        if(root->right) {
            isUnique = isUnique & BFS(root->right, count) & (root->right->val == root->val);
        }
        if(!isUnique) {
            return false;
        }
        ++count;
        return true;
    }
};