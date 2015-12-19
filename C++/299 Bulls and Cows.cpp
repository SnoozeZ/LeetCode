/*
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        map<char, int> map;
        //find the bull
        for(int i = 0; i < secret.size(); i ++){
            if(secret[i] == guess[i])
                bull++;
            else
                map[secret[i]]++;
        }
        //find the cow
        for(int i = 0; i <secret.size(); i++){
            if(secret[i] == guess[i]) continue;
            if(map.count(guess[i]) != 0){
                cow ++;
                if(--map[guess[i]] == 0){
                    map.erase(guess[i]);
                }
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
    
};*/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m1, m2;
        int bull=0, cow=0;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bull++;
            }else{
                m1[secret[i]] != 0? m1[secret[i]]--, cow++ : m2[secret[i]]++;
                m2[guess[i]] != 0? m2[guess[i]]--, cow++ : m1[guess[i]]++;
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
    
};
