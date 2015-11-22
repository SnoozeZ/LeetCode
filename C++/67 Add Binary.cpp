class Solution {
public:
    string addBinary(string a, string b) {
        string rlt = "";
        int carry = 0;
        for(int i = 0; i < a.size() || i < b.size(); i++){
            int bitA = (i>=a.size())? 0 : a[a.size()-1-i] - '0';
            int bitB = (i>=b.size())? 0 : b[b.size()-1-i] - '0';
            int tmp = (bitA + bitB + carry)%2;
            carry = (bitA + bitB + carry)/2;
            rlt.insert(rlt.begin(), tmp+'0');
        }
        if(carry == 1) rlt.insert(rlt.begin(), '1');
        return rlt;
    }
};
