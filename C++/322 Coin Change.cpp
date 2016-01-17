//DP. O(mn), m[i] = min(for all coin j: min[i - j] + 1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> m(amount+1, INT_MAX);
        m[0] = 0;
        for(int i = 0; i < amount+1; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && m[i-coins[j]] != INT_MAX)
                    m[i] = min(m[i], m[i-coins[j]] + 1);
            }
        }
        return m.back() == INT_MAX ? -1 : m.back();
    }
};
