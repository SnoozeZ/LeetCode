//Simple Backtracking
class Solution {
public:
    map<int, string> numDigits;
    vector<string> letterCombinations(string digits) {
        numDigits[2] = "abc";
        numDigits[3] = "def";
        numDigits[4] = "ghi";
        numDigits[5] = "jkl";
        numDigits[6] = "mno";
        numDigits[7] = "pqrs";
        numDigits[8] = "tuv";
        numDigits[9] = "wxyz";
        vector<string> rlt;
        string cur;
        
        if(digits == "") return rlt;
        helper(0, digits, cur, rlt);
        return rlt;
    }
    
    void helper(int start, string digits, string &cur, vector<string> &rlt){
        if(start == digits.size()){
            rlt.push_back(cur);
            return;
        }
        string curDigits = numDigits[digits[start]-'0'];
        for(int j = 0; j < curDigits.size(); j++){
            cur += curDigits[j];
            helper(start+1, digits, cur, rlt);
            cur = cur.substr(0, cur.size()-1);
        }
    }
};
