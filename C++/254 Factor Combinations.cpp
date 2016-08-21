//Interesting backtracking. The remain should be composited by nums larger or equal to current factor. 

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> cur;
        if(n < 2) return result;
        dfs(result, n, cur, 2);
        return result;
        
    }
    
    void dfs(vector<vector<int>>& result, int remain, vector<int> cur, int start) {
        if(remain == 1 && cur.size() > 1) {
            result.push_back(cur);
        }
        
        for(int i = start; i <= remain; i++) {
            if(i > sqrt(remain)) i = remain; // Prune. The factor should smaller than sqrt(remain). 
                                             // Thought, we need to check when factor == remain itself.
            
            if(remain % i == 0) {
                cur.push_back(i);
                dfs(result, remain/i, cur, i);
                cur.pop_back();
            }
        }
    }
};
