class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> match(m+1, vector<bool>(n+1, false));
        //init
        match[0][0] = true;
        for(int i = 1; i <= n; i++){
            if(p[i-1] == '*' && (match[0][i-1] || match[0][i-2]))   // very important here
                match[0][i] = true;
        }
        //go
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '.'){
                    match[i][j] = match[i-1][j-1];
                }else if(p[j-1] != '.' && p[j-1] != '*'){
                    match[i][j] = match[i-1][j-1] && (p[j-1] == s[i-1]);
                }else{
                    // the situation of "*"
                    if(match[i][j-1] || match[i][j-2]){ // match 1 or 0 preceding element
                        match[i][j] = true;
                    }else{
                        if((s[i-1] == p[j-2] || p[j-2] == '.') && match[i-1][j])
                            match[i][j] = true;
                    }
                }
            }
        }
        //return 
        return match[m][n];
    }
};
