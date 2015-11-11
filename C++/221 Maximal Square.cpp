//DP, time O(n^2), m[i, j] = min(m[i-1,j-1], m[i-1,j], m[i][j-1]) + 1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int rlt=INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sideLen(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i==0 || j==0){
                    if(matrix[i][j]=='1')
                        sideLen[i][j] = 1;
                }else{
                    if(matrix[i][j]=='1')
                        sideLen[i][j] = min(min(sideLen[i-1][j-1], sideLen[i][j-1]), sideLen[i-1][j]) + 1;
                }
                rlt = max(rlt, sideLen[i][j]);
            }
        }
        return rlt*rlt;
    }
};
