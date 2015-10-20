//A math solution, another observation solution: for n = k, append 0 in the front of n = k-1, append 1 in the front of n = k-1 and reverse the order of them.
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rlt;
        size_t size = pow(2,n);
        
        for(int i = 0; i < size; i++){
            rlt.push_back( (i>>1)^i );//Please remember this formula.
        }
        return rlt;
        
    }
};
