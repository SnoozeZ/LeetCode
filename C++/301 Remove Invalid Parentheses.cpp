class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;// use set to eleminate the duplicate
        vector<string> rlt;
        queue<string> q;
        q.push(s);
        while(!q.empty()){
            int size = q.size();
            int flag = false;
            for(int i = 0; i <size; i++){// in this level
                string cur = q.front();
                q.pop();
                //check valid or not
                if(isValid(cur)){
                    flag = true;
                    rlt.push_back(cur);
                }
                //BFS
                if(flag == false){
                    for(int i = 0; i < cur.size(); i++){
                        if(cur[i] != '(' && cur[i] != ')') continue;
                        string newStr = cur.substr(0, i) + cur.substr(i+1);
                        if(visited.find(newStr) == visited.end()){
                            q.push(newStr);
                            visited.insert(newStr);
                        }
                    }
                }
            }
            //check 
            if(flag == true){// only find the smallest level
                break;
            }
        }
        return rlt;
    }
    // BAD check FUNCTION
    // bool isValid(string str){
    //     if(str == "") return false;
    //     stack<char> stack;
    //     for(char c : str){
    //         if(c != '(' && c != ')') continue;
    //         if(stack.empty()){
    //             stack.push(c);
    //             continue;
    //         }
    //         if(stack.top() == '(' && c == ')'){
    //             stack.pop();
    //         }else{
    //             stack.push(c);
    //         }
    //     }
    //     return stack.empty();
    // }
    
    bool isValid(string str){
        int left=0, right=0;
        for(char c : str){
            if(c == '(') left++;
            if(c == ')') right++;
            if(right > left) return false;
        }
        return left == right;
    }
};
