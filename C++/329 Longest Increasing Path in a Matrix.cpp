// Use DFS + DP(Memoization), DFS meanwhile record the longest lenth of current grid.
// This problem can also be solved by topological sort.

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int m = matrix.size(), n = matrix[0].size(), result=0;
        vector<vector<int>> longest(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, helper(matrix, longest, i, j));
            }
        }
        return result;
    }
    
    int helper(vector<vector<int>> &matrix, vector<vector<int>> &longest, int i, int j) {
        int m = longest.size(), n = longest[0].size();
        if (longest[i][j] != 0) {
            return longest[i][j];
        }
        
        if (i>0 && matrix[i][j] > matrix[i-1][j]) {
            longest[i][j] = max(longest[i][j], helper(matrix, longest, i-1, j) + 1);
        }
        
        if (j>0 && matrix[i][j] > matrix[i][j-1]) {
            longest[i][j] = max(longest[i][j], helper(matrix, longest, i, j-1) + 1);
        }
        
        if (j < n-1&& matrix[i][j] > matrix[i][j+1]) {
            longest[i][j] = max(longest[i][j], helper(matrix, longest, i, j+1) + 1);
        }
        
        if (i < m-1 && matrix[i][j] > matrix[i+1][j]) {
            longest[i][j] = max(longest[i][j], helper(matrix, longest, i+1, j) + 1);
        }
        
        if (longest[i][j] == 0) {
            longest[i][j] = 1;
        }
        
        return longest[i][j];
    }
};
