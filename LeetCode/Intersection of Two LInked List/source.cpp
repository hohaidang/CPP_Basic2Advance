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
	// ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
		/*using HashTable*/
		// unordered_map<ListNode*, int> ht;
		// int i = 0;
		// while(headA != nullptr) {
			// ht.insert(make_pair(headA, i));
			// headA = headA->next;
			// ++i;
		// }
		// while(headB != nullptr) {
			// auto find = ht.find(headB);
			// if(find != ht.end()) {
				// return find->first;
			// }
			// headB = headB->next;
		// }
		// return nullptr;
	// }
	
	// ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
		// /*Using brute force*/
		// for(ListNode *ptr1 = headA; ptr1 != nullptr; ptr1 = ptr1->next) {
			// for(ListNode *ptr2 = headB; ptr2 != nullptr; ptr2 = ptr2->next) {
				// if(ptr1 == ptr2) {
					// return ptr1;
				// }
			// }
		// }
		// return nullptr;
	// }
	
	ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
		/* using 2 Pointer */
		ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		if (ptr1 == nullptr || ptr2 == nullptr) {
			return nullptr;
		}
		while (ptr1 != ptr2) {
			ptr1 = (ptr1 == nullptr) ? headB : ptr1->next;
			ptr2 = (ptr2 == nullptr) ? headA : ptr2->next;
		}
		return ptr1;
	}
};

int main() {
	MyLinkedList list1 = MyLinkedList();
	MyLinkedList list2 = MyLinkedList();
	list1.addAtHead(5);
	list1.addAtHead(4);
	list1.addAtHead(8);
	list1.addAtHead(1);
	list1.addAtHead(4);
	list2.addAtHead(1);
	list2.addAtHead(0);
	list2.addAtHead(5);
	list2.pTail->next = list1.pHead->next->next;
	


	Solution sol = Solution();
	ListNode* answer = sol.getIntersectionNode(list1.pHead, list2.pHead);
	if(answer == nullptr) {
		cout << "null";
	}
	else {
		cout << "Reference of the node with value = " << answer->val;
	}
	
	return 0;
}