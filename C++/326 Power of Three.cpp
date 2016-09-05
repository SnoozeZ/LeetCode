// // Naive, TLE.
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         int tmp = 1;
//         while(tmp < n) {
//             tmp = tmp * 3;
//         }
        
//         return tmp == n;
//     }
// };

// Just use the largest 3's power to mod 3....... 
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && ((int)pow(3, 19)%n==0);
    }
};


