// Just record # of marks in each row, col and diagonal. Equal n, return win.
// A good way to distinguish player1 and player2 is use n and -n.

class TicTacToe {
public:
    /** Initialize your data structure here. */
    int n;
    unordered_map<int, unordered_map<int, int>> X;
    unordered_map<int, unordered_map<int, int>> rowCount, colCount;
    TicTacToe(int n) {
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int tmp1, tmp2, tmp3, tmp4;
        tmp1 = ++rowCount[row][player];
        tmp2 = ++colCount[col][player];
        if(row == col) tmp3 = ++X[player][1];
        if(row + col == n-1) tmp4 = ++X[player][2];
        if(tmp1==n || tmp2==n || tmp3==n || tmp4==n) return player;
        return 0;
    }
    
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
