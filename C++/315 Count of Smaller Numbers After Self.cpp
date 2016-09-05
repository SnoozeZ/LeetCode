// Use BST to keep the already sorted array. 
// The worest time complexity is O(n^2).

class MyTreeNode{
public:
    MyTreeNode* left, *right;
    int val, count;
    MyTreeNode(int v) {
        val = v;
        count = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        MyTreeNode *root = NULL;
        for(int i = nums.size()-1; i >=0; i--) {
            int preSum = 0;
            root = insert(root, nums[i], preSum, res, i);
        }
        return res;
    }
    
    MyTreeNode* insert(MyTreeNode *root, int val, int preSum, vector<int>& res, int idx) {
        if(root == NULL) {
            root = new MyTreeNode(val);
            res[idx] = preSum;
            return root;
        } else {
            if(root->val > val) {
                root->count++;
                root->left = insert(root->left, val, preSum, res, idx);
            } else if(root->val < val){
                root->right = insert(root->right, val, preSum + (root->count)+1, res, idx);
            } else {
                root->right = insert(root->right, val, preSum + root->count, res, idx);
            }
        }
        return root;
    }
};
