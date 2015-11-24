class Solution {
public:
    int trailingZeroes(int n) {
        int rlt=0;
        while(n){
            rlt += n/5;
            n /= 5;
        }
        return rlt;
    }
};
