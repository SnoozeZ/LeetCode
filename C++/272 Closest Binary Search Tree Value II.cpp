/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <float.h>
//Heap Solution, O(k + (n-k)*logk) = 
class Solution2 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> heap;
        vector<int> rlt;
        searchTree(root, target, k, heap);
        while(!heap.empty()){
            rlt.push_back(heap.top().second);
            heap.pop();
        }
        return rlt;
    }
    
    void searchTree(TreeNode* root, double target, int k, priority_queue<pair<double, int>>& heap){
        if(!root) return;
        
        heap.push(pair<double, int>(abs(root->val - target), root->val));
        if(heap.size() > k)
            heap.pop();
        searchTree(root->left, target, k, heap);
        searchTree(root->right, target, k, heap);
    }
};

//Inorder traverse solution, O(n)
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> inorder;
        vector<int> rlt;
        //inorder traverse
        helper(root, inorder);
        //find the smallest num
        double tmp = double(INT_MAX);
        int pos=0;
        for(int i = 0; i < inorder.size(); i++){
            if(tmp > abs(inorder[i] - target)){
                tmp = abs(inorder[i] - target);
                pos = i;
            }
        }
        //return vector<int>({inorder[2]});
        rlt.push_back(inorder[pos]);
        k--;
        //find the k smallest
        int left = pos-1, right = pos+1;
        while(k-- > 0){
            int leftVal = left>=0 ? inorder[left] : INT_MIN;
            int rightVal = right<inorder.size() ? inorder[right] : INT_MIN;
            if(abs(leftVal - target) > abs(rightVal - target)){
                rlt.push_back(rightVal);
                right++;
            }else{
                rlt.push_back(leftVal);
                left--;
            }
        }
        return rlt;
    }
    
    void helper(TreeNode* root, vector<int>& inorder){
        //inorder traverse
        if(!root) return;
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
        return;
    }
};
