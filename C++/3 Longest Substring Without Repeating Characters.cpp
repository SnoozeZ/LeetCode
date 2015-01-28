#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <string>

using namespace std;

//The runtime at LeetCode OJ is 65ms.
//When using "simple array" to hash the number instead of "unordered_map",
//the runtime will decrease to 21ms.
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map_str;
		int size = s.size();
		int result = 0, pos_start = 0, pos_end = 0;
		
		for(int i=0; i<size; i++){
			char c_current = s[i];
			if(map_str.find(c_current) == map_str.end()
				|| map_str.find(c_current)->second < pos_start){ //not exist or not in current range
				map_str[c_current] = i;
				pos_end = i;
			}else{ //exist
				pos_start = map_str[c_current]+1;
				pos_end = i;
				map_str[c_current] = i;
			}
			int length = pos_end - pos_start+1;
			result = max(result, length);
		}
		return result;
	}
};

int main(){
	string s = "abba";
	Solution mySolution;
	int result = mySolution.lengthOfLongestSubstring(s);
	cout<<result;
	system("pause");
	
}