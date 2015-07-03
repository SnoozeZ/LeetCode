/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//8ms. Interesting iterate solution
public: 
    void flatten(TreeNode* root) {
		TreeNode *now = root;
		while(now){
			if(now->left){
				TreeNode * leftNode = now->left;
				while(leftNode->right)
					leftNode = leftNode->right;
				leftNode->right = now->right;
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};