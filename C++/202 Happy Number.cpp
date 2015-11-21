class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> already;
        while(true){
            int sum=0;
            while(n != 0){
                sum += pow((n%10), 2);
                n = n/10;
            }
            if(sum ==1) return true;
            else if(already.find(sum) != already.end()) return false;
            already[sum] = true;
            n = sum;
        }
    }
};
