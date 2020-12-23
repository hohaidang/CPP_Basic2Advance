#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next, *prev;
	ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
private:
	ListNode *head;
public:
	MyLinkedList() {
		head = nullptr;
	}
	
	/** Helper function to return the index-th node in the linked list. */
	ListNode* getNode(int index) {
		ListNode *ptr = head;
		for(int i = 0; i < index && ptr != nullptr; ++i) {
			ptr = ptr->next;
		}
		return ptr;
	}
	
	/** Helper function to return the last node in the linked list. */
	ListNode* getTail() {
		ListNode *ptr = head;
		while(ptr != nullptr && ptr->next != nullptr) {
			ptr = ptr->next;
		}
		return ptr;
	}
	
	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode *newNode = new ListNode(val);
		newNode->next = head;
		if(head != nullptr) {
			head->prev = newNode;
		}
		head = newNode;
	}
	
	void addAtTail(int val) {
		if(head == nullptr) {
			addAtHead(val);
			return;
		}
		ListNode *newNode = new ListNode(val);
		ListNode *prev = getTail();
		prev->next = newNode;
		newNode->prev = prev;
	}
	
	void addAtIndex(int index, int val) {
		if(index == 0) {
			addAtHead(val);
			return;
		}
		ListNode *prev = getNode(index - 1);
		if(prev == nullptr) {
			return;
		}
		ListNode *cur = new ListNode(val);
		ListNode *next = prev->next;
		cur->prev = prev;
		cur->next = next;
		prev->next = cur;
		if(next != nullptr) {
			next->prev = cur;
		}
	}
	
	void deleteAtIndex(int index) {
		ListNode *cur = getNode(index);
		if(cur == nullptr) {
			return;
		}
		ListNode *prev = cur->prev;
		ListNode *next = cur->next;
		if(prev != nullptr) {
			prev->next = next;
		}
		else {
			head = next;
		}
		if(next) {
			next->prev = prev;
		}
	}
};


int main () {
	return 0;
}