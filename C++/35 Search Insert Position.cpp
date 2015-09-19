//8ms, time O(logN), space O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return binarySearch(nums, 0, nums.size()-1, target);
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target){
        int m = (left+right)/2;
        if(left > right)
            return left;
    
        if(nums[m] == target)
            return m;
        else if(nums[m] < target)
            return binarySearch(nums, m+1, right, target);
        else
            return binarySearch(nums, left, m-1, target);
    }
};
