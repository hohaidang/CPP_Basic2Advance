#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
	ListNode *pHead;
	ListNode *pTail;
	MyLinkedList(ListNode *node) : pHead(node), pTail(node) {}
	MyLinkedList() : pHead(nullptr), pTail(nullptr) {}
	int get(int index) {
		int i = 0;
		ListNode *ptr = pHead;
		while (ptr != nullptr) {
			if (i == index) {
				return ptr->val;
			}
			ptr = ptr->next;
			++i;
		}
		return -1;
	}

	void addAtHead(int val) {
		ListNode *node = new ListNode(val);
		if (pHead == nullptr) {
			pHead = node;
			pTail = node;
		}
		else {
			node->next = pHead;
			pHead = node;
		}
	}
	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */

	void addAtTail(int val) {
		ListNode *node = new ListNode(val);
		if (pHead == nullptr) {
			pHead = node;
			pTail = node;
		}
		else {
			pTail->next = node;
			pTail = node;
		}
	}

	void addAtIndex(int index, int val) {
		ListNode *node = new ListNode(val);
		if (index == 0) {
			addAtHead(val);
		}
		ListNode *ptr = pHead;
		int i = 0;
		while (ptr != nullptr) {
			++i;
			if (i == index) {
				ListNode *temp = ptr->next;
				ptr->next = node;
				node->next = temp;
				pTail = pTail->next;
				break;
			}
			ptr = ptr->next;
		}
	}

	void deleteAtIndex(int index) {
		if (index == 0) {
			ListNode *temp = pHead;
			pHead = pHead->next;
			temp->next = nullptr;
			delete temp;
		}
		int i = 0;
		ListNode *ptr = pHead;
		while (ptr != nullptr) {
			++i;
			if (i == index) {
				ListNode *temp1 = ptr;
				ListNode *temp2 = ptr->next->next;
				ListNode *temp3 = ptr->next;
				temp1->next = temp2;
				temp3->next = nullptr;
				delete temp3;
			}
			ptr = ptr->next;
		}
	}
};

void showList(ListNode *head) {
	while(head != nullptr) {
		cout << head->val << "->";
		head = head->next;
	}
	cout << "null" << endl;
}

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = head;
        ListNode *toBeDeleted = nullptr;
        while(cur != nullptr) {
            if(cur->val == val) {
                toBeDeleted = cur;
                prev->next = cur->next;
            }
            else {
                prev = cur;
            }
            cur = cur->next;
            if(toBeDeleted != nullptr) {
                delete toBeDeleted;
                toBeDeleted = nullptr;
            }
            
        }
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
	}
};

int main() {
	MyLinkedList list = MyLinkedList();
	list.addAtHead(1);
	list.addAtTail(2);
	list.addAtTail(6);
	list.addAtTail(3);
	list.addAtTail(4);
	list.addAtTail(5);
	list.addAtTail(6);
	showList(list.pHead);
	
	Solution sol = Solution();
	sol.removeElements(list.pHead, 6);
	return 0;
}