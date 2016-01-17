//classical BackTracking
class Solution {
public:
    int totalNQueens(int n) {
        string tmp="";
        for(int i = 0; i < n; i ++) tmp += ".";
        vector<string> board(n, tmp);
        int rlt = 0;
        dfs(board, 0, rlt);
        return rlt;
    }
    
    void dfs(vector<string>& board, int row, int& rlt){
        //success
        if(row >= board.size()){
            rlt++;
            return;
        }
        //find 
        for(int col = 0; col < board.size(); col++){
            board[row][col] = 'Q';
            if(isValid(board, row, col))
                dfs(board, row+1, rlt);
            board[row][col] = '.';
        }
        return;
    }

    bool isValid(vector<string>& board, int x, int y){
        //check column and row
        for(int i = 0; i < board.size(); i++){
            //if(board[x][i] == 'Q' && i != y) return false;
            if(board[i][y] == 'Q' && i != x) return false;
        }
        //check diagonal
        for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = x - 1, j = y + 1; j < board.size() && i >= 0; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};
