/*class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        string ss = "", tt = "";
        char tmp = 'a';
        unordered_map<char, char> map;
        for(int i=0; i < s.size(); i++){
            if(map.count(s[i])==0){
                map[s[i]] = tmp;
                ss += tmp++;
            }else{
                ss += map[s[i]];
            }
        }
        tmp = 'a';
        map.clear();
        for(int i = 0 ; i < t.size(); i++){
            if(map.count(t[i])==0){
                map[t[i]] = tmp;
                tt += tmp++;
            }else{
                tt += map[t[i]];
            }
        }
        return ss == tt;
    }
};*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return 0;
        map<char, char> m1, m2;
        for(int i = 0; i < s.size(); i++){
            if(m1.count(s[i]) != 0)
                if(m1[s[i]] != t[i]) return false;
            if(m2.count(t[i]) !=0 ) 
                if(m2[t[i]] != s[i]) return false;
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
        return true;
    }
};
