class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> charCount;
        unordered_set<char> used;
        vector<char> rlt;
        for(char c : s) charCount[c]++;
        for(char c : s){
            charCount[c]--;
            if(used.find(c) != used.end())
                continue;
            while(!rlt.empty() && c <= rlt.back() && charCount[rlt.back()] > 0){
                used.erase(rlt.back());
                rlt.pop_back();
            }
            rlt.push_back(c);
            used.insert(c);
        }
        string ret = "";
        for(char c : rlt) ret += c;
        return ret;
    }
};
