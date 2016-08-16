// Construct a Trie first, then what is differnet from the Word Search I, is to pass a extra pointer of TrieNode.
// At each step, check continue searching or not based on the TrieNode->next,
// also, check put as result of not based on the TrieNode->isWord.

class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> next;
    TrieNode () {
        isWord = false;
    }
};

class Solution {
private:
    TrieNode* root;
    int m,n;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> result;
        if (board.empty() || words.empty()) return vector<string>(result.begin(), result.end());
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        
        root = new TrieNode();
        
        buildTrie(words);
        
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, visit, i, j, "", root, result);
            }
        }
        return vector<string>(result.begin(), result.end());
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int i, int j,
             string word, TrieNode *cur, set<string>& result) {
        if (i<0 || i>=m || j<0 || j>=n || visit[i][j]) {
            return;
        }
        
        char curChar = board[i][j];
        if(cur->next[curChar]==NULL){
            return;
        } else if (cur->next[curChar]->isWord) {
            // Is word.
            word += curChar;
            result.insert(word);
            cur = cur->next[curChar];
        } else {
            // Not word.
            word += curChar;
            cur = cur->next[curChar];
        }
        visit[i][j] = true;
        dfs(board, visit, i+1, j, word, cur, result);
        dfs(board, visit, i-1, j, word, cur, result);
        dfs(board, visit, i, j+1, word, cur, result);
        dfs(board, visit, i, j-1, word, cur, result);
        visit[i][j] = false;
    }
    
    void buildTrie(vector<string>& words) {
        for (string word : words) {
            TrieNode* cur = root;
            for (char c : word){
                if (cur->next[c] == NULL){
                    cur->next[c] = new TrieNode();
                }
                cur = cur->next[c];
            }
            cur->isWord = true;
        }
    }
};
