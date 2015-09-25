//16ms, time O(N!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rlt;
        rlt.push_back(nums);
        rSearch(rlt, nums, 0);
        return rlt;
    }
    
    void rSearch(vector<vector<int>> &rlt, vector<int> cur, int pos){
        if(pos >= cur.size()-1) return;
        rSearch(rlt, cur, pos+1);
        for(int i = pos+1; i < cur.size(); i++){
            swap(cur[pos], cur[i]);
            rlt.push_back(cur);
            rSearch(rlt, cur, pos+1);
        }
    }
};
