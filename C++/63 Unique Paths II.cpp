#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Running time at LeetCode online judge is 9ms. No extra space.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        for(int i = 0; i<m; i++){
            for(int j = 0;j<n; j++){
                if(i == 0 && j == 0)
                    if(obstacleGrid[i][j] == 0){
                        obstacleGrid[i][j] = 1;
                        continue;
                    }
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = -1;
                    continue;
                }
                if(i-1 >= 0)
                    if(obstacleGrid[i-1][j] != -1)
                        obstacleGrid[i][j] += obstacleGrid[i-1][j];
                if(j-1 >= 0)
                    if(obstacleGrid[i][j-1] != -1)
                        obstacleGrid[i][j] += obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};

int main(){
    vector<vector<int> > obstacleGrid;
    vector<int> tmp(2,0);
    obstacleGrid.push_back(tmp);
    Solution mySolution;
    int num = mySolution.uniquePathsWithObstacles(obstacleGrid);
    system("pause");
}