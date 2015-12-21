class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;
        for(char c : s) map[c]++;
        int count = 0;
        for(auto p : map){
            if(p.second%2 == 1)
                count++;
            if(count == 2) return false;
        }
        return true;
    }
};
