#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Running time at LeetCode online judge is 1ms. 
//Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1,n);
    }
    vector<TreeNode *> generateTrees(int begin, int end){
        vector<TreeNode *> result;
        if(begin > end){
            result.push_back(NULL);
            return result;  //size == 1
        }
        for(int i = begin; i <= end; i++){
            vector<TreeNode *> left = generateTrees(begin, i-1);
            vector<TreeNode *> right = generateTrees(i+1, end);
            for(size_t k = 0; k < left.size(); k++){
                for(size_t j = 0; j < right.size(); j++){
                    //TreeNode node(i); //If use this, the object will be destroied.
                    TreeNode *node = new TreeNode(i);
                    node->left = left[k];
                    node->right = right[j];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution mySolution;
    vector<TreeNode *> vec = mySolution.generateTrees(0);
    cout<<vec.size();
    system("pause");
}