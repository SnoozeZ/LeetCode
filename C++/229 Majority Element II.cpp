//time O(n), space O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> rlt;
        int num1, num2, count1=0, count2=0;
        for(int i:nums){
            if(count1!=0 && i == num1){count1++; continue;}
            if(count2!=0 && i == num2){count2++; continue;}
            if(0 == count1){num1 = i; count1++; continue;}
            if(0 == count2){num2 = i; count2++;continue;}
            count1--; count2--;
        }
        
        count1=0;
        count2=0;
        for(int i:nums){
            if(i == num1){count1++;}
            if(i == num2){count2++;}
        }
        if(count1 > nums.size()/3) rlt.push_back(num1);
        if(num1!=num2 && count2 > nums.size()/3) rlt.push_back(num2);
        return rlt;
        
    }
};
