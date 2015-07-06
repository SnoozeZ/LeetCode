/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //O((logN)^2),180ms
public:
	int nodeNumber, height;
    int countNodes(TreeNode* root) {
        if(!root) return 0;
		//calculate height
		TreeNode * p;
		height = 1;
		for(p = root; p->left; p = p->left, height++);
		//do
		nodeNumber = pow(2, height-1)-1;
		DFSHelper(root,1);
		return nodeNumber;
    }	
	
	void DFSHelper(TreeNode* curNode, int curDepth){
		if(curNode == NULL)
			return; //stop
		TreeNode* childNode = curNode->left;
		if(childNode == NULL){
			if(curDepth == height) nodeNumber += 1;
			return;	
		}
		
		int tmpDepth = 0;
		while(childNode->right){
			childNode = childNode->right;
			tmpDepth ++;
		}
		if(curDepth + tmpDepth + 1 == height){	//leaf node
			nodeNumber += pow(2,tmpDepth);
			return DFSHelper(curNode->right, curDepth+1);
		}else{//not leaf node
			return DFSHelper(curNode->left, curDepth+1);
		}
	}
};

