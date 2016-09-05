// Interesting solution: https://discuss.leetcode.com/topic/35973/java-intuitive-22ms-solution-with-stack

class Solution {
public:
    bool isValidSerialization(string input) {
        vector<string> preorder= split(input, ',');
        stack<string> st;
        for(int i = 0; i < preorder.size(); i++) {
            string cur = preorder[i];
            while(!st.empty() && cur == "#" && st.top() == cur) {
                st.pop();
                if(st.empty()) return false;
                st.pop();
            }
            st.push(cur);
        }
        return st.size()==1 && st.top()=="#";
    }
    
    vector<string> split(string preorder, char p) {
        stringstream ss(preorder);
        vector<string> res;
        string tmp;
        while(getline(ss, tmp, p)) {
            res.push_back(tmp);
        }
        return res;
    }
};
