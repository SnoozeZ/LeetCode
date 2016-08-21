// // Heap, time O(n^2 logk), space O(k)
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> minHeap;
//         for(auto vec : matrix) {
//             for (int num : vec) {
//                 if(minHeap.size()<=k || minHeap.top() > num)
//                     minHeap.push(num);
//                 if(minHeap.size() > k) 
//                     minHeap.pop();
//             }
//         }
//         return minHeap.top();
//     }
// };

// Binary Seaerch, O(nlogn^2) time and O(1) space
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        long left = matrix[0][0], right = matrix[n-1][n-1];
        // We have to wait until left > right
        while (left <= right) {
            long tmp = (left + right) / 2;
            int median = (int)tmp;
            int pos = calPos(matrix, median);
            if (k > pos) {
                left = median+1;
            } else {
                right = median-1; // It's right when equal. So return left
            }
        }
        return left;
    }
    
    int calPos(vector<vector<int>>& matrix, int num) {
        int n = matrix.size(), count = 0;
        int i = n-1, j = 0;
        while (i>=0 && j<n) {
            if(matrix[i][j] > num) {
                i--;
            } else {
                count += (i+1);
                j++;
            }
        }
        return count;
    }
};
