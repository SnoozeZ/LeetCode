class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 0);
        result[0] = 1;
        for(int length = 2; length <= rowIndex+1; length++)
            for(int j = length-1; j >=0; j--){
                result[j] += (0==j? 0: result[j-1]);
            }
        return result;
    }
};