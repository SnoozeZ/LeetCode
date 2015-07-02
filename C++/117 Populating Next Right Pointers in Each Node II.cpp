/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(!root) return;
		TreeLinkNode* startNode = findNextStartNode(root), *fatherNode = root, *childNode = findNextStartNode(root);
		while(startNode != NULL){
			TreeLinkNode* nextNode = findNextNode(childNode, fatherNode);
			while(nextNode != NULL){
				childNode->next = nextNode;
				childNode = nextNode;
				nextNode = findNextNode(childNode, fatherNode);
			}
			fatherNode = startNode;
			startNode = findNextStartNode(fatherNode); 
			childNode = startNode;	
		}
    }
	
	TreeLinkNode * findNextNode(TreeLinkNode* childNode, TreeLinkNode* &fatherNode){
		if(childNode == fatherNode->left && fatherNode->right){	
			return fatherNode->right;
		}
		while(fatherNode->next != NULL){
			fatherNode = fatherNode->next;
			if(fatherNode->left) return fatherNode->left;
			if(fatherNode->right) return fatherNode->right;
		}
		return NULL;
	}
	
	TreeLinkNode* findNextStartNode(TreeLinkNode *& startNode){
		if(startNode->left) 
			return startNode->left;
		else
			return findNextNode(startNode->left, startNode);
	}
};



