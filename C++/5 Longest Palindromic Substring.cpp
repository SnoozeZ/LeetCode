//DP, O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string rlt="";
        //vector<vector<bool>> isPal(n, vector<bool> (n, false));//leads to TLE
        bool isPal[1000][1000]={false};
        for(int i =n-1; i >=0; i--){
            for(int j = i; j < n; j ++){
                if((i+1 >= j-1 || isPal[i+1][j-1])&&s[i]==s[j]){
                    isPal[i][j] = true;
                    if(j-i+1 > rlt.size())
                        rlt = s.substr(i, j-i+1);
                }
            }
        }
        return rlt;
    }
};
