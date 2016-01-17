//DP m[i][j] = m[i][j-1]               -> if t[i] != s[j]
//           = m[i][j-1] + m[i-1][j-1] -> if t[i] == s[j]
class Solution {
public:
    int numDistinct(string s, string t) {
        int size1 = t.size();
        int size2 = s.size();
        if(size1 > size2) return 0;
        vector<vector<int>> m(size1+1, vector<int>(size2+1, 0));
        for(int i = 0; i < size2+1; i++)
            m[0][i] = 1;
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(t[i-1] != s[j-1])
                    m[i][j] = m[i][j-1];
                else
                    m[i][j] = m[i][j-1] + m[i-1][j-1];
            }
        }
        return m.back().back();
    }
}
