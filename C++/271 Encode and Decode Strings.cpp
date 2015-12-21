class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_str;
        for(string s : strs){
            encoded_str += to_string(s.size()) + '#' + s;
        }
        return encoded_str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int pos = 0;
        while(true){
            int newPos = s.find('#', pos);
            if(newPos == string::npos) break;
            int len = stoi(s.substr(pos, newPos-pos));
            strs.push_back(s.substr(newPos+1, len));
            pos = newPos + len + 1;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
