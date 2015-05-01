#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = (int)height.size();
        int result = INT_MIN, left = 0, right = size-1;
        for(;size-1>0;size--){
            result = max(result, (size-1)*min(height[left],height[right]));
            height[left] >= height[right] ? right-- : left++;
        }
        return result;
    }
};

int main(){

    Solution mySolution;
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);
    test.push_back(3);
    int rlt = mySolution.maxArea(test);
    //cout<<result;
    system("pause");
}