#include <iostream>
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
		if(pHead == nullptr) {
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

int main() {
	//,"get","addAtHead","addAtIndex","addAtHead"]
	//,[4],[4],[5,0],[6]]
	MyLinkedList list = MyLinkedList();
	list.addAtHead(7);
	list.addAtHead(2);
	list.addAtHead(1);
	showHeadTail(&list);
	list.addAtIndex(3, 0);
	showHeadTail(&list);
	list.deleteAtIndex(2);
	showHeadTail(&list);
	list.addAtHead(6);
	list.addAtTail(4);
	list.get(4);
	list.get(4);
	list.addAtHead(4);
	list.addAtIndex(5, 0);
	list.addAtHead(6);
	SingleListNode *ptr = list.pHead;
	while (ptr != nullptr) {
		cout << ptr->val << " " << endl;
		ptr = ptr->next;
	}
	cout << "get = " << list.get(3);
	return 0;
}