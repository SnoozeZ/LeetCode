//Heap solution, 4ms, O(klgn)
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        int i = 0;
        for(; i < k; i ++)
            pop_heap(nums.begin(), nums.end()-i);
        return *(nums.end()-i);
    }
};*/

//Partition Solution, 4ms, O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        find(nums, 0, nums.size()-1, k);
    }
    
    int find(vector<int>& nums, int left, int right, int k){
        if(left == right)
            return nums[left];
        int q = partition(nums, left, right);
        int pos = q - left + 1;
        if(pos == k)
            return nums[q];
        else if(pos > k)
            return find(nums, left, q-1, k);
        else
            return find(nums, q+1, right, k-pos);
        
    }
    
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int i = left-1;
        for(int j = left; j<right; j++){
            if(nums[j] > pivot){
                i++;
                swap(nums, i, j);
            }
        }
        swap(nums, i+1, right);
        return i+1;
    }
    
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
