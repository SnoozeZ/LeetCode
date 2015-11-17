//O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec;
        int pos1=0, pos2=0, pos3=0;
        vec.push_back(1);
        while(vec.size()!=n){
            int cur = min(vec[pos1]*2, min(vec[pos2]*3, vec[pos3]*5));
            if(cur == vec[pos1]*2) pos1++;
            if(cur == vec[pos2]*3) pos2++;
            if(cur == vec[pos3]*5) pos3++;
            
            vec.push_back(cur);
        }
        return vec.back();
    }
};
