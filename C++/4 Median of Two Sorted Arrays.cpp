#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

double func(int A[], int B[], int m, int n, int k){
	if(m>n){//let A's size smaller than B's.
		return func(B , A, n, m, k);
	}
	if(0 == m){//A is empty, return the k th smaller of B.
		return B[k-1];
	}
	if(1 == k){//k is 1, so return the smaller one of the first number of A and B. 
		return min(A[0],B[0]);
	}
	//recursively find the k th small number
	int pos_A = min(k/2, m);
	int pos_B = k - pos_A;
	if(A[pos_A - 1] < B[pos_B - 1]){
		return func(A+pos_A, B, m-pos_A, n, k-pos_A);
	}else if(A[pos_A - 1] > B[pos_B - 1]){
		return func(A, B+pos_B, m, n-pos_B, k-pos_B);
	}else{// A[pos_A - 1] == B[pos_B - 1], so they are the k th small number, and return one of them.
		return B[pos_B-1];
	}

}

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m+n;
		if(total & 1){//odd
			return func(A, B, m, n, total/2+1);
		}else{
			return (func(A, B, m, n, total/2) + func(A, B, m, n, total/2+1))/2;
		}
	}
};

int main(){
	int A[4] = {1,2,3,4};
	int B[4] = {7,7,8,8};
	Solution S;
	double result = S.findMedianSortedArrays(A,4,B,4);
	cout<<result;
	system("pause");

	
}