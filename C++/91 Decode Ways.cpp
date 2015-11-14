//DP, O(n)
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(s[0]<'1') return 0;
        
        vector<int> nums(s.size()+1, 0);
        nums[1] = 1;
        nums[0] = 1;
        
        for(int i =1; i < size; i++){
            
            int tmp = (s[i-1]-'0')*10 + s[i]-'0';
            if(tmp>9 && tmp<27)
                nums[i+1] += nums[i-1];
            if(s[i]!='0'){
                nums[i+1] += nums[i];
            }
            if(nums[i+1] == 0)return 0;
        }
        return nums[size];
    }
};
