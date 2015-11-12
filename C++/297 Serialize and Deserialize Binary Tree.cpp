/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string rlt="";
        if(!root) return rlt;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()){
            TreeNode* cur = nodeQueue.front();
            nodeQueue.pop();
            rlt += cur? to_string(cur->val) : "#";
            rlt += ",";
            if(cur){
                nodeQueue.push(cur->left);
                nodeQueue.push(cur->right);
            }
        }
        return rlt;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        vector<TreeNode*> nodeVec;
        string cur="";
        //decode string into treenode
        for(int i=0; i<data.size(); i++){
            if(data[i] != ','){cur+=data[i]; continue;}
            else{
                if(cur == "#") nodeVec.push_back(nullptr);
                else{
                    TreeNode *newNode = new TreeNode(atoi(cur.c_str()));
                    nodeVec.push_back(newNode);
                }
                cur.clear();
            }
        }
        //constract tree
        int t=0;    //correction of the subscript when there is a null
        for(int i=0; i<nodeVec.size(); i++){// Be careful! Why not nodeVec.size()/2 ?
            if(i>=nodeVec.size()) break;
            if(nodeVec[i]){
                nodeVec[i]->left = nodeVec[2*i+1 -t];
                nodeVec[i]->right = nodeVec[2*i+2 -t];
            }else{
                t+=2;
            }
        }
        return nodeVec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
