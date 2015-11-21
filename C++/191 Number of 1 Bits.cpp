class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 1 & n;
        for(int i =0; i < 31; i++){
            n = n>>1;
            count += n&1;
        }
        return count;
    }
};
