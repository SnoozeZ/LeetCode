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

/*
// Better DFS. At each step, have two choices: add current char or add the counter.

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        helper(word, 0, "", result, 0);
        return result;
    }
    
    void helper(string word, int pos, string cur, vector<string>& result, int count) {
        if(pos == word.size()) {
            if(count > 0) cur += to_string(count);
            result.push_back(cur);
            return;
        }
        // Two choices.
        helper(word, pos+1, cur, result, count+1);
        helper(word, pos+1, cur + (count > 0 ? to_string(count):"") + word[pos], result, 0);
    }
};*/
