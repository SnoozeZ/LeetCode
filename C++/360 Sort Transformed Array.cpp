// Two pointers, from start and end to middle.
// Each step has two possible situation: a > 0 or a < 0.
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        deque<int> res;
        int left=0, right=nums.size()-1; // Two pointers.
        while(left <= right) {
            int leftVal = calFunc(a,b,c,nums[left]);
            int rightVal = calFunc(a,b,c,nums[right]);
            if(leftVal < rightVal) {
                if(a > 0){
                    res.push_front(rightVal);
                    right --;
                }
                else {
                    res.push_back(leftVal);
                    left++;
                }
            } else {
                if(a > 0){
                    res.push_front(leftVal);
                    left++;
                }
                else {
                    res.push_back(rightVal);
                    right--;
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    
    int calFunc(int a, int b, int c, int val){
        return a*val*val + b*val + c;
    }
};
