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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int last=1, cur=0, rlt=1; // to avoid insert 'level' marker
        
        while(!q.empty()){
            TreeNode * curNode = q.front();
            q.pop();
            
            if(!curNode->left && !curNode->right) break;
            if(curNode->left) {q.push(curNode->left); cur++;}
            if(curNode->right) {q.push(curNode->right); cur++;}
            
            if(--last == 0){
                rlt++;
                last = cur;
                cur = 0;
            }
        }
        return rlt;
    }
};
