#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
	  vector<int> result;
		vector<int>::iterator vec_it;
		unordered_map<int,int> numMap;
		unordered_map <int,int> ::iterator map_it;
		int count = 1,index1,index2;
		//construct the hash map
		for(vec_it = numbers.begin(); vec_it != numbers.end(); vec_it++){
			numMap[target - *vec_it] = count++;
		}
		//find the indexes
		count = 1;
		for(vec_it = numbers.begin(); vec_it != numbers.end(); vec_it++){
			map_it = numMap.find(*vec_it);
			if(map_it != numMap.end() && map_it->second != count){
				//found the num
				index1 = count;
				result.push_back(index1);
				index2 = map_it->second;
				result.push_back(index2);
				break;
			}
			count++;
		}		
		//change the order of the result
		if(result[0]>result[1]){
			int tmp;
			tmp = result[1];
			result[1] = result[0];
			result[0] = tmp;
		};
		return result;
	}
};

int main(){
	vector<int> numbers;
	numbers.push_back(0);
	numbers.push_back(4);
	numbers.push_back(3);
	numbers.push_back(0);
	int target = 0;
	Solution mySolution;
	vector<int> result = mySolution.twoSum(numbers,target);
	cout<<result[0]<<" "<<result[1]<<endl;
	system("pause");
	
}