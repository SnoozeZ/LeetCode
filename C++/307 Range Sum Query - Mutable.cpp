class NumArray {
public:
    int n;
    vector<int> BITree, nums;
    NumArray(vector<int> &nums) {
        n = nums.size();
        this->nums = nums;
        BITree.resize(n+1, 0);
        // Init
        for(int i = 0; i < nums.size(); i++) {
            init(i, nums[i]);
        }
        
    }

    void init(int i, int val) {
        int index = i + 1;
        while(index <= n) {
            BITree[index] += val;
            index += index&(-index);
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i] = val;
        init(i, diff);
    }
    
    int sum(int i) {
        int index = i+1, val = 0;
        while(index > 0) {
            val += BITree[index];
            index -= index&(-index);
        }
        return val;
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
