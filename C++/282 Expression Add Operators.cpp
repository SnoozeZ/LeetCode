class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> rlt;
        dfs(num, target, "", 0, rlt, 0);
        return rlt;
    }
    
    void dfs(string num, long target, string curEq, long curVal, vector<string>& rlt, long preNum){
        //success
        if(num == "" && curVal == target){
            rlt.push_back(curEq);
        }
        //let's go
        for(int i = 1; i <= num.size(); i++){
            string curStr = num.substr(0, i);
            string next = num.substr(i);
            //long curNum = stoi(curStr.c_str());
            long curNum = stol(curStr);
            //when head is 0
            if(curStr[0] == '0' && curStr.size() > 1) continue;
            
            if(curEq != ""){
                //not at the begining
                dfs(next, target, curEq + "+" + curStr, curVal + curNum, rlt, curNum);//+
                dfs(next, target, curEq + "-" + curStr, curVal - curNum, rlt, -curNum);//-
                //* A bit complex
                long newCurVal = (curVal - preNum) + (preNum * curNum);
                long newPreNum = preNum * curNum;
                dfs(next, target, curEq+"*"+curStr, newCurVal, rlt, newPreNum);
            }else{
                //begining
                dfs(next, target, curEq + curStr, curNum, rlt, curNum);
            }
        }
        return;
    }
};
