iclass Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int s1 = s.size(), s2 = t.size();
        if(abs(s1 - s2)>=2) return false;
        
        if(s1 == s2){
            return sizeEqual(s, t);
        }else{
            return s1>s2 ? sizeNotEqual(s, t) : sizeNotEqual(t, s);
        }
        
    }
    
    bool sizeEqual(string s, string t){
        int count = 0;  //number of diffs
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i])
                if(++count > 1)
                    return false;
        }
        return count == 1;
    }
    
    bool sizeNotEqual(string s, string t){
        //s is longer than t
        int size = t.size();
        int count=0;    //number of insert
        for(int i = 0; i < size; i++){
            if(count == 0){
                if(s[i] != t[i]){
                    count++;
                    i--;        //compare this position one more time
                } 
            }else if(count == 1){
                if(s[i+1] != t[i]) count++;
            }else{
                return false;
            }
        }
        return count <= 1;
        
    }
};
