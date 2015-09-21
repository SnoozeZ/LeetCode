/*
//(Bad)Bit Manipulation Solution 1, 188ms, time O(N), space O(1)  
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int rlt=0, back=findMax(nums);
        
        if(nums.size() == 1 && nums.front() == 1) return 0;
        if(nums.size()-1 == back) return back+1;
        
        for(auto num : nums){
            rlt ^= num;
        }
        for(int i=back+1; i < findFloor(back); i++){
            rlt ^= i;
        }
        return rlt;
    }
    
    int findMax(vector<int>& nums){
        int max = INT_MIN;
        for(auto num : nums){
            if (num > max) max = num;
        }
        return max;
    }
    
    int findFloor(int num){
        int tmp = 1;
        while(num >= pow(2,tmp)){
            tmp++;
        }
        return pow(2,tmp);
    }
};
*/


//(Good)Bit Manipulation Solution 1, 32ms, time O(N), space O(1)  
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int rlt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            rlt ^= nums[i];
            rlt ^= i;
        }
        rlt ^= nums.size();
        
        return rlt;
    }

};

/*
//Math Equation Solution, 36ms, time O(N), space O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for(auto num : nums){
            sum += num;
        }
        
        return size*(size+1)/2 - sum;
        
    }

};
*/

