#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int result = INT_MIN;
        vector<int> tmpVec(nums.size(),-1);
        for(int i = 0; i <nums.size(); i++){
            if(0 == i)
                tmpVec[0] = nums[0];
            else
                tmpVec[i] = max(tmpVec[i-1] + nums[i], nums[i]);
            result = tmpVec[i] > result ? tmpVec[i] : result;
        }
        return result;
    }
};

int main(){
    Solution mySolution;
    int array[9] = {-2,1,-3,-1000,10011,2,1,-5,4};
    vector<int> test(array, array+9);
    int rlt = mySolution.maxSubArray(test);
    //cout<<result;
    system("pause");
}