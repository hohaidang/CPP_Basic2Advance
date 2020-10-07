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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::vector<int> answer;
        std::stack<TreeNode *> output, m_stack;
        TreeNode *cur = root;
        while (cur or !m_stack.empty()) {
            if (cur) {
                m_stack.push(cur);
                output.push(cur);
                cur = cur->right;
            }
            else {
                cur = m_stack.top();
                m_stack.pop();
                cur = cur->left;
            }
        }
        while (!output.empty()) {
            answer.push_back(output.top()->val);
            output.pop();
        }
        return answer;
    }
};