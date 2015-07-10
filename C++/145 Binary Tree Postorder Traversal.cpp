/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //O(N), 0ms. Ugly code.
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        
        stack<int> toVisit;
        TreeNode *curNode = root;
        Map<TreeNode*, bool> secondVisit;
        //toVisit.push_back(root);
        
        while(curNode || !toVisit.empty()){
            if(curNode){
                toVisit.push(curNode);
                curNode = curNode->left;
            }else{
                curNode = toVisit.top();
                if(secondVisit[curNode] == false){ //visit for the first time
                    secondVisit[curNode] = true;
                    curNode = curNode->right;
                }else{
                    while(secondVisit[curNode] == true){    
                        result.push_back(curNode->val);
                        toVisit.pop();
                        curNode = toVisit.top();
                    }
                    if(curNode){
                        
                    } 
                }
            }
        }
    }
};
