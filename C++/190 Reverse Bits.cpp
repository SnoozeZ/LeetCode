class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rlt;
        for(int i = 0; i < 31; i++){
            rlt = rlt | (n&1);
            rlt = rlt<<1;
            n = n>>1;
        }
        rlt = rlt | (n&1);
        return rlt;
    }
};
