//time O(N), 4ms
//Another simple O(NlgN) solution is to use binary search
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        size_t size = nums.size(), left=0, right = 0;
        size_t minSize = INT_MAX, sum=0;
        while(right < size){
            sum += nums[right++];
            if(sum >= s){
                while(sum >= s && left < right){
                    sum -= nums[left++];
                    minSize = min(minSize, right - left +1);
                }
            }
        }
        
        return minSize == INT_MAX? 0 : minSize;
    }
};
