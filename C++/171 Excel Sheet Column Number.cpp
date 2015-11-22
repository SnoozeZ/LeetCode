class Solution {
public:
    int titleToNumber(string s) {
        int rlt = 0;
        for(int i = 0; i<s.size(); i++){
            rlt += (s[s.size()-1-i] - 'A' + 1) * pow(26, i);
        }
        return rlt;
    }
};
