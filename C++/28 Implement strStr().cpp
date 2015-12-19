class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        if(needle == "") return 0;
        for(int i = 0; i<haystack.size()-needle.size()+1; i++){
            int k = i;
            for(int j = 0; j<needle.size(); j++){
                if(haystack[k] == needle[j]){
                    if(j == needle.size()-1)
                        return i;
                    k++;
                }else{
                    break;
                }
            }
        }
        return -1;
    }
};
