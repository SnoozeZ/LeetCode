//Dynamic Programing, O(nlgn)
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(n+1, INT_MAX);
        nums[0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; i+j*j <= n; j++){
                nums[i+j*j] = min(nums[i+j*j], nums[i] + 1);
            }
        }
        return nums[n];
    }
};

/*
//DFS, O(2^n),TLE
class Solution {
public:
    int size;
    int numSquares(int n) {
        size = n;
        helper(n, 0);
        
        return size;
    }
    void helper(int target, int curSize){
        if(target == 0) size = min(size, curSize);
        
        for(int i = 1; i*i <= target; i ++){
            helper(target-i*i, curSize+1);
        }
    }
};*/

//Math solution
/*
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};*/

