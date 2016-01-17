//classical BackTracking
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string tmp="";
        for(int i = 0; i < n; i ++) tmp += ".";
        vector<string> board(n, tmp);
        vector<vector<string>> rlt;
        dfs(board, 0, rlt);
        return rlt;
    }
    
    void dfs(vector<string>& board, int row, vector<vector<string>>& rlt){
        //success
        if(row >= board.size()){
            vector<string> tmp = board;
            rlt.push_back(tmp);
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

//Permutation solution (TLE)
class Solution2 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> tmpRlt;
        vector<vector<string>> rlt;
        vector<int> cur;
        for(int i = 0; i < n; i++){
            cur.push_back(i);
        }
        dfs(cur, tmpRlt, 0);
        
        //contruct result
        for(auto tmp : tmpRlt){
            rlt.push_back(construct(tmp));
        }
        return rlt;
        
    }
    
    void dfs(vector<int>& cur, vector<vector<int>>& rlt, int pos){
        //success
        if(isValid(cur)){
            rlt.push_back(cur);
            return;
        }
        //dfs!
        for(int i = pos; i < cur.size(); i++){
            swap(cur[pos], cur[i]);
            dfs(cur, rlt, pos+1);
            swap(cur[pos], cur[i]);
        }
        return;
    }
    
    bool isValid(vector<int> cur){
        for(int i = 0; i < cur.size(); i++){
            for(int j = i+1; j < cur.size(); j++){
                if(cur[i] == cur[j] + (j-i)) return false;
                if(cur[i] == cur[j] - (j-i)) return false;
            }
        }
        return true;
    }
    
    vector<string> construct(vector<int> tmp){
        int size = tmp.size();
        vector<string> rlt(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(tmp[i] == j)
                    rlt[i] += 'Q';
                else
                    rlt[i] += '.';
            }
        }
        return rlt;
    }
    
};



