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
    // Recursion
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root, root);
    }
    
    bool checkSymmetric(TreeNode *t1, TreeNode *t2) {
        if(!t1 && !t2)
            return true;
        if((t1 && !t2) || (!t1 && t2))
            return false;
        return (t1->val == t2->val) 
            & checkSymmetric(t1->right, t2->left) 
            & checkSymmetric(t1->left, t2->right);
    }
	
	// Iterator
	bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()) {
            TreeNode *n1 = q.front();
            q.pop();
            TreeNode *n2 = q.front();
            q.pop();
            if((n1 && !n2) || (!n1 && n2)) 
                return false;
            if((n1 && n2) && n1->val != n2->val) 
                return false;
            if(!n1 && !n2) 
                continue;
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);    
        }
        return true;
    }
};