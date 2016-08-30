class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        helper(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, result);
        return result;
    }
    
    void helper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>& result) {
        if(x1>x2 || y1>y2) return;
        
        for(int i = y1; i <= y2; i++) {
            result.push_back(matrix[x1][i]);
        }
        
        for(int i = x1+1; i<=x2; i++) {
            result.push_back(matrix[i][y2]);
        }
        
        for(int i = y2-1; i>=y1; i--) {
            if (x2 <= x1) break;
            result.push_back(matrix[x2][i]);
        }
        
        for(int i = x2-1; i>x1; i--) {
            if(y2 <= y1) break;
            result.push_back(matrix[i][y1]);
        }
        helper(matrix, x1+1, y1+1, x2-1, y2-1, result);
    }
};
