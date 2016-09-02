// Type to store info in stack: pair<isFile, pair<length, # of \t>>
typedef pair<bool, pair<int, int>> Info; 

class Solution {
public:
    int lengthLongestPath(string input) {
        int result = 0, curLength = 0;
        stack<Info> s;
        vector<Info> infos = split(input);
        for(Info info : infos) {
            while(!s.empty() && s.top().second.second >= info.second.second){ 
                curLength -= s.top().second.first + 1;
                s.pop();
            }
            s.push(info);
            curLength += info.second.first + 1;
            if(s.top().first) // is last file
                result = max(result, curLength-1);
        }
        return result;
        
    }
    
    // Helper function, split and construct Info.
    vector<Info> split(string input) {
        stringstream s(input);
        vector<Info> res;
        string tmp;
        while(getline(s, tmp, '\n')) {
            int count = 0;  // Count of \t
            int isFile = false;
            while(tmp[count] == '\t') count ++;
            tmp = tmp.substr(count);
            if(tmp.find(".") != string::npos) isFile = true;
            
            res.push_back(make_pair(isFile, make_pair(tmp.size(), count)));
        }
        return res;
    }
    
};
