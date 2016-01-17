class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string, int> map;// => might leads to TLE
        vector<int> vec(words.size());
        //construct tag for each string
        for(int i = 0; i < words.size(); i++){
             for(auto c : words[i])
                 vec[i] |= 1<<(c - 'a');
         }
         
        //let's compare
        int rlt = 0;
        for(int i = 0; i < int(words.size()-1); i++){
            for(int j = i+1; j < words.size(); j++){
                if((vec[i] & vec[j]) != 0) continue;
                rlt = max(rlt, int(words[i].size() * words[j].size()));
            }
        }
        return rlt;
    }
};
    
