/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rlt;
        if(!root) return rlt;
        queue<TreeNode *> q;
        q.push(root);
        int last = 1;//two vars to help distinct different levels.
        int now = 0;//
        vector<int> tmp;
        while(!q.empty()){
            TreeNode * cur = q.front();
            q.pop();
            //
            if(cur->left){
                q.push(cur->left);
                now++;
            }
            if(cur->right){
                q.push(cur->right);
                now++;
            }
            //
            tmp.push_back(cur->val);
            if(--last == 0){
                rlt.push_back(tmp);
                tmp.clear();
                last = now;
                now=0;
            }
        }
        return rlt;
        
    }
};
