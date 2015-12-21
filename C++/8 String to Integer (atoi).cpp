class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int num = 0;
        int i = 0;
        int sign = 1;
        while(str[i] == ' ' && i < len) i++;
        if(str[i] == '-') {sign = -1; i++;}
        else if(str[i] == '+') i++;
        for(i; i < len; i++){
            if(str[i] > '9' || str[i] < '0') break;
            if(INT_MAX/10 < num || (INT_MAX/10 == num && INT_MAX%10 < (str[i]-'0'))){
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + str[i] - '0'; 
        }
        return num * sign;
    }
};
