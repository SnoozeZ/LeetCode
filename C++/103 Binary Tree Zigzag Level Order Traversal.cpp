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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { //O(N), 4ms
		vector<vector<int>> result;
		if(!root) return result;
		
		queue<TreeNode*> toVisit;
		TreeNode* lastNode = root;
		vector<int> tmpVector;
		
		toVisit.push(root);
		bool rFlag = false; //reverse or not
		
		while(!toVisit.empty()){
			TreeNode * curNode = toVisit.front();
			toVisit.pop();
			tmpVector.push_back(curNode->val);
			if(curNode->left) toVisit.push(curNode->left);
			if(curNode->right) toVisit.push(curNode->right);
			
			if(curNode == lastNode){//last node of this level
				lastNode = toVisit.back();
				if(curNode->left) lastNode = curNode->left;
				if(curNode->right) lastNode = curNode->right;
				if(rFlag) std::reverse(tmpVector.begin(), tmpVector.end());
				result.push_back(vector<int> (tmpVector));
				tmpVector.clear();
				rFlag = !rFlag;
			}
		}
		return result;
    }
};