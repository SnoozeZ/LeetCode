//Naive DP without space improvement. Easy to understand.
//Four states at a day: sell, buy, keep(noOp), wait(cool)
//Transform functions:
// noOp[i] = max(noOp[i-1], buy[i-1]);// choose buy when i = 1
// buy[i] = cool[i-1] - priceToday;
// cool[i] = max(sell[i-1], cool[i-1]);
// sell[i] = max(buy[i-1], noOp[i-1]) + priceToday;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(n+1), buy(n+1), cool(n+1), noOp(n+1);
        
        buy[0] = INT_MIN, noOp[0] = INT_MIN; // cool
        
        for(int i = 1; i <= n; i++){
            int priceToday = prices[i-1];
            noOp[i] = max(noOp[i-1], buy[i-1]);// choose buy when i = 1
            buy[i] = cool[i-1] - priceToday;
            cool[i] = max(sell[i-1], cool[i-1]);
            sell[i] = max(buy[i-1], noOp[i-1]) + priceToday; // small enough when i = 1
        }
        
        return max(cool.back(), sell.back());
    }
};
