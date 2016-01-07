class Solution {
public:
    int minDistance(string word1, string word2) {
        //special cases
        if(word1 == "" || word2 == "") return max(word1.size(), word2.size());
        
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> m(size1+1, vector<int>(size2+1, 0));
        
        //init the matrix
        for(int i = 0; i <= size1; i++) m[i][0] = i;
        for(int j = 0; j <= size2; j++) m[0][j] = j;
        
        //not at the boundry
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                int tmp1 = m[i-1][j] + 1;
                int tmp2 = m[i][j-1] + 1;
                int tmp3 = word1[i-1]==word2[j-1] ? m[i-1][j-1] : m[i-1][j-1]+1;
                m[i][j] = min(tmp1, min(tmp2, tmp3));
            }
        }
        return m[size1][size2];
    }
};
