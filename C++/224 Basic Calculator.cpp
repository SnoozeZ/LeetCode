// Not that complex, just traverse one by one.
// Use a stack to cache the old sign and result;
class Solution {
public:
    int calculate(string s) {
        stack<int> cache;
        int result=0, sign=1, num=0;
        for(int i = 0; i < s.size(); i++) {
            char cur = s[i];
            if(cur>='0' && cur<='9') {
                num = num*10 + cur-'0';
            } else if (cur == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (cur == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (cur == '(') {
                // Cache two things: cur result and sign
                cache.push(result);
                cache.push(sign);
                result = 0;
                sign = 1;
            } else if(cur == ')') {
                result += sign*num;
                num = 0;
                result *= cache.top();  // Cached sign.
                cache.pop();
                result += cache.top();  // Cached result
                cache.pop();
            } else {
                continue;
            }
        }
        // Final Number
        if(num != 0) result += sign * num;
        return result;
    }
};
