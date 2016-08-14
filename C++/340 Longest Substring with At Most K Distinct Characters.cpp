// Two pointer and use a map to record the # of occurance.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> used;
        int size = s.size();
        int result = 0;
        int left=-1, right=-1;
        while(used.size() <= k && right != size-1) {
            char current = s[++right];
            used[current]++;
            while (used.size() > k) {
                char leftChar = s[++left];
                used[leftChar]--;
                if (used[leftChar] == 0){
                    used.erase(leftChar);
                }
            }
            result = max(result, right-left);
        }
        return result;
    }
};
