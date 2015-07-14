class Solution {//O(N), 12ms
public:
    string simplifyPath(string path) {
        if(path == "/") return "/";
        deque<string> validPath;
        vector<string> strVec;
        split(path, '/', strVec);
        
        for(string curStr : strVec){
            if(curStr == "") continue;
            if(curStr == ".."){
                if(!validPath.empty()) validPath.pop();
            }else if(curStr == "."){
                continue;
            }else{
                validPath.push(curStr);
            }
        }
        //construct simple path
        string result = "/";
        while(!validPath.empty()){  
            result += validPath.front();
            result += "/";
            validPath.pop_front();
        }
        if(result.size()>1) result.pop_back();
        return result;
    }
    //self define split function
    vector<std::string> split(const string s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
};