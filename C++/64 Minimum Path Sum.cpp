#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//Runtime at LeetCode OJ is 22 ms. Time complexity is O(n).
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		for(int i = 0; i<grid.size(); i++){
			for(int j = 0; j < grid[0].size(); j++){
				if(0 == i && 0 == j){
					continue;
				}
				if(0 == i){
					grid[i][j] += grid[i][j-1];
					continue;
				}
				if(0 == j){
					grid[i][j] += grid[i-1][j];
					continue;
				}
				grid[i][j] = min(grid[i][j]+grid[i][j-1], grid[i][j]+grid[i-1][j]);

			}
		}
		return grid[grid.size()-1][grid[0].size()-1];
    }
};

int main(){
	
	vector<vector <int> > vec;
	vector<int> vec1,vec2;
	vec1.push_back(1);
	vec1.push_back(2);
	vec2.push_back(1);
	vec2.push_back(1);

	vec.push_back(vec1);
	vec.push_back(vec2);

	Solution mySolution;
	int result = mySolution.minPathSum(vec);
	
	//cout<<result;
	system("pause");
}