// https://discuss.leetcode.com/topic/6079/accepted-cpp-solution-with-explainations
class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        string result = "";
        
        if(numerator == 0) return "0";   // =0
        
        if(numerator < 0 ^ denominator < 0) result += "-";   // Sign.
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        // Integral part
        result += to_string(numerator / denominator);
        if(numerator % denominator == 0) return result;
        result+=".";
        
        // After .
        unordered_map<long, long> numPos;
        while (true) {
            long reminder = numerator % denominator;
            if(reminder == 0) break;
            if(numPos.count(reminder)) {
                result.insert(numPos[reminder], "(");
                result += ")";
                break;
            } else {
                numPos[reminder] = result.size();
                numerator = reminder * 10;
                result += to_string(numerator / denominator);
            }
        }
        
        return result;
    }
};
