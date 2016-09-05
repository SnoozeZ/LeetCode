// Kind of a GRE math problem.. 排列组合
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1);
        dp[0] = 1, dp[1] = 9 + dp[0];
        for(int i = 2; i <= n; i++) {
            int count = 9;
            for(int j = 1; j < i; j++) {
                count *= 10 - j;
            }
            dp[i] = dp[i-1] + count;
        }
        return dp[n];
    }
};
