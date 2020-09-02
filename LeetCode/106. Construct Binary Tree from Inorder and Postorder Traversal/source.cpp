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
    // THam khao dap an
private:    
    int post_idx;
    vector<int> postorder, inorder;
    unordered_map<int, int> hashMap; // <key, val>, key = nums in inorder array, val = indx related
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->post_idx = postorder.size() - 1;
        this->inorder = inorder;
        this->postorder = postorder;
        
        // Create hashMap
        for(int i = 0; i < inorder.size(); ++i) {
            hashMap[inorder[i]] = i;
        }
        // inorder array dung de xac dinh left, right, day la dieu kien de ket thuc recursion (add null vao node)
        
        return helper(0, postorder.size() - 1);
    }

    TreeNode* helper(int left, int right) {
        if(left > right) {
            return nullptr;
        }
        
        int val = postorder[post_idx--];
        TreeNode *newNode = new TreeNode(val);
        int index = hashMap[val];
        newNode->right = helper(index + 1, right);
        newNode->left = helper(left, index - 1);
        return newNode;
    }
};