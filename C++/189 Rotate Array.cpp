/*
//time O(N), space O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int size = nums.size();
        vector<int> rlt(nums.size(), 0);
        for(int i= 0; i < size-k; i++){
            rlt[i+k] = nums[i];
        }
        for(int i = 0; i < k; i++){
            rlt[i] = nums[size-k+i];
        }
        nums = rlt;
    }
};*/

/*
//time O(N^2), space O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int size = nums.size();
        while(k--){
            int tmp = nums[size-1];
            for(int i = size-1; i>0; i--){
                nums[i] = nums[i-1];
            }
            nums[0] = tmp;
        }
    }
};*/

//time O(N), space O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        reverse(nums, size-k, size-1);
        reverse(nums, 0, size-k-1);
        reverse(nums, 0, size-1);
    }
    void reverse(vector<int>& nums, int i, int j){
        while(i<j){
            swap(nums[i++], nums[j--]);
        }
    }
};

