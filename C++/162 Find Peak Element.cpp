/*
//Linear Search Solution, 8ms, time O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i =0; i < nums.size(); i++){
            if(i != 0 && nums[i] < nums[i-1]) continue;
            if(i != nums.size()-1 && nums[i] < nums[i+1]) continue;
            return i;
        }
    }
};
*/

//Binary Search Solution, 4ms, time O(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return biSearch(0, nums.size()-1, nums);
    }
    int biSearch(int left, int right, vector<int> nums){
        if(left == right) return right;
        
        int mid = (left + right)/2;
        if(nums[mid+1] > nums[mid]) 
            return biSearch(mid+1, right, nums);
        else return biSearch(left, mid, nums);
    }
};
