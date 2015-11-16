ass Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) return false;
        
        set<int> set;
        for(int i =0; i < nums.size(); i++){
            if(i>k)
                set.erase(nums[i-k-1]);
            auto pos = set.lower_bound(nums[i]-t);//to find the x that satisfy x > nums[i] - t
            if(pos != set.end() && *pos - nums[i] <= t)// to find the x that satisfy nums[i] + t > x > nums[i] - t
                return true;
            set.insert(nums[i]);
        }
        return false;
    }
};
