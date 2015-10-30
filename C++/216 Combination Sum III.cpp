//0ms, backtracking with simple pruning strategy.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(result, tmp, 1, k, n);
        
        return result;
        
    }
    
    bool dfs(vector<vector<int>> &result, vector<int> tmp, int pos, int k, int n){
        if(n < 0 ) return true; // to prune
        if(k < 0) return false;
        if(n == 0 && k == 0){
            result.push_back(tmp);
            return false;
        }
        
        for(int i = pos; i <= 9; i++){
            tmp.push_back(i);
            if(dfs(result, tmp, i+1, k-1, n-i))
                break;//prune
            tmp.pop_back();
        }
        return false;
    }
};
