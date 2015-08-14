class Solution {
public:
    int removeDuplicates(vector<int>& nums) {//time O(N), space O(1), 32ms AC.
        if(nums.empty()) return 0;
        size_t ptr1=0, ptr2=0, size = nums.size();
        while(ptr2 < size-1)
            if(nums[++ptr2] != nums[ptr1])
                nums[++ptr1] = nums[ptr2];
        return ptr1 + 1;
    }
};
