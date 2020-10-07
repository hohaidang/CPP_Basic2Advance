/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// Bottom up
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int cur = 0;
        for(auto &node : root->children) {
            cur = max(cur, maxDepth(node));
        }
        return 1 + cur;
    }
};

class Solution {
public:
	// Recursion top-down
    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }
        int depth = 1;
        compute_depth(root, depth);
        return max_depth_;
    }
    
    void compute_depth(Node *root, int depth) {
        max_depth_ = max(depth, max_depth_);
        for(auto &child : root->children) {
            compute_depth(child, depth + 1);
        }
    }
    
private: 
    int max_depth_ = 0;
};

// Queue iterator
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }
        std::queue<Node *> m_queue;
        int depth = 0;
        m_queue.push(root);
        while(!m_queue.empty()) {
            size_t size = m_queue.size();
            for(size_t i = 0; i < size; ++i) {
                Node *temp = m_queue.front();
                for(auto &child : temp->children) {
                    m_queue.push(child);
                }
                m_queue.pop();
            }
            depth += 1;
        }
        return depth;
    }
};