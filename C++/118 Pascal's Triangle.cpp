class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(0 == numRows) return vector<vector<int> >(0);
        vector<vector<int> > result(1,vector<int>(1,1));
        for(int length = 2; length <= numRows; length++){
            vector<int> tmpVec(length,-1);
            for(int j =0; j < length; j++){
                int valLeft = (0==j? 0: result[length-2][j-1]);
                int valRight = (length-1==j? 0: result[length-2][j]);
                tmpVec[j] = valLeft + valRight;
            }
            result.push_back(tmpVec);
        }
        return result;
    }
};