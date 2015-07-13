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
    int result;
    int kthSmallest(TreeNode* root, int k) { //O(n), 20ms
        int pos = 0;
        DFSHelper(root, pos, k);
        return result;
    }
    void DFSHelper(TreeNode *curNode, int &pos, int k){
        if(!curNode) return;
        DFSHelper(curNode -> left, pos, k);
        pos++;
        if(pos == k){
            result = curNode -> val;
            return;
        }
        DFSHelper(curNode -> right, pos, k);
    }
};