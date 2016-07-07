class Solution {
public:
    vector<string> digit1 = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> digit2 = {"Ten", "Eleven","Twelve", "Thirteen", "Fourteen", 
                           "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> digit3 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string rlt = "";
        
        if(num / 1000000000 > 0){
            rlt += lessThan1000(num / 1000000000) + "Billion ";
            num = num % 1000000000;
        }
        if(num / 1000000 > 0){
            rlt += lessThan1000(num / 1000000) + "Million ";
            num = num % 1000000;
        }
        if(num / 1000 > 0){
            rlt += lessThan1000(num / 1000) + "Thousand ";
            num = num % 1000;
        }
        rlt += lessThan1000(num);
        return rlt.substr(0, rlt.size()-1);
    }
    
    string lessThan1000(int num){
        if(num == 0) return "";
        
        string rlt = "";
        if(num/100 != 0){// larger than 100
            rlt += digit1[num/100-1] + " Hundred ";
            num = num%100;
        }
        rlt += lessThan100(num);
        return rlt;
    }
    
    string lessThan100(int num){
        if(num == 0) return "";
        
        string rlt = "";
        if(num/10 != 0){//  two digits
            if(num/10 > 1){//   larger than 19
                rlt += digit3[num/10-2] + " ";
                num = num%10;
                if(num > 0) rlt += digit1[num-1] + " ";
            }else{//smaller than 19
                num = num%10;
                rlt += digit2[num] + " ";
            }
        }else{//    one digits
            rlt += digit1[num-1] + " ";
        }
        return rlt;
    }
};
