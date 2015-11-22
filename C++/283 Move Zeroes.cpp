//Two pointer, time O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int pos1=0, pos2=0;
        while(nums[pos1]!=0) pos1++;
        for(pos2 = pos1; pos2<nums.size(); pos2++){
            if(nums[pos2]!=0){
                swap(nums[pos1], nums[pos2]);
                while(nums[pos1]!=0) pos1++;
            }
        }
    }
};
