//60ms, time O(n), space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        
        int tmp=1;
        for(int i = 0; i < nums.size()-1; i++){
            tmp *= nums[i];
            output[i+1] = tmp;
        }
        
        tmp = 1;
        for(int i = nums.size()-1; i > 0; i--){
            tmp *= nums[i];
            output[i-1] *= tmp;
        }
        
        return output;
    }
    
};
