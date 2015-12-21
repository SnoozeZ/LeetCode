/*class Solution {
public:
    bool canWin(string s) {
        if(s.size()<2) return false;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '+' && s[i+1] == '+' && !canWin(s.substr(0, i) + "--" + s.substr(i+2)))
                return true;
        }
        return false;
    }
};*/

class Solution {
public:
    bool canWin(string s) {
        if(s.size()<2) return false;
        return helper(s);
    }
    bool helper(string &s){
        for(int i =0; i < s.size()-1; i++){
            if(s[i] == '+' && s[i+1] == '+'){
                s[i] = '-';
                s[i+1] = '-';
                bool win = helper(s);
                s[i] = '+';
                s[i+1] = '+';
                if(!win) return true;
            }
        }
        return false;
    }
};

