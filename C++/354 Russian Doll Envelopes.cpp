// // Simple topological sort solution. Time O(n^2), space O(n^2). Unfortunately, get TLE.
// typedef pair<int, int> Envelop;
// class Solution {
// public:
//     int maxEnvelopes(vector<pair<int, int>>& envelopes) {
//         unordered_map<int, set<int>> children;
//         unordered_map<int, int> inDegree;
//         unordered_map<int, int> distance;
//         int result = 0;
        
//         // Build the graph.
//         for(int i = 0; i < envelopes.size(); i++) {
//             inDegree[i], distance[i]=1;
//             for(int j = 0; j < envelopes.size(); j++) {
//                 if(j==i) continue;
//                 if(fit(envelopes[i], envelopes[j])) {
//                     children[i].insert(j);
//                     inDegree[j]++;
//                 }
//             }
//         }
        
//         // Do the topological sort.
//         queue<int> toSort;
//         for(auto p : inDegree) {    // init
//             if(p.second == 0) toSort.push(p.first);
//         }
//         while(!toSort.empty()) {
//             int cur = toSort.front();
//             toSort.pop();
//             result = max(result, distance[cur]);
//             for(int child : children[cur]) {
//                 inDegree[child]--;
//                 if(inDegree[child] == 0) {
//                     toSort.push(child);
//                 }
//                 distance[child] = max(distance[child], distance[cur] + 1);
//                 result = max(result, distance[child]);
//             }
//         }
        
//         return result;
//     }
    
//     bool fit(Envelop e1, Envelop e2) {
//         if(e1.first > e2.first && e1.second > e2.second) {
//             return true;
//         } else {
//             return false;
//         }
//     }
// };

// Let's try Dynamic Programing. Time O(n^2), space O(n)
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size(), result = 0;
        if(n == 0) return result;
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        
        result = 1;
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(fit(envelopes[i], envelopes[j]))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
        
    }
    
    bool fit(pair<int, int> e1, pair<int, int> e2) {
        if(e1.first > e2.first && e1.second > e2.second) {
            return true;
        } else {
            return false;
        }
    }
};

// Another O(nlgn) solution:
// https://discuss.leetcode.com/topic/47469/java-nlogn-solution-with-explanation
