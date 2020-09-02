/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // case 4
        if(head == nullptr) {
            Node* newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }
        
        Node *prev = head, *cur = head->next;
        bool isInsert = false;
        do {
            // case 1
            if(insertVal >= prev->val && insertVal <= cur->val) {
                isInsert = true;
            }
            
            // case 2
            if(prev->val > cur->val) {
                if(insertVal >= prev->val || insertVal <= cur->val) {
                    isInsert = true;
                }
            }
            
            if(isInsert) {
                Node *newNode = new Node(insertVal);
                prev->next = newNode;
                newNode->next = cur;
                return head;
            }
            cur = cur->next;
            prev = prev->next;
        }while(prev != head);
        
        // case 3, cyclic list 3->3->3
        Node *newNode = new Node(insertVal);
        prev->next = newNode;
        newNode->next = cur;
        return head;
    }
};