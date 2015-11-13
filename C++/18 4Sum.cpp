//24ms, O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rlt;
        if(nums.size()<4) return rlt;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        for(int i = 0; i < size-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;//handle duplicate
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//Very interesting pruning
            if(nums[i]+nums[size-1]+nums[size-2]+nums[size-3]<target) continue;//Very interesting pruning
            for(int j = i+1; j < size-2; j++){
                if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;//Very interesting pruning
                if(nums[i]+nums[size-1]+nums[size-2]+nums[size-3]<target) continue;//Very interesting pruning
                if(j>i+1 && nums[j] == nums[j-1]) continue;//handle duplicate
                int left = j+1, right = size-1;
                while(left < right){
                    int val = nums[left]+nums[right]+nums[i]+nums[j];
                    if(val > target) right--;
                    else if(val < target) left++;
                    else{
                        vector<int> tmp({nums[i], nums[j], nums[left], nums[right]});
                        rlt.push_back(tmp);
                        while(nums[left] == nums[left+1]) left++;//handle duplicate
                        while(nums[right] == nums[right-1]) right--;//handle duplicate
                        left++;
                        right--;
                    }
                }
            }
        }
        
        
     }
};
