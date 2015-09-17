class Solution {
public:
    int singleNumber(vector<int>& nums) {// Runtime 20ms, time complexity O(n), not extra space
        for(int i = 0; i<nums.size();i++){
            if(!i) continue;
            nums[0] = nums[0] ^ nums[i];
        }
        return nums[0];
    }
};
