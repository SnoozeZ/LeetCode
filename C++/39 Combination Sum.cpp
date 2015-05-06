#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

//Runtime at LeetCode OJ is 22 ms. Time complexity is O(n).
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > result; 
		vector<int> myStack;
		sort(candidates.begin(), candidates.end());
		myStack.push_back(candidates.size() - 1);
		int value = candidates[myStack.back()], size = candidates.size();
		while(true){
			if(value >= target){
				if(value == target)// equal to the target
					result.push_back(myStack);
				if( (myStack.size() > 1 && 0 == myStack.front() && 0 == myStack.back()) || (1 == myStack.size() && 0 == myStack.front()))
					break;
				while( 0 == myStack.back()){// pop all the smallest
					value -= candidates[myStack.back()];
					myStack.pop_back();
				}
				value -= candidates[myStack.back()];
				myStack.back()--;
				value += candidates[myStack.back()];
			}else{
				myStack.push_back(myStack.back());//push the same one
				value += candidates[myStack.back()];
			}
		}
		for(size_t i =0; i <result.size(); i++)
			for(size_t j =0; j < result[i].size(); j++)
				result[i][j] = candidates[result[i][j]];
		for(vector<int> &tmp : result)
			reverse(tmp.begin(), tmp.end());
		return result;
	}
};

int main(){
	vector<vector <int> > vec;
	vector<int> vec1,vec2;
	vec1.push_back(2);
	vec1.push_back(4);
	vec1.push_back(3);



	Solution mySolution;
	vec = mySolution.combinationSum(vec1,12);

	//cout<<result;
	system("pause");
}