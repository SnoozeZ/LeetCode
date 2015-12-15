class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<char, bool> checkX;
            unordered_map<char, bool> checkY;
            for(int j =0; j < 9; j++){
                if(board[j][i]!='.' && checkX[board[j][i]])
                    return false;
                checkX[board[j][i]] = true;
                if(board[i][j]!='.' && checkY[board[i][j]])
                    return false;
                checkY[board[i][j]] = true;
            }
        }
        
        for(int i = 0; i <9; i+=3){
            for(int j = 0; j < 9; j+=3){
                unordered_map<char, bool> check;
                for(int ii = i; ii < i+3; ii++){
                    for(int jj = j; jj < j+3; jj++){
                        if(board[ii][jj]!='.' && check[board[ii][jj]])
                            return false;
                        check[board[ii][jj]] = true;
                    }
                }
            }
        }
        
        return true;
    }
    

};
