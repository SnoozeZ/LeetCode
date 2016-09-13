// Binary index tree solution.
class NumMatrix {
public:
    vector<vector<int>> BITree;
    vector<vector<int>> nums;
    int m, n;

    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size()==0) return;
        m = matrix.size();
        n = matrix[0].size();
        BITree.resize(m+1, vector<int>(n+1));
        nums.resize(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if(m==0 || n==0) return;
        int diff = val - nums[row][col];
        nums[row][col] = val;
        for(int i = row+1; i<=m; i+=i&(-i)) {
            for(int j = col+1; j<=n; j+=j&(-j)) {
                BITree[i][j] += diff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(m==0 || n==0) return 0;
        return sum(row2, col2) - sum(row1-1, col2) - sum(row2, col1-1) + sum(row1-1, col1-1);
    }
    
    int sum(int row, int col) {
        int val = 0;
        for(int i = row+1; i > 0; i-=i&(-i)) {
            for(int j = col+1; j>0; j-=j&(-j)) {
                val += BITree[i][j];
            }
        }
        return val;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
