// Interesting! Use a set to store all nums.
// Randomly pick up a num from the set, and check its left and right side.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        while(!numSet.empty()) {
            int cur = *numSet.begin(), curLength = 1;
            int left = cur-1, right = cur+1;
            numSet.erase(cur);
            
            // Find the left side.
            while(numSet.count(left)) {    
                curLength ++;
                numSet.erase(left);
                left--;
            }
            
            // Find the right side.
            while(numSet.count(right)) {    // Right
                curLength ++;
                numSet.erase(right);
                right++;
            }
            result = max(result, curLength);
        }
        return result;
    }
};
