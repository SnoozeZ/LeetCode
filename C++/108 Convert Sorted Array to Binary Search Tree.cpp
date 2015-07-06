
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums);
    }
	
	TreeNode* constructBST(vector<int> nums){
		if(nums.empty()) return NULL;
		size_t middle = nums.size()/2 + nums.size()%2;
		TreeNode * root = new TreeNode(nums[middle-1]);
		root->left = constructBST(vector<int>(nums.begin(), nums.begin()+middle-1));
		root->right = constructBST(vector<int>(nums.begin()+middle, nums.end()));
		return root;
	}
};