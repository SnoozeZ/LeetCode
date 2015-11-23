//least swap times. time O(n)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int left=0, right=nums.size()-1;
        while(nums[right]==val && right>=0) right--;
        
        while(left <= right){
            if(nums[left] == val){
                swap(nums[left], nums[right]);
                while(nums[right]==val && right>=0) right--;
            }
            left++;
        }
        return left;
    }
};
