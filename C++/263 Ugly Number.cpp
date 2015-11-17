//??
class Solution {
public:
    bool isUgly(int num) {
        if(num == 1) return true;
        while(num>=2){
            if(num%2==0) num = num/2;
            else if(num%3==0) num = num/3;
            else if(num%5==0) num = num/5;
            else return false;
        }
        return num==1;
    }
};
