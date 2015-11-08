//Two pointers, time O(n^2), 56ms
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]) continue; // KEY: purning
            find(0-nums[i], i+1, nums.size()-1, nums);
        }
        return result;
    }
    
    void find(int target, int left, int right, vector<int>& nums){
        while(left < right){
                if(target > nums[left] + nums[right]){
                    left++;
                }else if(target < nums[left]+nums[right]){
                    right--;
                }else{
                    result.push_back(vector<int> ({0-target, nums[left], nums[right]}));
                    while(nums[left] == nums[left+1]) left++;   //KEY: delete duplicates
                    while(nums[right] == nums[right-1]) right--;    //KEY: delete duplicates
                    left++;
                    right--;
                }
            } 
    }
};



//Brute Force O(n^3)

//Backtracking Solution, time O(2^n), TLE
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmpVec;
        vector<vector<int>> result;
        helper(nums, 0, tmpVec, result, 0);
        return result;
        
    }
    void helper(vector<int> nums,int pos, vector<int> tmpVec, vector<vector<int>> &result, int target){
        if(tmpVec.size() == 3){
            if(target == 0){
                result.push_back(tmpVec);
                return;
            }else return;
        }
        
        for(int i = pos; i < nums.size(); i++){
            if(i>pos && nums[i] == nums[i-1]) continue; //important
            tmpVec.push_back(nums[i]);
            helper(nums, i+1, tmpVec, result, target-nums[i]);
            tmpVec.pop_back();
        }
    }
};*/

