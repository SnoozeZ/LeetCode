// Notice that the power of 2 can ensure all nums in it been reachable.

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, pos=0, count=0;     // the number in range [0, mis) are reachable.
        while(miss <= n) { 
            if (pos < nums.size() && nums[pos] <= miss) {
                miss += nums[pos++];
            } else {
                count ++;
                miss += miss;
            }
            
        }
        return count;
    }
};
