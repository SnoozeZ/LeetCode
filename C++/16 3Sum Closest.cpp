//Two Pointer, time O(n^2)
class Solution {
public:
    int result;
    int minDiff;
    int threeSumClosest(vector<int>& nums, int target) {
        minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i =0; i < size; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1, right = size-1;
            while(left<right){
                int cur = nums[left]+nums[right]+nums[i];
                result = minDiff>abs(cur-target) ? (cur) : result;
                minDiff = min(abs(cur-target), minDiff);
                //opt, Why doesn't work?
                //while(left+1<right && nums[left] == nums[left+1]) left++; 
                //while(left+2<right && nums[right] == nums[right-1]) right--;
                if(cur-target > 0) right--;
                else if(cur-target < 0) left++;
                else{return result;}
            }
        }
        return result;
    }
};
