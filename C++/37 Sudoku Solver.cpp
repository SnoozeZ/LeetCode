class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool success = solver(board, 0, 0);
    }
    
    bool solver(vector<vector<char>>& board, int x, int y){
        if(x > 8) return true;
        //get the next coordinate
        int next_x, next_y;
        if(y == 8){
            next_x = x + 1;
            next_y = 0;
        }else{
            next_x = x;
            next_y = y + 1;
        }
        //let's check
        if(board[x][y] != '.'){
            return solver(board, next_x, next_y);
        }else{
            for(int i = 1; i <= 9; i++){
                board[x][y] = '0' + i;
                if(isValid(board, x, y) && solver(board, next_x, next_y))
                    return true;
            }
            board[x][y] = '.';
            return false;
        }
    }
    
    bool isValid(vector<vector<char>>& board, int x, int y){
        //check row and column
        for(int i = 0; i < 9; i++){
            if(board[x][i] == board[x][y] && i != y) return false;
            if(board[i][y] == board[x][y] && i != x) return false;
        }
        //check the subbox
        int box_x = x/3*3, box_y = y/3*3;
        for(int i = box_x; i < box_x+3; i++){
            for(int j = box_y; j < box_y+3; j++){
                if(board[i][j] == board[x][y] && (i!=x || j!=y)) return false;
            }
        }
        //pass the test
        return true;
    }
};
