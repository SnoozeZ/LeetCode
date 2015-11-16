//Sliding window solution. time O(n), space O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        unordered_map<int, bool> map;
        //for the first k numbers
        for(int i = 0; i <= k && i<nums.size(); i++){
            if(!map.count(nums[i]))
                map[nums[i]] = true;
            else
                return true;
        }
        //for the ele behind
        for(int i = k+1; i < nums.size(); i++){
            map.erase(nums[i-k-1]);
            if(!map.count(nums[i]))
                map[nums[i]] = true;
            else
                return true;
        }      
        
        return false;
    }
};
