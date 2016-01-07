class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size()-1;
        int pivot = right;
        //first binary search: find the pivot
        while(left<=right){//search the pivot
            int mid = (left + right)/2;
            if(nums[mid] == target) return mid;//lucky boy
            if(nums[mid] > nums[mid+1]){
                pivot = mid;
                break;
            }
            if(nums[left] <= nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        //set new left and right
        if(target >= nums[0]){//search before pivot
            left = 0;
            right = pivot;
        }else{//search after pivot
            left = pivot + 1;
            right = nums.size()-1;
        }
        //second binary search: find the target
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
