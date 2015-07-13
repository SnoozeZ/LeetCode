/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> toVisit;
    BSTIterator(TreeNode *root) {
        DFSHelper(root);
    }

    void DFSHelper(TreeNode * curNode){
        while(curNode){
            toVisit.push(curNode);
            curNode = curNode -> left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !toVisit.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *curNode = toVisit.top();
        int val = curNode -> val;
        toVisit.pop();
        DFSHelper(curNode->right);
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */