/*
//4ms, time O(N), space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return nums[i+1];
        }
        return nums[0];//size is 1 or array is in order.
    }
};
*/

//Binary search solution, 4ms, time O(logN), space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums[0] < nums[nums.size()-1]) return nums[0]; 
        return binarySearch(nums, 0, nums.size()-1);
    }
    
    int binarySearch(vector<int>& nums, int left, int right){
        int mid = (left+right)/2;
        
        if(nums[mid] > nums[mid+1])
            return nums[mid+1];//it's found
        
        if(nums[mid] > nums[left]){
            return binarySearch(nums, mid, right);
        }else if(nums[mid] < nums[right]){
            return binarySearch(nums, left, mid);
        }
    }
};
