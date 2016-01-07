class Solution {
public:
    bool isMatch(string s, string p) {
        //pruning
        int count = 0;
        for(auto c : p){
            if(c!='*') count++;
        }
        if(count > s.size()) return false;
        
        //init
        vector<vector<bool>> match(s.size()+1, vector<bool>(p.size()+1));
        match[0][0] = true;
        //for the pattern start with "****"
        for(int i = 0; i < p.size(); i++){
            if(p[i] == '*')
                match[0][i+1] = true;
            else
                break;
        }
        //start
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(p[j-1] == '*'){
                    match[i][j] = match[i-1][j] || match[i][j-1] || match[i-1][j-1];
                }else{
                    if(s[i-1] == p[j-1] || p[j-1] == '?')
                        match[i][j] = match[i-1][j-1];
                }
            }
        }
        
        return match.back().back();
        
    }
};
