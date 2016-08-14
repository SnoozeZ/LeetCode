// DFS backtracking.
// This kind of problems, use a map or something to hardcode the necessary infomation.

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int totalCount = 0;
        int result = 0;
        unordered_map<int, unordered_map<int, int>> jump;
        unordered_map<int, bool> marked;
        // the block map;
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[7][9] = jump[9][7] = 8;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[4][6] = jump[6][4] = 5;
        jump[2][8] = jump[8][2] = jump[3][7] = jump[7][3] = 5;
        
        for(auto num : vector<int>({1,2,5})) {
            int tmp = helper(num, m, n, 1, marked, totalCount, jump);
            totalCount = 0;
            if(num == 1 || num == 2) result += 4*tmp;
            else result += tmp;
        }
        
        return result;
    }
    
    
    int helper(int current, int& m, int& n, int length, unordered_map<int, bool>& marked, int& count, unordered_map<int, unordered_map<int, int>>& jump) {
        if (length > n) return count;
        if(length >= m && length <= n) count++;
        
        marked[current] = true;
        for (int i = 1; i<=9; i++) {
            if(marked[i]) continue;
            if(jump[current][i]==0 || marked[jump[current][i]]) {
                helper(i, m, n, length+1, marked, count, jump);
            }
        }
        marked[current] = false;
        return count;
    }
        
};
