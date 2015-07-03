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
	vector<vector<int> > resultVector;
	
    vector<vector<int>> pathSum(TreeNode* root, int sum) {//24ms
        DFSHelper(root, vector<int>(0), sum);
		return resultVector;
    }
	
	void DFSHelper(TreeNode* node, vector<int> valueVector, int sum){
		if(!node) return;
		valueVector.push_back(node->val);
		if(!node->left && !node->right){//leaf node
			if(node->val == sum)
				resultVector.push_back(vector<int> (valueVector));
		}
		DFSHelper(node->left, valueVector, sum - node->val);
		DFSHelper(node->right, valueVector, sum - node->val);
		return;
	}
};
