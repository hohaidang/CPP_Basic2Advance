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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) {
            return {};
        }
        std::stack<TreeNode *> m_stack;
        std::vector<int> answer;
        m_stack.push(root);
        while(!m_stack.empty()) {
            root = m_stack.top();
            m_stack.pop();
            answer.push_back(root->val);
            if(root->right) {
                m_stack.push(root->right);
            }
            if(root->left) {
                m_stack.push(root->left);
            }
            
        }
        return answer;
    }

};