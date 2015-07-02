/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(root == NULL) return;
		TreeLinkNode* ptr1 = root, ptr2 = root;
		while(ptr1->left!= NULL){
			while(ptr2 != NULL){
				ptr2->left->next = ptr2->right;
				ptr2->right->next = ptr2->next == NULL? NULL : ptr2->next->left;
				ptr2 = ptr2->next;
			}
			ptr1 = ptr2 = ptr1->left;
		}
	}
};