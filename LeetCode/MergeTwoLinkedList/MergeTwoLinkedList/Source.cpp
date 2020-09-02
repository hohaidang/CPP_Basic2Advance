/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;
		if (l1->val < l2->val) 
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}

	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;
		ListNode *temp = new ListNode(-1);
		auto *preTemp = temp;
		while ((l1 != nullptr) and (l2 != nullptr)) 
		{
			if (l1->val < l2->val)
			{
				temp->next = l1;
				l1 = l1->next;
			}
			else
			{
				temp->next = l2;
				l2 = l2->next;
			}
			temp = temp->next;
		}
		temp->next = (l1 == nullptr) ? l2 : l1;
		return preTemp->next;
	}
};

int main()
{
	ListNode *a = new ListNode(1);
	auto preA = a;
	a->next = new ListNode(2);
	a = a->next;
	a->next = new ListNode(4);

	ListNode *b = new ListNode(1);
	auto preB = b;
	b->next = new ListNode(3);
	b = b->next;
	b->next = new ListNode(4);
	Solution sol = Solution();
	auto c = sol.mergeTwoLists(preA, preB);
	//auto c = sol.mergeTwoLists2(preA, preB);
	return 0;
}

