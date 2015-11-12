//Not concise enough
class TrieNode {
public:
    // Initialize your data structure here.
    string val;
    bool isWord;
    map<string, TrieNode *> childMap;
    TrieNode(string val) {
        this->val = val;
        this->isWord = false;
    }
    TrieNode(){
        this->val = "";
        this->isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *ptr = root;
        for(int i =0; i < word.size(); i++){
            string curVal = ptr->val + word[i];
            if(ptr->childMap.find(curVal) != ptr->childMap.end()){
                ptr = ptr->childMap[curVal];
                if(i == word.size()-1)
                    ptr->isWord = true;
            }else{
                TrieNode *newPtr = new TrieNode(curVal);
                if(i == word.size()-1)
                    newPtr->isWord = true;
                ptr->childMap[curVal] = newPtr;
                ptr = newPtr;
            }
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *ptr = root;
        string curString = "";
        for(int i=0; i < word.size(); i++){
            curString += word[i];
            if(ptr->childMap.find(curString) != ptr->childMap.end()){
                ptr = ptr->childMap[curString];
            }else{
                return false;
            }
        }
        return ptr->isWord;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        string curString = "";
        for(int i=0; i < prefix.size(); i++){
            curString += prefix[i];
            if(ptr->childMap.find(curString) != ptr->childMap.end()){
                ptr = ptr->childMap[curString];
            }else{
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
