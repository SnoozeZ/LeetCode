//DP for left part and right part => Best Time to Buy and Sell Stock I
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int size = prices.size();
        vector<int> left(size+1);
        vector<int> right(size+1);
        //find the left max
        left[0] = 0;
        int minPrice = INT_MAX;
        for(int i = 1; i <= size; i++){
            minPrice = min(minPrice, prices[i-1]);
            left[i] = max(prices[i-1] - minPrice, left[i-1]);
        }
        //find the right max
        right[size] = 0;
        int maxPrice = INT_MIN;
        for(int i = size-1; i >= 0; i--){
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(maxPrice - prices[i], right[i+1]);
        }
        //find the best break point
        int rlt = INT_MIN;
        for(int i = 0; i<size;i++){
            rlt = max(rlt, left[i+1]+right[i]);
        }
        //return
        return rlt;
    }
};
