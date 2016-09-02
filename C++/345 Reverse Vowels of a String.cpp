class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right) {
            while(left < s.size() && !isVowel(s[left])) left ++;
            while(right >=0 && !isVowel(s[right])) right--;
            if(left <= right){ 
                swap(s[left], s[right]);
                left ++, right--;
            }
        }
        return s;
    }
    
    bool isVowel(char c) {
        bool tmp1 = c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        bool tmp2 = c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
        return tmp1 || tmp2;
    }
};
