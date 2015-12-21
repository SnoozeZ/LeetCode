class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> rlt;
        for(string s : strings){
            string key = "";
            for(int i = 0; i < s.size()-1; i++){
                int tmp = s[i]-s[i+1]>=0 ? s[i]-s[i+1] : 26+s[i]-s[i+1];
                key += to_string(tmp) + ",";
            }
            map[key].push_back(s);
        }
        for(auto m : map){
            sort(m.second.begin(), m.second.end());
            rlt.push_back(m.second);
        }
        return rlt;
    }
};
