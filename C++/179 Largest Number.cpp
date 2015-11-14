//O(nlgn)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string rlt = "";
        for(int i : nums)
            rlt+=to_string(i);
        while(rlt.front() == '0' && rlt.size()>1) rlt.erase(0,1);
        return rlt;
    }
    
    static bool cmp(int a, int b){
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);

        return ab>ba;
    }
};
