class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> rlt;
        if(s=="") return rlt;
        set<string> store;
        store.insert(s);
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == '+' && s[i] == s[i+1]){
                string tmp = flip(s, i);
                if(store.find(tmp) == store.end())
                    store.insert(tmp);
            }
        }
        store.erase(s);
        for(auto s : store){
            rlt.push_back(s);
        }
        return rlt;
    }
    
    string flip(string ss, int pos){
        string s = ss;
        s[pos++] = '-';
        s[pos] = '-'; 
        return s;
    }
};
