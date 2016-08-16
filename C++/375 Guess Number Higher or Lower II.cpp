// Use dynamic programing.
// The transform equation is dp[i][j] = min_p(p + max(dp[i][p-1], dp[p+1][j]))
// Then return dp[1][n]

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int len = 1; len < n; len++) {
            for (int i = 1; i + len <= n; i++) {
                dp[i][i+len] = INT_MAX;
                for (int j = i; j <= i+len; j++) {
                    if (j == i)
                        dp[i][i+len] = min(dp[i][i+len], j + dp[j+1][i+len]);
                    else if (j == i+len)
                        dp[i][i+len] = min(dp[i][i+len], j + dp[i][j-1]);
                    else
                        dp[i][i+len] = min(dp[i][i+len], j + max(dp[j+1][i+len], dp[i][j-1]));
                }
            }
        }
        return dp[1][n];
    }
};
