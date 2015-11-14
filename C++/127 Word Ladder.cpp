//BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int wordLen = beginWord.size(), rlt=1;
        
        if(wordList.find(beginWord) != wordList.end()){
            wordList.erase(beginWord);
        }
        
        queue<string> q;
        q.push(beginWord);
        q.push("#");//mark layer
        while(!q.empty()){
            bool flag = false;
            string curWord = q.front();
            q.pop();
            if(q.front() == "#") flag = true;//Here comes a new level
            if(curWord == endWord){return rlt;};
            if(curWord == "#"){rlt++;continue;}
            
            for(int i=0; i<wordLen; i++){
                for(char c = 'a'; c!='z'; c++){
                    string tmpWord = curWord;
                    tmpWord[i] = c;
                    if(wordList.find(tmpWord) != wordList.end()){
                        q.push(tmpWord);
                        wordList.erase(tmpWord);
                    }
                }
            }
            if(flag)
                q.push("#");
        }
        return 0;
        
    }
};
