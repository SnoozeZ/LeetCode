//84ms, time O(mn), space O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size(), n = matrix[0].size();
        
        unordered_map<int, bool> row;
        unordered_map<int, bool> col;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                    continue;
                }
            }
        }
        //set matrix zeroes
        for(auto tmpPair : row){
            if(tmpPair.second)
                for(int i = 0; i < n; i++)
                    matrix[tmpPair.first][i] = 0;
        }
        for(auto tmpPair : col){
            if(tmpPair.second)
                for(int i = 0; i < m; i++)
                    matrix[i][tmpPair.first] = 0;
        }

    }
};
