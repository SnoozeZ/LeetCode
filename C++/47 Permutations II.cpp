//Backtracking, adopt a map to eliminate the duplicate situation.
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         map<int, int> countMap;
//         for(int i:nums) countMap[i]++;
//         vector<int> cur;
//         vector<vector<int>> rlt;
//         helper(nums, cur, rlt, countMap);
//         return rlt;
        
//     }
    
//     void helper(vector<int>& nums, vector<int> &cur, vector<vector<int>> &rlt, map<int,int> &countMap){
//         if(cur.size()==nums.size()){
//             rlt.push_back(cur);
//             return;
//         }
        
//         for(auto &m : countMap){
//             if(m.second<=0) continue;
//             m.second--;
//             cur.push_back(m.first);
//             helper(nums, cur, rlt, countMap);
//             cur.pop_back();
//             m.second++;
//         }
        
//     }
// };

// Better solution.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(nums.size() == 0) return result;
        dfs(result, nums, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int> nums, int start) {
        if(start == nums.size()) {
            result.push_back(nums);
        } else {
            for(int i = start; i < nums.size(); i++) {
                if(i!=start and nums[i]==nums[start]) continue;
                swap(nums[i], nums[start]);
                dfs(result, nums, start+1);
            }
        }
    }
};

