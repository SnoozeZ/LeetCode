class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> set(nums1.begin(), nums1.end());
        for(auto num : nums2){
            if(set.find(num) != set.end()){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
