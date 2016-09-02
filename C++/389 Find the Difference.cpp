// Bid Maniputation
class Solution {
public:
    char findTheDifference(string s, string t) {
        char a = 0;
        for(char c : s) a ^= c;
        for(char c : t) a ^= c;
        return a;
    }
};
