class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0) return vector<int>();    

        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> path(nums.size());
        for(int i = 0; i < path.size(); i++) {
            path[i] = i;
        }
        int max = 1, pos = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    path[i] = j;
                    if(dp[i] > max) {
                        max = dp[i];
                        pos = i;
                    }
                }
            }
        }
        
        // Back Tracking
        deque<int> res;
        while(true) {
            res.push_front(nums[pos]);
            int tmp = path[pos];
            if(tmp == pos) break;
            pos = tmp;
        }
        
        return vector<int>(res.begin(), res.end());
    }
};
