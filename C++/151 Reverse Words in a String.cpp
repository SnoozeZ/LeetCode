class Solution {
public:
    void reverseWords(string &s) {//O(n), 4ms
        if(s == "") return;
        deque<string> words;
        string result;
        split(s,' ', words);
        while(!words.empty()){
            result += words.back();
            result += ' ';
            words.pop_back();
        }
        if(result.size() > 0) result.pop_back();
        s = result;

    }
    //self define split function
    deque<string> split(string str, char delim, deque<string> &elems){
        stringstream ss(str);
        string item;
        while(getline(ss, item, delim)){
            if(item != "")
                elems.push_back(item);
        }
        return elems;
    }
};