//DP and DFS, O(n^2)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        //use dp to construct the palindrome matrix
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        for(int i =n-1; i >=0; i--)
            for(int j = i; j < n; j ++)
                if((i+1 >= j-1 || isPal[i+1][j-1])&&s[i]==s[j])
                    isPal[i][j] = true;
        //DFS find all partitioning approaches
        vector<vector<string>> rlt;
        vector<string> cur;
        
        dfs(s, 0, cur, rlt, isPal);
        return rlt;
    }
    void dfs(string s, int start, vector<string> &cur, vector<vector<string>>& rlt, vector<vector<bool>>& isPal){
        if(start == s.size()){
            rlt.push_back(cur);
        }
        
        for(int i = start; i < s.size(); i++){
            if(!isPal[start][i]) continue;
            cur.push_back(s.substr(start, i-start+1));
            dfs(s, i+1, cur, rlt, isPal);
            cur.pop_back();
        }
    }
};
