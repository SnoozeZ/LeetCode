// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left=1, right=n;
        
        while (left <= right) {
            long median = (right + left) / 2;
            int guessResult = guess(median);
            if (guessResult == 1) {
                left = median + 1;
            } else if (guessResult == -1) {
                right = median - 1;
            } else {
                break;
            }
        }
        
        return (int) ((left+right)/2);
    }
};
