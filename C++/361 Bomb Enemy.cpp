// 0100
// 1101
// 1

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp1(m, vector<int>(n, 0)), dp2=dp1, dp3=dp1, dp4=dp1;
        // Top->down
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                dp1[i][j] += (i-1>=0 && grid[i][j]!='W') ? dp1[i-1][j] : 0;
                dp1[i][j] += grid[i][j]=='E' ? 1 : 0;
            }
        }
        // left->right
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                dp2[i][j] += (j-1>=0 && grid[i][j]!='W') ? dp2[i][j-1] : 0;
                dp2[i][j] += grid[i][j]=='E' ? 1 : 0;
            }
        }
        // right->left
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                dp3[i][j] += (i+1<m && grid[i][j]!='W') ? dp3[i+1][j] : 0;
                dp3[i][j] += grid[i][j]=='E' ? 1 : 0;
            }
        }
        
        // Bottom->top
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                dp4[i][j] += (j+1<n && grid[i][j]!='W') ? dp4[i][j+1] : 0;
                dp4[i][j] += grid[i][j]=='E' ? 1 : 0; 
            }
        }
        
        return helper(dp1, dp2, dp3, dp4, grid);
        
    }
    
    int helper(vector<vector<int>> &dp1, vector<vector<int>> &dp2, vector<vector<int>> &dp3, vector<vector<int>> &dp4, vector<vector<char>> &grid) {
            int maxEnemy = 0;
            for(int i=0; i < dp1.size(); i++){
                for(int j=0; j < dp1[0].size(); j++){
                    if (grid[i][j] == 'E') continue;
                    maxEnemy = max(maxEnemy, dp1[i][j] + dp2[i][j] + dp3[i][j] + dp4[i][j]);
                }
            }
            return maxEnemy;
        }
        
};
