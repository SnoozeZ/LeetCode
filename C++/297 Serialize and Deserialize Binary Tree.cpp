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

// 2nd solution. Recursion.
// // Let's do this in the format: {1,{2,{},{}},{3,{},{5,{},{}}}}. Each {} represents a tree.

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Codec {
// public:
    
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (root == NULL) return "{}";
//         string result = "{";
//         result += to_string(root->val) + ",";
//         result += serialize(root->left) + ",";
//         result += serialize(root->right) + "}";
//         return result;
//     }
    
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         int pos = 0;
//         return deHelper(data, pos);
//     }
    
//     TreeNode* deHelper(string& data, int& pos) {
//         if (data[pos]=='{' && data[pos+1]=='}') {
//             pos+=2;
//             return NULL;
//         }
        
//         // Decode the integer.
//         int left = pos, value;
//         while(data[pos] != ',') pos ++;
//         value = stoi(data.substr(left+1, pos-left-1).c_str());
//         TreeNode* result = new TreeNode(value);
        
//         // Decode left and right child.
//         pos++; // handle ','
//         result->left = deHelper(data, pos);
//         pos++; // handle ','
//         result->right = deHelper(data, pos);
//         pos++; // handle '}'
//         return result;
//     }
    
// };

// // Your Codec object will be instantiated and called as such:
// // Codec codec;
// // codec.deserialize(codec.serialize(root));
