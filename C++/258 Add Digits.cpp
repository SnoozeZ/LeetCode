/*class Solution {
public:
    int addDigits(int num) {
        while(num>=10){
            int tmp=0;
            while(num!=0){
                tmp += num%10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};*/

//Math solution
class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        return (num%9==0)?9:num%9;
        
        //another solution: return num - 9 * ((num - 1) / 9);
    }
};
