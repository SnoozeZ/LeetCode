// DP, transform function: dp[i][j] = max_k(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j])

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 1; i < n-1; i ++) dp[i][i] = nums[i];
        
        for(int len = 2; len < n; len++) {
            for(int l = 0; l < n-len; l++) {
                int r = l + len;
                for(int m = l+1; m < r; m++) {
                    dp[l][r] = max(dp[l][r], nums[l]*nums[m]*nums[r] + dp[l][m] + dp[m][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};
