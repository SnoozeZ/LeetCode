//O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first, second;
        for(first = nums.size()-2; first >=0; first--)
            if(nums[first] < nums[first+1]) break;
        for(second = nums.size()-1; second>=first; second--)
            if(nums[second] > nums[first]) break;
            
        if(first == -1)
            sort(nums.begin(), nums.end());
        else{
            swap(nums[first], nums[second]);
            sort(nums.begin()+first+1, nums.end());
        }
    }
};
