/*class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int tmp = 0;
        while(n!=0){
            tmp += 1&n;
            n = n>>1;
        }
        return tmp==1;
    }
};*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1)); 
        //n&(n-1) is the last bit position with '1'. If its 'not' is zero, there is only one '1'
    }
};
