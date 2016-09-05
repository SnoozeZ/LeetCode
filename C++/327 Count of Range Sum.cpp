// Use a enhanced BST to keep the searched prefix sum. 
// In average, time O(nlogn). Worest cases, O(n^2). 

class Node {
public:
    Node* left, *right;
    long val;
    int leftCount;
    int equalCount;
    Node(long val) {
        this->val = val;
        equalCount = 1;
        leftCount = 0;
        left = NULL, right = NULL;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        Node *root = NULL;
        long prefixSum = 0, result = 0;
        root = insert(root, 0);
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int low = findSmaller(root, prefixSum - upper, true);
            int up = findSmaller(root, prefixSum - lower, false);
            result += up - low;
            root = insert(root, prefixSum);
        }
        return result;
    }
    
    Node* insert(Node* root, long val) {
        if(root == NULL) return new Node(val);
        if(root->val > val) {
            root->leftCount++;
            root->left = insert(root->left, val);
        } else if (root->val < val) {
            root->right = insert(root->right, val);
        } else {
            root->equalCount++;
        }
        return root;
    }
    
    int findSmaller(Node* root, long val, bool isLower) {
        if(root == NULL) return 0;
        if(root->val == val) {
            if(isLower)
                return root->leftCount;
            else
                return root->equalCount + root->leftCount;
        }
        if(root->val > val) {
            return findSmaller(root->left, val, isLower);
        } else {
            return root->leftCount + root->equalCount + findSmaller(root->right, val, isLower);
        }
    }
};
