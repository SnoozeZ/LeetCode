//DFS, time O(m*n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int rlt=0, m=grid.size(), n=grid[0].size();
        
        vector<vector<bool>> searched(m, vector<bool> (n, false));
        for(int i = 0; i<m; i++){
            for(int j =0; j<n;j++){
                if(grid[i][j] == '1' && !searched[i][j]){
                    rlt++;
                    dfs(i, j, grid, searched); 
                } 
            }
        }
        return rlt;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& searched){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(searched[i][j] || grid[i][j] == '0') return;
        
        searched[i][j] = true;
        dfs(i+1, j, grid, searched);
        dfs(i, j+1, grid, searched);
        dfs(i-1, j, grid, searched);
        dfs(i, j-1, grid, searched);
    }
};


/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int result;
        for(int i=0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) result++;
                markVisited(grid, i, j, visited);
            }
        }
        return result;
    }
    
    void markVisited(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]!='1') {
            return;
        }
        visited[i][j] = true;
        markVisited(grid, i+1, j, visited);
        markVisited(grid, i-1, j, visited);
        markVisited(grid, i, j+1, visited);
        markVisited(grid, i, j-1, visited);
    }
};
*/
