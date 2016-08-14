// Two point approach.
// For each point, its water depends on the heighest block on its right and left sides.
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size(), result = 0;
        vector<int> leftMax(size, 0);
        vector<int> rightMax(size, 0);
        int curMax = 0;
        // Find left max.
        for (int i = 0; i < size; i ++) {
            leftMax[i] = curMax;
            curMax = max(height[i], curMax);
        }
        // Find right max. 
        curMax = 0;
        for (int i = size-1; i >= 0; i--) {
            rightMax[i] = curMax;
            curMax = max(curMax, height[i]);
        } 
        
        // Cal area.
        for (int i = 0; i < size; i++){
            int area = min(rightMax[i], leftMax[i]) - height[i];
            result += area>0 ? area : 0;
        }
        return result;
    }
};



