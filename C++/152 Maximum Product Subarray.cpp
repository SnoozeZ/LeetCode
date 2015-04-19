#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int result = nums[0], minInt = nums[0], maxInt = nums[0];
        for(size_t i = 1; i <nums.size(); i++){
            int minTmp = minInt;
            minInt = min(nums[i],min(minInt*nums[i], maxInt*nums[i]));
            maxInt = max(nums[i],max(minTmp*nums[i], maxInt*nums[i]));
            result = max(maxInt, result);
        }
        return result;
    }
};

int main(){

    Solution mySolution;
    int array[2] = {2,3};
    vector<int> test(array, array+2);
    int rlt = mySolution.maxProduct(test);
    //cout<<result;
    system("pause");
}