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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        std::queue<TreeNode *> m_queue;
        std::vector<std::vector<int>> answer;
        m_queue.push(root);
        while(!m_queue.empty()) {
            size_t size = m_queue.size();
            for(int i = 0; i < size; ++i) {
                TreeNode *temp = m_queue.front();
                if(i == 0) {
                    answer.push_back({temp->val});
                } else {
                    answer[answer.size() - 1].push_back(temp->val);
                }
                if(temp->left) {
                    m_queue.push(temp->left);
                }
                if(temp->right) {
                    m_queue.push(temp->right);
                }
                m_queue.pop();
            }
            
        }
        return answer;
    }

};