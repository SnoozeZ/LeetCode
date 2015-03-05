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
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        return DFS(root->left, root->right);
    }

    bool DFS(TreeNode *root1, TreeNode *root2){
        if(!root1&& !root2)
            return true;
        else if((root1) ^ (root2) == true)
            return false;
        bool tmp1 = DFS(root1->left, root2->right);
        if(root1->val != root2->val)
            return false;
        bool tmp2 = DFS(root1->right, root2->left);
        return tmp1 && tmp2;
    }
};

int main(){
    TreeNode l1(1), l2(2), l3(2), l4(3), l5(4), l6(4), l7(3);
    l1.left = &l2;
    l1.right = &l3;
    l2.left = &l4;
    l2.right = &l5;
    l3.left = &l6;
    //l3.right = &l7;

    Solution mySolution;
    bool result = mySolution.isSymmetric(&l1);

    system("pause");
}