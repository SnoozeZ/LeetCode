//https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charCount;//change into vector will accelerate. 
        for(char c : t) charCount[c]++;
        
        int start=0, end=0, rltSize=INT_MAX, total=t.size();
        string rlt="";
        
        while(end < s.size()){//move the end pointer
            char endChar = s[end];
            if(charCount[endChar] > 0)
                total--;
            charCount[endChar]--;
            end++;
            
            while(total == 0){  //Valid!!! Move the start pointer when not satisty
                char startChar = s[start];
                if(end - start < rltSize){
                    rltSize = end - start;
                    rlt = s.substr(start, rltSize);
                }
                if(charCount[startChar] == 0)
                    total++;//wow invalid
                charCount[startChar]++;
                start++;
            }
        }
        return rlt;
        
        
    }
};
