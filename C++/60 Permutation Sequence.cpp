//Backtracking, may lead to TLE.
/*
class Solution {
public:
    string getPermutation(int n, int k) {
        string rlt="", nums="";
        for(int i =1; i <= n; i++)
            nums += i+'0';
        helper(0, nums, k, rlt);
        return rlt;
    }
    
    void helper(int start, string& nums, int& k, string& rlt){
        if(k == 0) return;
        if(start == nums.size()){
            if(--k == 0)
                rlt = nums;
            return;
        }
        for(int i=start; i<nums.size(); i++){
            nums.insert(start, 1, nums[i]);//ensure the order.
            nums.erase(i+1,1);
            helper(start+1, nums, k, rlt);
            nums.insert(i+1, 1, nums[start]);
            nums.erase(start, 1);
        }
    }
};*/

//Math Solution
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n,1);
        vector<char> nums;
        string rlt;
        for(int i = 1; i < n; i++){
            factorial[i] = factorial[i-1] * i;
        }
        for(int i =1; i <= n; i++)
            nums.push_back( i+'0');
        k--;
        for(int i = n-1; i >=0; i--){
            int pos = k / factorial[i];
            rlt+= nums[pos];
            k %= factorial[i];
            nums.erase(nums.begin()+pos);
        }
        
        return rlt;
    }
};

