//Binary search solution
/*
class Solution {
public:
    int mySqrt(int x) {
        if(0 == x || 1 == x) return x;
        int left=0, right = x, rlt=0;
        while(left<=right){
            int mid = (left+right)/2;
            //m*m will overflows the 32 bit
            if(mid > x/mid) right = mid-1;
            else if(mid < x/mid){
                left = mid+1;
                rlt = mid;
            }else return mid;
        }
        return rlt;
    }
};*/

//Newton solution
class Solution {
public:
    int mySqrt(int x) {
        if(0==x) return 0;
        double cur = (double)x/2;
        while(true){
            double newCur = (cur + (double)x/cur)/2;
            if((int)newCur == (int)cur) return newCur;
            else cur = newCur;
        }
    }
};
