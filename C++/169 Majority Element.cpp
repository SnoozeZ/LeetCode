//time O(n), space O(n)
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        for(int i : nums){
            map[i]++;
        }
        
        for(auto p : map){
            if(p.second > size/2) return p.first;
        }
    }
};*/

//time O(n), space O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int tmp = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != tmp){
                if(--count == 0){
                    tmp = nums[i];
                    count ++;
                }
            }else{
                count++;
            }
        }
        return tmp;
    }
};


