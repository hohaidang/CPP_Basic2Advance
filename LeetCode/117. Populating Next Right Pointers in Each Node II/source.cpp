/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    Node *prev, *leftmost;
public:
    void processChild(Node *childNode) {
        if(childNode) {
            if(!prev) {
                leftmost = childNode;
            }
            else {
                prev->next = childNode;
            }
            prev = childNode;
        }
    }
    
    Node* connect(Node* root) {
        if(!root) {
            return root;
        }
        Node* cur = root;
        leftmost = root;
        while(leftmost != nullptr) {
            cur = leftmost;
            leftmost = nullptr; // for breaking loop when reach out last level
            prev = nullptr; // for start new level 
            while(cur) {
                this->processChild(cur->left);
                this->processChild(cur->right);
                cur = cur->next;
            }
        }
        return root;
    }
};