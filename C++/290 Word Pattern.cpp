class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        istringstream in(str);
        int i=0;
        for(string word; in >> word; i++){
            if(m1.count(pattern[i]) != 0){
                if(m1[pattern[i]] != word) return false;
            }else{
                m1[pattern[i]] = word;
            }
            
            if(m2.count(word) != 0){
                if(m2[word] != pattern[i]) return false;
            }else{
                m2[word] = pattern[i];
            }
        }
        return i == pattern.size();
    }
};
