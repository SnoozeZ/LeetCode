//8ms, time O(2^N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, result, tmp, 0);
        
        return result;
    }
    
    void dfs(vector<int> nums, vector<vector<int>> &result, vector<int> tmp, int pos){
        result.push_back(tmp);
        
        for(int i = pos; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            dfs(nums, result, tmp, i+1);
            tmp.pop_back();
        }
    }
};

//Another simple solution is to use bit manipulation
