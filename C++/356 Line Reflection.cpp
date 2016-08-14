// The left-most point must reflect with the right-most one. Find them and check. O(n) time and O(n) space
// Use sort: 1. sort all in ascending order; 2. sort second half in decending order and check. O(nlgn) time and O(1) space.
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int minX = INT_MAX, maxX = INT_MIN;
        unordered_map<int, unordered_map<int, bool>> allPoints;
        for (auto p : points) {
            allPoints[p.first][p.second] = true;
            minX = min(minX, p.first);
            maxX = max(maxX, p.first);
        }
        double median = (minX + maxX) / 2.0;
        
        // loop to check
        for(auto p: points) {
            int reflectX = (int) (median*2 - p.first);
            if (allPoints[reflectX][p.second]) { // Check reflect exist or not.
                continue;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
