//Backtracking, 48ms
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> searched(m, vector<bool>(n, false));
        bool find = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                dfs(i, j, board, word, 0, find, searched);
        }
        return find;
    }
    void dfs(int i, int j, vector<vector<char>>& board, string& word, int pos, bool& find, vector<vector<bool>>& searched){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(searched[i][j] || find || board[i][j]!=word[pos]) return;
        if(pos == word.size()-1){ 
            find = true;
            return;
        }
        searched[i][j] = true;
        
        dfs(i+1, j, board, word, pos+1, find, searched);
        dfs(i-1, j, board, word, pos+1, find, searched);
        dfs(i, j+1, board, word, pos+1, find, searched);
        dfs(i, j-1, board, word, pos+1, find, searched);
        searched[i][j] = false;
    }
};
