// List "Merge Sorted List".

typedef pair<int, int> Info;    // First: next product value, second: the prime position.

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(1,1);
        vector<int> primePos(primes.size(), 0); // Kind of "merge sorted list", it record pos of each "list".
        priority_queue<Info, vector<Info>, greater<Info>> minHeap;
        for(int i = 0; i < primes.size(); i++) minHeap.push({primes[i], i});    // Init.
        for(int i = 0; i < n; i++) {
            Info top = minHeap.top();
            minHeap.pop();
            // Check Duplicate.
            if(top.first != ugly.back())
                ugly.push_back(top.first);
            else 
                i--;
            // Add next potential prime.
            int nextPrime = ugly[++primePos[top.second]] * primes[top.second];
            minHeap.push({nextPrime, top.second});
        }
        return ugly[n-1];
    }
};
