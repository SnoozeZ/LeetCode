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
	int totalNumber;
    int sumNumbers(TreeNode* root) {
		vector<int> numberVector;
		DFSHelper(root, numberVector);
		return totalNumber;
    }
	
	void DFSHelper(TreeNode* node, vector<int> numberVector){
	    if(node == NULL)//edge case
	        return;
		int returnValue = 0;
		if(node->left != NULL || node->right != NULL){//not leaf node
		    vector<int> tmpVector(numberVector);
		    tmpVector.push_back(node->val);
		    if(node->left != NULL)
			    DFSHelper(node->left, tmpVector);//left
		    if(node->right != NULL)
			    DFSHelper(node->right, tmpVector);//right
		}else{ //leaf node
			numberVector.push_back(node->val);
			size_t length = numberVector.size();
			for(int i : numberVector){
				returnValue += i * pow(10, length - 1);//calculate the value
				length --;
			}
			totalNumber += returnValue;
		}
		return;
	}

};