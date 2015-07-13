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
    vector<int> postorderTraversal(TreeNode* root) {//O(N) 0ms. Ugly code.
        vector<int> result;
        if(!root) return result;
        
        stack<TreeNode *> toVisit;
        TreeNode *curNode = root;
        map<TreeNode*, bool> secondVisit;
        
        while(curNode || !toVisit.empty()){
            if(curNode){    //curnode not null
                toVisit.push(curNode);
                curNode = curNode->left;
            }else{// curnode is null
                curNode = toVisit.top();
                if(secondVisit[curNode] == false){ //visit for the first time
                    secondVisit[curNode] = true;
                    curNode = curNode->right;
                }else{//not the first time
                    while(secondVisit[curNode] == true){
                        result.push_back(curNode->val);
                        toVisit.pop();
                        if(toVisit.empty()) break;
                        curNode = toVisit.top();
                    }
                    if(curNode){
                        secondVisit[curNode] = true;
                        curNode = curNode ->right;
                    }
                }
            }
            if(toVisit.empty()) break;
        }
        return result;
    }
};