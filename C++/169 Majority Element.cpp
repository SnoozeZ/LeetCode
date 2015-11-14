//time O(n)
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
};
