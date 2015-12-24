class Solution {
public:
    unordered_map<char, char> int_map = {{'1', '1'}, {'0', '0'}, {'8', '8'}, {'9', '6'}, {'6', '9'}};
    vector<string> findStrobogrammatic(int n) {
        vector<string> rlt;
        helper(rlt, n, "");
        return rlt;
    }
    
    void helper(vector<string>& rlt, int count, string cur){
        if(count == 0){
            rlt.push_back(cur);
            return;
        }
        if(count%2 == 1){   //handle the odd situation
            helper(rlt, count-1, "1");
            helper(rlt, count-1, "8");
            helper(rlt, count-1, "0");
        }else{//handle the even situation
            helper(rlt, count-2, '1'+cur+'1');
            helper(rlt, count-2, '8'+cur+'8');
            helper(rlt, count-2, '6'+cur+'9');
            helper(rlt, count-2, '9'+cur+'6');
            if(count >2)
                helper(rlt, count-2, '0'+cur+'0');//"00" is illegal so skip it
        }
        return;
    }
};
