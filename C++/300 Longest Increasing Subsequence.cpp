//DP, O(n^2), 116ms
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size(), rlt = 0;
        if(size == 0) return rlt;
        
        vector<int> m(size, 1);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    m[i] = max(m[i], m[j]+1);
            }
        }
        for(auto i : m){
            rlt = max(rlt,i);
        }
        return rlt;
    }
};
//another interesting O(nlgn) solution: use a "ladder" to help binary search:
//https://leetcode.com/discuss/67687/c-o-nlogn-solution-with-explainations-4ms
