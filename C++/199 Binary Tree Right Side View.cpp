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
    vector<int> rightSideView(TreeNode* root) { //O(N), 4ms
        vector<int> result;
		if(!root) return result;
		
		queue<TreeNode *> toVisit;
		TreeNode* lastNode = root;
		toVisit.push(root);
		
		while(!toVisit.empty()){
			TreeNode *curNode = toVisit.front();
			toVisit.pop();
			if(curNode->left) toVisit.push(curNode->left);
			if(curNode->right) toVisit.push(curNode->right);
			if(curNode == lastNode){
				result.push_back(lastNode->val);
				lastNode = toVisit.back();
				if(curNode->left) lastNode = curNode->left;
				if(curNode->right) lastNode = curNode->right;
			}
		}
		return result;
    }
};