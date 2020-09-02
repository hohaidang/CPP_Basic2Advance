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

void showHeadTail(MyLinkedList *list) {
	cout << "Head = " << list->pHead->val << ", Tail = " << list->pTail->val << endl;
}

class Solution {
public:
	// int findReversePos(ListNode *head, int n) {
		// int i = 0;
		// int s = 0;
		// for(ListNode *ptr1 = head; ptr1 != nullptr; ptr1 = ptr1->next) {
			// ++i;
			// s = i - n;
		// }
		// return s;
	// }
	// ListNode* removeNthFromEnd(ListNode *head, int n) {
		// int rpos = findReversePos(head, n);
		// int i = 0;
		// ListNode *temp = nullptr;
		// cout << "rpos = " << rpos << endl;
		// for(auto ptr = head; ptr != nullptr; ptr = ptr->next) {
			// if(i == rpos) {
				// if(temp == nullptr) {
					// // head;
					// head = head->next;
					// ptr->next = nullptr;
				// }
				// else if(ptr->next == nullptr) {
					// // tail
					// temp->next = nullptr;
				// }
				// else {
					// // middle
					// temp->next = ptr->next;
				// }
				// break;
			// }
			// temp = ptr;
			// ++i;
		// }
		// return head;
	// }
	
	// ListNode* removeNthFromEnd(ListNode *head, int n) {
		// int rpos = 0;
		// int i = 0;
		// ListNode* ptr_mod = head;
		// ListNode* pre_pos = nullptr;
		// for(ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
			// rpos = i - n + 1;
			// if(rpos > 0) {
				// ptr_mod = ptr_mod->next;
			// }
			// if(ptr->next == nullptr) {
				// // end list
				// if(ptr_mod == head) {
					// // remove head
					// head = head->next;
					// ptr_mod->next = nullptr;
				// }
				// else if(ptr_mod->next == nullptr) {
					// // remove tail
					// pre_pos->next = nullptr;
				// }
				// else {
					// // remove middle
					// pre_pos->next = ptr_mod->next;
					// ptr_mod->next = nullptr;
				// }
			// }
			// pre_pos = ptr_mod;
			// ++i;
		// }
		// return head;
	// }
};

int main() {
	MyLinkedList list = MyLinkedList();
	list.addAtHead(5);
	list.addAtHead(4);
	list.addAtHead(3);
	list.addAtHead(2);
	list.addAtHead(1);
	
	Solution sol = Solution();
	cout << "List before remove: ";
	for(ListNode *ptr = list.pHead; ptr != nullptr; ptr = ptr->next) {
		cout << ptr->val << " ";
	}
	
	auto *ptr = sol.removeNthFromEnd(list.pHead, 1);
	cout << "\nList after remove: ";
	for(;ptr != nullptr; ptr = ptr->next) {
		cout << ptr->val << " ";
	}
	return 0;
}