class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> rlt;
        if(nums.empty()){//handle empty
            rlt.push_back(createRange(lower, upper));
            return rlt;
        }
        if(nums[0] > lower) rlt.push_back(createRange(lower, nums[0]-1));//handle left bound
        
        for(int i = 0; i < nums.size()-1; i++){//handle interior
            if(nums[i]+1 == nums[i+1])
                continue;
            else 
                rlt.push_back(createRange(nums[i]+1, nums[i+1]-1));
        }
        
        if(nums.back() < upper) rlt.push_back(createRange(nums.back()+1, upper));//handle right bound
        
        return rlt;
    }
    
    string createRange(int left, int right){
        if(left == right)
            return to_string(left);
        else
            return to_string(left) + "->" + to_string(right);
    }
};
