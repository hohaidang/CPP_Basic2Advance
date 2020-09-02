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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        computeMaxDepth(root, 1, maxDepth);
        return maxDepth;
    }
    
    // pre-order, top-down method
    void computeMaxDepth(TreeNode *root, int deep, int &maxDepth) {
        if(!root) {
            return;
        }
        maxDepth = max(maxDepth, deep);
        computeMaxDepth(root->left, deep + 1, maxDepth);
        computeMaxDepth(root->right, deep + 1, maxDepth);
        
    }
    
    // post-order, bottom-up method
    int computeMaxDepth(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int depth_left = computeMaxDepth(root->left);
        int depth_right = computeMaxDepth(root->right);
        return max(depth_left, depth_right) + 1;
    }
	
	int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        // <depth, Node>
        stack<pair<int, TreeNode*>> s;
        int answer = 0;
        s.push(make_pair(1, root));
        while(!s.empty()) {
            int depth = s.top().first;
            TreeNode* node = s.top().second;
            answer = max(depth, answer);
            s.pop();
            if(node->left) {
                s.push(make_pair(depth + 1, node->left));
            }
            if(node->right) {
                s.push(make_pair(depth + 1, node->right));
            }
        }
        return answer;
    }
};