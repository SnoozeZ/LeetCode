//DP
//O(n*k) sub problems, and O(k) choices for each sub problem. => O(nkk)
//Improvenment: record the largest and the second largest situation in last step. => O(2) choices for each sub problem => O(nk)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = costs.size(), m = costs[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m, INT_MAX));
        
        for(int i = 0; i < m; i++) dp[0][i] = 0;

        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < m; j++)
                for(int k = 0; k < m; k++){
                    if(k == j && i != 1) continue;  //trik: when i == 1 we shouldn't continue
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i-1][j]);
                }
        }
        //find result
        int rlt = INT_MAX;
        for(int tmp : dp.back()) rlt = min(rlt, tmp);
        return rlt;
    }
};
