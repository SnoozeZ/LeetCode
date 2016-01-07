lass Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> m;
        int left = 0, right = 0, rlt = 0;
        for(right; right < s.size(); right++){
            if(m.count(s[right]) != 0){
                //found it in the map
                m[s[right]] ++;
            }else{
                //not found
                if(m.size() < 2){
                    m[s[right]] ++;
                }else{
                    // size == 2
                    rlt = max(rlt, countMap(m));
                    while(--m[s[left++]] != 0);
                    m.erase(s[left-1]);
                    m[s[right]] ++;
                }
            }
        }
        return max(rlt, countMap(m));
    }
    
    int countMap(map<char, int> map){
        int count = 0;
        for(auto p : map){
            count += p.second;
        }
        return count;
    }
}
