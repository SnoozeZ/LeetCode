#include <iostream>
#include <string>
#include <stack>

using namespace std;
//Runtime at LeetCode OJ is 24 ms.

//Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidNode(TreeNode *root, long min, long max){
        if(NULL == root) return true;
        if(min < root->val && max > root->val){
            return isValidNode(root->left, min, root->val) 
                && isValidNode(root->right, root->val, max);
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode *root) {
        return isValidNode(root, LONG_MIN, LONG_MAX);
    }
    
};

int main(){
    TreeNode l1(10), l2(5), l3(15), l4(6), l5(20);
    l1.left = &l2;
    l1.right = &l3;
    l3.left = &l4;
    l3.right = &l5;

    Solution mySolution;
    bool result = mySolution.isValidBST(&l1);

    system("pause");
} 