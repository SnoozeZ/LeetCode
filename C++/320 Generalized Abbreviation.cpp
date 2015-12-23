class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> rlt;
        helper(word, 0, "", false, rlt);
        return rlt;
    }
    
    void helper(string word, int pos, string cur, bool preInt, vector<string>& rlt){
        if(pos == word.size()){
            rlt.push_back(cur);
            return;
        }
        helper(word, pos+1, cur+word[pos], false, rlt);
        if(!preInt){
            for(int i =1; i <= word.size()-pos; i++){
                helper(word, pos+i, cur+to_string(i), true, rlt);
            }
        }
        
    }
};
