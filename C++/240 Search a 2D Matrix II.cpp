//time O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j =n-1;
        
        while(true){
            if(i>m-1 || j<0) return false;
            if(target > matrix[i][j]) i++;
            else if(target < matrix[i][j]) j--;
            else return true;
        }
    }
};
//Another O(lg(sqrt(m^2+n^2))) solution:
//Binary search from bottom right conner to top left conner, to find the possible row and column.
//Binary search in the possible row and column respectively
