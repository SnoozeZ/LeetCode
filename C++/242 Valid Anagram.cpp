//Hash Table, time O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(auto c : s) m1[c]++;
        for(auto c : t) m2[c]++;
        
        for(auto p : m1){
            if(p.second != m2[p.first])
                return false;
        }
        return true;
    }
};
