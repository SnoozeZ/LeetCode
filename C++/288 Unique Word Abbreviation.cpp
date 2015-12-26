class ValidWordAbbr {
public:
    unordered_map<string, int> abbrCount;
    unordered_set<string> wordSet;
    ValidWordAbbr(vector<string> &dictionary) {
        for(string word : dictionary){
            if(wordSet.find(word) == wordSet.end())//a word might appear more than once
                abbrCount[abbr(word)]++;
            wordSet.insert(word);
        }
    }

    bool isUnique(string word) {
        if(wordSet.find(word) != wordSet.end())// word in the dictionary
            return abbrCount[abbr(word)] < 2;
        else // word not in dictionary
            return abbrCount.find(abbr(word)) == abbrCount.end();
    }
    
    string abbr(string word){
        if(word.size() > 2)
            return word.front() + to_string(word.size()-2) + word.back();
        else
            return word;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
