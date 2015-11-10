/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Recursion. If two subtrees that contains the target nodes meet for the first time, the root is the LCA.
class Solution {
public:
    TreeNode *result;
    bool stop;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return result;
    }
    
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q){  //true means contains the target node
        if(stop || root == NULL) return false;
        
        bool rootContain = false;
        if(root == p || root == q) rootContain=true; 
        bool L = helper(root->left, p, q);
        bool R = helper(root->right, p, q);
        if((L&&R) || rootContain&&(L||R) ){
            result = root;
            stop = true;
        }
        return L||R||rootContain;
    }
};
