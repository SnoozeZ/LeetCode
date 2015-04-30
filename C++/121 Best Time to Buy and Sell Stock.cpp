class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int result = INT_MIN, minPrice = prices[0];
        for(int price: prices){
            result = max(result, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return result;
    }
};