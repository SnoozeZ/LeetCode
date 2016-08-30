//Greedy, O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int step = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(--step<0) return false;
            else(step = max(step, nums[i]));
        }
        return true;
        
    }
};

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int longest = nums[0];
//         for(int i = 0; i < nums.size(); i++) {
//             if(longest < i) return false;
//             longest = max(longest, i+nums[i]);
//         }
//         return true;
//     }
// };
