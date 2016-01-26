class TrieNode{
public:
    TrieNode* children[26];
    bool isVal;
    TrieNode(){
        isVal = false;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->children[idx] == NULL){
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isVal = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(DFS(word, 0, root)) 
            return true;
        return false;
    }
    
    bool DFS(string& word, int pos, TrieNode* root){
        //JUDGE: success or not
        if(pos >= word.size()){
            return root->isVal ? true : false;
        }
        //let's search
        if(word[pos] == '.'){
            //current is '.'
            for(int i = 0; i < 26; i++){
                if(root->children[i] != NULL && DFS(word, pos+1, root->children[i]))
                    return true;
            }
        }else{
            //current is not '.'
            int idx = word[pos] - 'a';
            if(root->children[idx] != NULL && DFS(word, pos+1, root->children[idx]))
                return true;
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
