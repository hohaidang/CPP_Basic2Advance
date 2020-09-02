#include <iostream>
#include <unordered_map>
using namespace std;

struct SingleListNode {
	int val;
	SingleListNode *next;
	SingleListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
public:
	SingleListNode *pHead;
	SingleListNode *pTail;
	MyLinkedList(SingleListNode *node) : pHead(node), pTail(node) {}
	MyLinkedList() : pHead(nullptr), pTail(nullptr) {}
	int get(int index) {
		int i = 0;
		SingleListNode *ptr = pHead;
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
		SingleListNode *node = new SingleListNode(val);
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
		SingleListNode *node = new SingleListNode(val);
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
		SingleListNode *node = new SingleListNode(val);
		if (index == 0) {
			addAtHead(val);
		}
		SingleListNode *ptr = pHead;
		int i = 0;
		while (ptr != nullptr) {
			++i;
			if (i == index) {
				SingleListNode *temp = ptr->next;
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
			SingleListNode *temp = pHead;
			pHead = pHead->next;
			temp->next = nullptr;
			delete temp;
		}
		int i = 0;
		SingleListNode *ptr = pHead;
		while (ptr != nullptr) {
			++i;
			if (i == index) {
				SingleListNode *temp1 = ptr;
				SingleListNode *temp2 = ptr->next->next;
				SingleListNode *temp3 = ptr->next;
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
	SingleListNode *checkCycle(SingleListNode *head) {
		SingleListNode *ptr1 = head;
		SingleListNode *ptr2 = head;
		while (ptr2 != nullptr && ptr2->next != nullptr) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next->next;
			if (ptr1 == ptr2) {
				return ptr1;
			}
		}
		return nullptr;
	}
	SingleListNode *detectCycle(SingleListNode *head) {
		auto *temp = checkCycle(head);
		if (temp == nullptr) {
			return nullptr;
		}

		auto *ptr1 = head;
		while (ptr1 != temp) {
			ptr1 = ptr1->next;
			temp = temp->next;
		}
		return temp;
	}
};

int main() {
	//,"get","addAtHead","addAtIndex","addAtHead"]
	//,[4],[4],[5,0],[6]]
	MyLinkedList list = MyLinkedList();
	list.addAtHead(-4);
	list.addAtHead(0);
	list.addAtHead(2);
	list.addAtHead(3);
	//list.pTail->next = list.pHead->next;

	// SingleListNode *ptr = list.pHead;
	// while (ptr != nullptr) {
		// cout << ptr->val << " " << endl;
		// ptr = ptr->next;
	// }

	Solution sol = Solution();
	auto answer = sol.detectCycle(list.pHead);
	if (answer != nullptr) {
		cout << "Index start of cycle = " << sol.detectCycle(list.pHead)->val << endl;
	}
	else {
		cout << "No start index" << endl;
	}
	
	return 0;
}