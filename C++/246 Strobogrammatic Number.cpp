class Solution {
public:
    bool isStrobogrammatic(string num) {
        for(int i = 0; i < num.size(); i++){
            int j = num.size() - i - 1;
            if(num[i] != '1' && num[i] != '6' && num[i] != '9' &&num[i] != '8' &&num[i] != '0') return false;
            if(num[i] == '6') 
                if(num[j] != '9') return false;
            if(num[i] == '9') 
                if(num[j] != '6') return false;
            if(num[i] == '1') 
                if(num[j] != '1') return false;
            if(num[i] == '8') 
                if(num[j] != '8') return false;
            if(num[i] == '0') 
                if(num[j] != '0') return false;
        }
        return true;
    }
};
