
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curSolution;
        
        DFS(result, curSolution, 1, n, k);
        return result;
        
    }
    
    void DFS(vector<vector<int>> &result, vector<int> curSolution, int cur, int n, int k){
        if(0 == k){ // for bad solution: k == curSolution.size(); 
            result.push_back(curSolution);
            return;
        }
        /*bad solution
        for(int i = cur; i <= n; i++){
            curSolution.push_back(i);
            DFS(result, curSolution, i+1, n, k);
            curSolution.pop_back();
        }*/
        
        for(int i = cur; i <= n-k+1; i++){
            curSolution.push_back(i);
            DFS(result, curSolution, i+1, n, k-1);
            curSolution.pop_back();
        }
        
        return;
    }
};



