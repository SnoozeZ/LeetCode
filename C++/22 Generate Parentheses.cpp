//0ms, time O(n^2)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rlt;
        if(!n) return rlt;
        
        DFS(rlt, n, n, "");
        
        return rlt;
    }
    
    void DFS(vector<string> &rlt, int leftCount, int rightCount, string curString ){
        //leftCount is the amount of unused '('
        if(rightCount < leftCount) return;
        if(rightCount == 0 && leftCount == 0) rlt.push_back(curString);
        if(leftCount > 0)
            DFS(rlt, leftCount-1, rightCount, curString+'(');
        if(rightCount > 0)
            DFS(rlt, leftCount, rightCount-1, curString+')');
        
    }
};
