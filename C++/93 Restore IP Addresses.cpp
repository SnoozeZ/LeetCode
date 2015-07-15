class Solution {//O(N^3),4ms
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return result;
        DFSHelper(string(), 0, s);
        return result;
    }
    void DFSHelper(string already, int fieldNum, string remain){
        if(fieldNum >= 4 && remain.empty()){
            already.pop_back();
            result.push_back(already);
        }
        if(fieldNum<4 && !remain.empty())
            for(int len = 1; len <= remain.size(); len++){
                string curField = remain.substr(0, len);
                if(atoi(curField.c_str())<256 && !(curField.size()>1 && curField.front()=='0')){
                    string newAlready = already+curField+".";
                    string newRemain = remain.substr(len, remain.size()-len+1);
                    DFSHelper(newAlready, fieldNum+1, newRemain);
                }else{
                    continue;
                }
            }
        return;
    }
};