class Solution {
public:
    void sortColorsOld(vector<int>& nums) {//two-pass solution, time: O(N), space: O(N), 4ms
        vector<int> tmpVec(3,0);
        for(int i : nums){
            tmpVec[i] ++;
        }
        nums.clear();
        int color = 0;
        for(int i : tmpVec){
            for(int j = 0; j < i; j++){
                nums.push_back(color);
            }
            color ++;
        }
    }

    void sortColors(vector<int>& nums) {//one-pass solution, time: O(N), space: O(1), 4ms
        int ptr1=-1, ptr2=-1, index=0;
        for(int i : nums){
            if(2 == i){
                //do nothing
            }
            if(1 == i){
                if(-1 == ptr2) ptr2 = ptr1; //if it is the first '1'
                swap(nums[++ptr2], nums[index]);
            }
            if(0 == i){
                swap(nums[++ptr1], nums[index]);
                if(ptr2 != -1) //if these is no '1'
                    swap(nums[++ptr2], nums[index]);
            }
            index++;
        }
    }

};
