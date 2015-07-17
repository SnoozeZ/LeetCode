class Solution {
public:
    string multiply(string num1, string num2) {//O(M*N), ugly and slow code
        string result="0";
        for(int i=num2.size()-1; i>=0; i--){
            string tmp = digitMultiply(num2[i]-'0', num1);
            for(int j = 0; j < num2.size()-i-1; j++)
                tmp = tmp + "0";
            result = plus(result, tmp);
        }
        while(result.front() == '0' && result.size()!=1){
            result = result.substr(1, result.size()-1);
        }
        return result;
        
    }
    string digitMultiply(int digit1, string num){
        int carry=0;
        for(int i = num.size()-1; i >= 0; i--){
            int digit2 = num[i] - '0';
            num[i] = (digit1 * digit2 + carry) % 10 + '0';
            carry = (digit1 * digit2 + carry) / 10;
        }
        if(carry != 0){
            char tmp = carry + '0';
            num = tmp + num;
        }
        return num;
    }
    
    string plus(string num1, string num2){
        if(num2.size() > num1.size()) swap(num1, num2);   //let num1 is always larger than num2
        int carry = 0;
        int lenDiff = num1.size()-num2.size();
        for(int i=num2.size()-1; i>=0; i--){
            int digit1 = num1[i+lenDiff]-'0', digit2 = num2[i]-'0';
            num1[i+lenDiff] = (digit1+digit2+carry)%10 + '0';
            carry = (digit1+digit2+carry)/10;
        }
        while(lenDiff != 0 && carry != 0){
            int digit = num1[lenDiff-1]-'0';
            num1[lenDiff-1] = (digit+carry)%10+'0';
            carry =(digit+carry)/10;
            lenDiff--;
        }
        if(carry != 0){
            char tmp = carry+'0';
            num1 = tmp+num1;
        }
        return num1;
    }
};

