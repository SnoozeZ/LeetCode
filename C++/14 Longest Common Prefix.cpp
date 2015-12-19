class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rlt = "";
        if(strs.size() == 0) return rlt;
        int minLen = INT_MAX;
        for(auto s : strs)
            minLen = min(minLen, (int)s.size());
        bool flag = true;
        for(int i = 0; i < minLen; i++){
            char c = strs[0][i];
            for(int j = 0; j <strs.size(); j++){
                if(strs[j][i] == c){
                    continue;
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag)
                rlt += c;
            else
                break;
        }
        
        return rlt;
    }
};
