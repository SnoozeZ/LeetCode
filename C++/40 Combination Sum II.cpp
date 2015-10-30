//20, O(2^N), with simple pruning strategy.
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, result, tmp, 0, target);
        
        return result;
    }
    bool dfs(vector<int> candidates, vector<vector<int>> &result, vector<int> tmp, int pos, int target){
        if(target < 0) return true; //prune: since the current element will cause a larger target, so no need to consider elements behind current element.
        if(target == 0){
            result.push_back(tmp);
            return false;
        }
        
        for(int i = pos; i < candidates.size(); i++){
            if(i > pos && candidates[i] == candidates[i-1]) continue;//eleminate dup elements
            tmp.push_back(candidates[i]);
            bool flag = dfs(candidates, result, tmp, i+1, target-candidates[i]);
            if(flag) break;//if flag == true, prune.
            tmp.pop_back();
        }
        
        return false;
        
        
    }
};
