class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int rlt = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            find(nums, i+1, nums.size()-1, target-nums[i], rlt);
        }
        return rlt;
        
    }
    
    void find(vector<int> nums, int left, int right, int target, int& rlt){
        while(left < right){
            if(nums[left] + nums[right] >= target){
                right--;
            }else{
                rlt += right - left;
                left++;
            }
        }
    }
};
