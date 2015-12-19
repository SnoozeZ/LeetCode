class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(auto c :s){
            if((c>='a' && c<='z') || (c>='0' && c<='9'))
                ss+=c;
            if(c>='A' && c<='Z')
                ss += c+32; 
        }
        int i=0, j=ss.size()-1;
        while(i<j){
            if(ss[i++] != ss[j--]) return false;
        }
        return true;
    }
};
