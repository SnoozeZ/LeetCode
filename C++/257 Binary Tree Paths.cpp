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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rlt;
        if(!root) return rlt;
        vector<TreeNode *> path;
        dfs(rlt, root, path);
        return rlt;
    }
    
    void dfs(vector<string>& rlt, TreeNode *root, vector<TreeNode *> path){
        path.push_back(root);
        if(!root->left && !root->right){
            //leaf node, add
            string curRlt = "";
            for(auto node : path)
                curRlt += to_string(node->val) + "->";
            curRlt = curRlt.substr(0, curRlt.size()-2);
            rlt.push_back(curRlt);
            return;
        }
        if(root->left) dfs(rlt, root->left, path);
        if(root->right) dfs(rlt, root->right, path);
    }
};
