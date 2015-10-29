//O(lgN)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        
        int size = citations.size();
        int left = 0, right = size;
        int mid;
        //binary search 
        while(left <= right){
            mid = (left + right)/2;
            int remain = size - mid;
            if(left == right) return remain;
            if(citations[mid] >= remain)
                right = mid;
            else
                left = mid + 1;
        }
        
    }
};
