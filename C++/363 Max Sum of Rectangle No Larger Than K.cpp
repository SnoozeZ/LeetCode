// Interesting implementation: 
// https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references/14

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        int result = INT_MIN;
        for(int left = 0; left < matrix[0].size(); left++) {
            vector<int> sums(matrix.size(), 0);
            for(int right = left; right < matrix[0].size(); right++) {
                for(int i = 0; i < matrix.size(); i++) {
                    sums[i] += matrix[i][right];
                }
                
                // Find the rectangle sum less than K.
                int accSum = 0; // Accumulative sum. 
                set<int> prefixSum;
                prefixSum.insert(accSum);
                for(int i = 0; i < sums.size(); i++) {
                    accSum += sums[i];
                    int goal = accSum - k;
                    if(prefixSum.lower_bound(goal) != prefixSum.end()) {
                        result = max(result, accSum - *prefixSum.lower_bound(goal));
                    }
                    prefixSum.insert(accSum);
                }
            }
        }
        return result;
    }
};
