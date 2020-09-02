class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		else if (p == nullptr || q == nullptr) return false;
		else if (p->val != q->val) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

// Queue, BFS
bool isSameTree(TreeNode* p, TreeNode* q) {
	queue<pair<TreeNode*, TreeNode*>> myQueue;
	myQueue.push(make_pair(p, q));
	while (!myQueue.empty()) {
		p = myQueue.front().first;
		q = myQueue.front().second;

		if ((p && q) && p->val != q->val)
			break; // both null
		if (p && !q || !p && q)
			break; // each not null
		myQueue.pop();
		if (p && q) {
			myQueue.push(make_pair(p->left, q->left));
			myQueue.push(make_pair(p->right, q->right));
		}
	}
	return myQueue.empty();
}

// Stack, pre-order, DFS
bool isSameTree(TreeNode* p, TreeNode* q) {
	stack<pair<TreeNode*, TreeNode*>> myStack;
	myStack.push(make_pair(p, q));
	while (!myStack.empty()) {
		p = myStack.top().first;
		q = myStack.top().second;

		if ((p && !q) || (!p && q))
			break;
		if ((p && q) && p->val != q->val)
			break;
		myStack.pop();
		if (p && q) {
			myStack.push(make_pair(p->left, q->left));
			myStack.push(make_pair(p->right, q->right));
		}
	}
	return myStack.empty();
}