class Solution {
public:
    int removeDuplicates(vector<int>& nums) {//time O(N), space O(1), 16ms AC.
        if(nums.empty()) return 0;
        size_t ptr1=0, ptr2=0, size = nums.size();
        bool twice = true;//current element allows twice or not
        
        while(ptr2 < size-1){
            ptr2 ++;
            if(nums[ptr2] != nums[ptr1]){//not equal
                nums[++ptr1] = nums[ptr2];
                twice = true;
            }else{//equal
                if(twice == true){//allow twice
                    nums[++ptr1] = nums[ptr2];
                    twice = false;
                }
            }
        }
        return ptr1 + 1;
    }
};
