// time O(log(m) + log(n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        if(target < matrix[0][0]) return false;// important!
        size_t m = matrix.size()-1, n = matrix[0].size()-1;
        int right, left; 
        // find the row
        left = 0, right = m;
        while(left <= right){
            int mid = (left + right)/2;
            if(matrix[mid][0] > target) 
                right = mid-1;
            else if(matrix[mid][0] < target)
                left = mid+1;
            else 
                return true;
        }
        int row = min(left, right);
        //find the col
        left = 0;
        right = n;
        while(left <= right){
            int mid = (left + right)/2;
            if(matrix[row][mid] > target)
                right = mid -1;
            else if(matrix[row][mid] < target)
                left = mid + 1;
            else 
                return true;
        }
        //
        return false;
    }
};
