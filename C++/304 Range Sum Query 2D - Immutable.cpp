// Easy DP
class NumMatrix {
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        preSum.resize(m, vector<int>(n, 0));
        // Init
        int tmp=0;
        for(int i = 0; i < m; i++) {
            preSum[i][0] = matrix[i][0] + tmp;
            tmp += matrix[i][0];
        }
        tmp = 0;
        for(int j = 0; j<n;j++) {
            preSum[0][j] = matrix[0][j] + tmp;
            tmp += matrix[0][j];
        }
        // DP
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(preSum.size() == 0) return 0;
        if(row1 == 0)
            return preSum[row2][col2] - preSum[row2][col1-1];
        if(col1 == 0)
            return preSum[row2][col2] - preSum[row1-1][col2];
        return preSum[row2][col2] - preSum[row1-1][col2] - preSum[row2][col1-1] + preSum[row1-1][col1-1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
