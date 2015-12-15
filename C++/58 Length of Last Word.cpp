class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        int pos1=0, pos2=0;
        for(pos2 = s.size()-1; pos2>=0; pos2--){
            if(s[pos2]!= ' ')
                break;
        }
        
        for(pos1 = pos2; pos1>=0; pos1--){
            if(s[pos1]==' ')
                break;
        }
        
        return pos2 - pos1;
    }
};
