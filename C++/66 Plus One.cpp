class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i = digits.size()-1; i>=0; i--){
            int cur = digits[i] + carry;
            carry = cur/10;
            digits[i] = cur%10;
        }
        if(carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
