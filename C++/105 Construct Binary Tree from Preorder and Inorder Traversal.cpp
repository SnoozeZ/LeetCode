/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // O(N), 20ms,  Yaah!
public:
	map<int, int> hashMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for(size_t i = 0; i < inorder.size(); i++){
			hashMap[inorder[i]] = i;
		}
		int prePos = 0;
		return constructTree(inorder, preorder, 0, inorder.size()-1, prePos);
    }
	TreeNode* constructTree(vector<int>& inorder, vector<int>& preorder, int left, int right, int& prePos){
		if(left > right || prePos==inorder.size()){
			prePos--; 
			return NULL;
		}
		int inPos = hashMap[preorder[prePos]];
		TreeNode* root = new TreeNode(inorder[inPos]);
		root -> left = constructTree(inorder, preorder, left, inPos-1, ++prePos);
		root -> right = constructTree(inorder, preorder, inPos+1, right, ++prePos);
		return root;
	}
};