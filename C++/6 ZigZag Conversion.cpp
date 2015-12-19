class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string rlt = "";
        vector<string> vec(numRows, "");
        bool flag = true;
        int pos = 0;
        for(int i=0; i < s.size(); i++){
            vec[pos]+=s[i];
            if(flag)
                pos++;
            else 
                pos--;
            if(pos == numRows-1 || pos == 0) flag = !flag;
        }
        
        for(auto s : vec){
            rlt += s;
        }
        return rlt;
    }
};
