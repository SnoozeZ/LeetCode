class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> nums1(nums.begin()+1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()-1);
        
        return max(robLine(nums1), robLine(nums2));
    }
    
    int robLine(vector<int> nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        if(nums.size()==3) return max(nums[0]+nums[2], nums[1]);
        
        vector<int> money(nums.size(), INT_MIN);
        money[0] = nums[0];
        money[1] = nums[1];
        money[2] = nums[2]+nums[0];
        
        for(int i=3; i<nums.size(); i++){
            money[i] = nums[i] + max(money[i-2], money[i-3]);
        }
        return max(money[nums.size()-1], money[nums.size()-2]);
    }
};
