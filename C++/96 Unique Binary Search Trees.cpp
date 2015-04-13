#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Running time at LeetCode online judge is 1ms. 
class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1,0);
        num[0] = num[1] = 1;
        for(int i =2;i<n+1;i++){
            for(int j=0;j<n;j++)
                num[i] += num[j]*num[i-1-j];
        }
        return num[n];

    }
};

int main(){
    Solution mySolution;
    int num = mySolution.numTrees(3);
    cout<<num;
    system("pause");
}