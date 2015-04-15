#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//Runtime at LeetCode OJ is 14 ms. Time complexity is O(n^2).
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int result = INT_MAX;
		int length = triangle.size();
		for(int i = 1; i < length; i++){
			int size = triangle[i].size();
			for(int j = 0; j < size; j++){
				if(0 == j){
					triangle[i][j] += triangle[i-1][j];	
				}else if(size -1 == j){
					triangle[i][j] += triangle[i-1][j-1];
				}else{
					triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
				}
			}
			
		}
		for(size_t i = 0; i < triangle[length-1].size(); i++){
			result = min(result, triangle[length-1][i]);
		}
		return result;
	}
};

int main(){
	
	vector<vector<int> >testVec;
	vector<int> a(1,2);
	vector<int> b(1,3);
	b.push_back(4);
	vector<int> c(1,6);
	c.push_back(5);
	c.push_back(7);
	vector<int> d(1,4);
	d.push_back(1);
	d.push_back(8);
	d.push_back(3);
	testVec.push_back(a);
	testVec.push_back(b);
	testVec.push_back(c);
	//testVec.push_back(d);

	Solution mySolution;
	int result = mySolution.minimumTotal(testVec);
	cout<<result;
	system("pause");
}