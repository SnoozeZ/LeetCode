class Solution {
public:
    string countAndSay(int n) {
        //corner case
        if(n == 1) return "1";
        //cool
        string rlt = "1";
        while(--n > 0){
            rlt = convert(rlt);
        }
        return rlt;
    }
    
    string convert(string str){
        //corner case
        if(str == "1") return "11";
        //go
        string rlt = "";
        int count = 1;
        int i = 0;
        for(; i < str.size()-1; i++){
            if(str[i] == str[i+1]){
                count ++;
            }else{
                //find the boundry
                rlt += to_string(count);
                rlt += str[i];
                count = 1;//key~
            }
        }
        //last time
        rlt += to_string(count);
        rlt += str[i];
        return rlt;
    }
    
    
};
