class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        vector<bool> vec(n, true);
        int rlt=0;
        for(int i =2; i < sqrt(n); i++){
            if(vec[i])
                for(int j = i*i; j < n; j+=i){
                    vec[j] = false;
                }
        }
        
        for(auto i : vec){
            if(i) rlt++;
        }
        
        return rlt-2;
    }
};
