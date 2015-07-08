/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) { //O(N), 0ms
		vector<int> result; 
        if(!root) return result;
		
		stack<TreeNode *> toVisit;
		toVisit.push(root);
		
		while(!toVisit.empty()){
			TreeNode *curNode = toVisit.top();
			toVisit.pop();
			result.push_back(curNode->val);
			if(curNode->right) toVisit.push(curNode->right);
			if(curNode->left) toVisit.push(curNode->left);
		}
		return result;
    }
};