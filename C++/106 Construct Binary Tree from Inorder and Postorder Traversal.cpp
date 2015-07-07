/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <algorithm>
class Solution { // O(N), 20ms, evolved from Problem 105
public:
	map<int, int> hashMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		for(size_t i = 0; i < inorder.size(); i++){
			hashMap[inorder[i]] = i;
		}
		int prePos = 0;
		std::reverse(postorder.begin(), postorder.end());
		return constructTree(inorder, postorder, 0, inorder.size()-1, prePos);
    }
	TreeNode* constructTree(vector<int>& inorder, vector<int>& preorder, int left, int right, int& prePos){
		if(left > right || prePos==inorder.size()){
			prePos--; 
			return NULL;
		}
		int inPos = hashMap[preorder[prePos]];
		TreeNode* root = new TreeNode(inorder[inPos]);
		root -> right = constructTree(inorder, preorder, inPos+1, right, ++prePos);
		root -> left = constructTree(inorder, preorder, left, inPos-1, ++prePos);
		return root;
	}
};