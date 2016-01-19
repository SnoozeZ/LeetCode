/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//BFS~~
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        vector<vector<int>> rlt;
        queue<pair<TreeNode*, int>> q;
        if(root)
            q.push(pair<TreeNode*, int>(root, 0));// <TreeNode, position>
        //Let's BFS!
        while(!q.empty()){
            int size = q.size();//cool
            while(size-- > 0){
                pair<TreeNode*, int> cur = q.front();
                q.pop();
                map[cur.second].push_back(cur.first->val);
                if(cur.first->left != NULL)
                    q.push(pair<TreeNode*, int>(cur.first->left, cur.second-1));
                if(cur.first->right != NULL)
                    q.push(pair<TreeNode*, int>(cur.first->right, cur.second+1));
            }
        }
        //return
        for(auto p : map){
            rlt.push_back(p.second);
        }
        return rlt;
    }
};
