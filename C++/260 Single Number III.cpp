class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {//20ms, time O(n), space O(1)
        int tmp1 = 0, tmp2 = 0, tmp3 = 0, devideNum;
        vector<int> rlt;
        if(nums.size()==0) return rlt;
        
        for(auto num : nums){// first traverse
            tmp1 ^= num;
        }
            
        devideNum = getDevideNum(tmp1);
        
        for(auto num : nums){//second traverse
            if((num & devideNum) == devideNum)
                tmp2 ^= num;
            else
                tmp3 ^= num;
        }
        
        
        rlt.push_back(tmp2);
        rlt.push_back(tmp3);
        return rlt;
    }
    
    
    int getDevideNum(int num){
        //find the index of the first 1(from right to left)
        int index = 1;
        while((num & 1) == 0){
            index = index<<1;
            num = num>>1;
            cout<<"fuck";
        }
        return index;
    }
    
};
