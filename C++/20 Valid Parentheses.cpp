class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto c : s){
            if(stack.empty()){
                stack.push(c);
                continue;
            }
            char tmp = stack.top();
            if((tmp == '[' && c == ']')||(tmp == '(' && c == ')')||(tmp == '{' && c == '}'))
                stack.pop();
            else
                stack.push(c);
        }
        return stack.empty();
    }
};
