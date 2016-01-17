//dp. O(3n) sub-problems, O(3) choices for each sub-problem
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = costs.size(), m = costs[0].size();
        vector<vector<int>> dp(n+1,vector<int>(3, INT_MAX));
        dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
        
        for(int i = 1; i < n+1; i++){
            dp[i][0] = min(dp[i-1][1] + costs[i-1][0], dp[i-1][2] + costs[i-1][0]);
            dp[i][1] = min(dp[i-1][0] + costs[i-1][1], dp[i-1][2] + costs[i-1][1]);
            dp[i][2] = min(dp[i-1][0] + costs[i-1][2], dp[i-1][1] + costs[i-1][2]);
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};
