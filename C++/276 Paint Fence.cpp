class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        vector<int> ways(n);
        ways[0] = k;
        ways[1] = k*k;
        
        for(int i = 2; i < n; i++){
            ways[i] = ways[i-1]*(k-1) + ways[i-2]*(k-1);
        }
        return ways[n-1];
    }
};
