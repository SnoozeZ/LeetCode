//100%, time O(nlgn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        
        int n = citations.size();
        //binary search
        int left = 0, right = n;
        while(left <= right){
            int mid = (left + right)/2, count = 0;
            for(int i = 0; i < n; i++)
                if(citations[i] >= mid)
                    count++;
            if(count >= mid)
                left = mid+1;
            else
                right = mid-1;
        }
        return min(left, right);
    }
};
