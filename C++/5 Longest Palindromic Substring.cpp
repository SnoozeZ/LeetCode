class Solution {
public:
    string longestPalindrome(string s) {//O(N^2) why超时?
        size_t size = s.size();
        string result = "";
        vector<vector<bool> > isPal(size, vector<bool>(size, false));

        for(size_t len = 0; len < size; len++){
            for(size_t pos = 0; len + pos < size; pos++){
                size_t tail = len + pos;
                if(s[pos] == s[tail] && (0 == len || 1 == len || isPal[pos+1][tail-1])){
                    isPal[pos][tail] = true;
                    if(tail - pos + 1 > result.size()) 
                        result = s.substr(pos, tail - pos + 1);
                }

            }
        }
        return result;
    }
};
