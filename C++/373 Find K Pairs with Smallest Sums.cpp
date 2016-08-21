// Interesting! 
// 1. Only need to check first k numbers both in nums1 and nums2;
// 2. Can be transformed into merge k sorted arrays problem. (https://discuss.leetcode.com/topic/50529/java-9ms-heap-queue-solution-k-log-k/2)
// Time O(klogk). Space O(k)

typedef pair<int, pair<int, int>> Info; // (sum, idx1, idx2)

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Info, vector<Info>, greater<Info>> minHeap;
        vector<pair<int, int>> result;
        if(nums1.empty() || nums2.empty()) return result;
        // Init
        for(int i = 0; i < nums1.size(); i++) {
            int sumVal = nums1[i] + nums2[0];
            minHeap.push(make_pair(sumVal, make_pair(i, 0)));
        }
        
        // Do
        int maxSize = nums1.size()*nums2.size();
        while(result.size() != min(k, maxSize)) {
            Info top = minHeap.top();
            minHeap.pop();
            int idx1 = top.second.first, idx2 = top.second.second;
            result.push_back(make_pair(nums1[idx1], nums2[idx2]));
            
            // Push new
            if (idx2 == nums2.size()-1) continue;
            int valSum = nums1[idx1] + nums2[idx2+1];
            minHeap.push(make_pair(valSum, make_pair(idx1, idx2+1)));
        }
        
        return result; 
    }
};
