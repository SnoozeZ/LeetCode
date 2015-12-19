class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        size_t p1=0, p2=0;
        vector<string> rlt;
        while(p2<nums.size()){
            while(p2<nums.size()-1 && nums[p2]+1 == nums[p2+1]){
                p2++;
            }
            if(p2>p1)
                rlt.push_back(to_string(nums[p1])+"->"+to_string(nums[p2]));
            else
                rlt.push_back(to_string(nums[p1]));
            p1 = ++p2;
        }
        return rlt;
        
    }
};
