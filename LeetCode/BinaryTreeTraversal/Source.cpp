#include <iostream>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
	Node() : val(0), left(nullptr), right(nullptr) {};
	Node(int data) : val(data), left(nullptr), right(nullptr) {};
	Node(int data, Node *left, Node *right) : val(data), left(left), right(right) {};
};

int temp() {
	Node *root = new Node(1);
	/* following is the tree after above statement

	   1
	 /   \
	NULL  NULL
	*/
	root->left = new Node(2);
	root->right = new Node(3);
	/* 2 and 3 become left and right children of 1
		   1
		 /   \
		2      3
	 /    \    /  \
	NULL NULL NULL NULL
  */
	root->left->left = new Node(4);
	/* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/

	return 0;
}