ass Solution {
public:
    string convertToTitle(int n) {
        string rlt = "";
        while(n != 0){
            int tmp = (n-1) % 26;
            char c = 'A' + tmp;
            rlt = c + rlt;
            n = (n-1)/26;
        }
        return rlt;
    }
};
