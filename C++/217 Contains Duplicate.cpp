class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        unordered_map<int, bool> exist;
        for(auto num : nums){
            if(exist.find(num) == exist.end())
                exist[num] = true;
            else
                return true;
        }
        return false;
    }
};
