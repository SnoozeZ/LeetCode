// Store every word into hashmap. Then generate the residual of each word, find it in the map.

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        set<vector<int>> result;
        unordered_map<string, int> wordIdxMap;
        for(int i = 0; i < words.size(); i++) {
            wordIdxMap[words[i]] = i;
        }
        
        // for each word
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int size = word.size();
            // find every substring
            for (int j = 0; j <= word.size(); j++) {
                string leftSubString = word.substr(0, j);       // Here is interesting.
                string rightSubString = word.substr(j, size-j); // Same as above.
                // cat back
                if(isPalindrome(rightSubString)) {
                    string tmp = leftSubString;
                    reverse(tmp.begin(), tmp.end());
                    if (wordIdxMap.count(tmp) && i != wordIdxMap[tmp]) {
                        result.insert(vector<int>({i, wordIdxMap[tmp]}));
                    }
                }
                // cat front
                if(isPalindrome(leftSubString)) {
                    string tmp = rightSubString;
                    reverse(tmp.begin(), tmp.end());
                    if (wordIdxMap.count(tmp) && i != wordIdxMap[tmp]) 
                        result.insert(vector<int>({wordIdxMap[tmp], i}));
                }
            }
        }
        return vector<vector<int>> (result.begin(), result.end());
    }
    
    bool isPalindrome(string word) {
        int size = word.size();
        for(int i = 0; i < size/2; i++) {
            if(word[i] != word[size-i-1])
                return false;
        }
        return true;
    } 
};
