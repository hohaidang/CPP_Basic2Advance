#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;
	Node(int data) : val(data), next(nullptr), random(nullptr) {};
};

void showList(Node *head) {
	Node *ptr = head;
	while (ptr != nullptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
}

class Solution {
public:
	Node* copyRandomList(Node *head) {
		if (head == nullptr) {
			return nullptr;
		}

		// Step 1: duplicate linked list
		Node *cur = head;
		while (cur != nullptr) {
			Node *newNode = new Node(cur->val);
			Node *next = cur->next;
			cur->next = newNode;
			newNode->next = next;
			cur = next;
		}

		// Step 2: handling random pointer
		// A -> A' -> B -> B' -> C -> C' -> nullptr
		cur = head;
		Node *clonePtr = head->next;
		while (cur != nullptr) {
			cur->next->random = (cur->random != nullptr) ? cur->random->next : nullptr;
			cur = cur->next->next;
		}

		// Step 3: cut off clone list
		// A' -> B' -> C' -> nullptr
		cur = head;
		clonePtr = head->next;
		Node *answer = clonePtr;
		while (clonePtr->next != nullptr) {
			cur->next = clonePtr->next;
			cur = cur->next;
			clonePtr->next = cur->next;
			clonePtr = clonePtr->next;
		}
		cur->next = nullptr;
		return answer;
	}
};

int main() {
	Node *head = new Node(7);
	head->random = nullptr;
	head->next = new Node(13);
	head->next->next = new Node(11);
	head->next->next->next = new Node(10);
	head->next->next->next->next = new Node(1);

	head->next->random = head;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head;

	Solution sol = Solution();
	auto *node = sol.copyRandomList(head);
	showList(head);
	return 0;
}