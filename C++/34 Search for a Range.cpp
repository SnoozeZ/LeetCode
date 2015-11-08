//Binary Search, twice, to find the left and right boundary respectively.
//time complexity O(lgn)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rlt(2,-1);
        int left=0, right=nums.size()-1;
        int leftBoundary, rightBoundary;
        //find the left boundary
        while(true){
            if(left > right) return rlt;// not found
            int mid = (left+right)/2;
            if(target > nums[mid]){
                left = mid+1;
            }else if(target < nums[mid]){
                right = mid-1;
            }else{
                if(mid > left && nums[mid-1]==target) right = mid-1;
                else{
                    rlt[0] = mid;
                    break;
                }
            }
        }
        
        //find the right boundary
        left=0;
        right=nums.size()-1;
        while(true){
            int mid = (left+right)/2;
            if(target > nums[mid]){
                left = mid+1;
            }else if(target < nums[mid]){
                right = mid-1;
            }else{
                if(mid < right && nums[mid+1]==target) left = mid+1;
                else{
                    rlt[1] = mid;
                    break;
                }
            }
        }
        return rlt;
    }
};
