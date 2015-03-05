#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //version 1. Runtime at LeetCode OJ is 23 ms. Time complexity is O(n^3)
    bool wordBreak_v1(string s, unordered_set<string> &dict) {
        int size = s.size();
        if(size == 0) return true;
        vector<vector<bool> > matrix(size, vector<bool> (size,false));
        for(int i =0; i<size; i++){
            if(dict.find(s.substr(i,1)) != dict.end()){
            matrix[i][i] = true;
            }else{
                matrix[i][i] = false;
            }
        }
        for(int l = 2; l<=size; l++){
            for(int i=0; i<size-l+1; i++){
                int j = i+l-1;
                matrix[i][j] = false;
                for(int k = i; k<j; k++){
                    if(k == i){ //may be a new word
                        string tmp = s.substr(k,l);
                        if(dict.find(tmp) != dict.end()){
                            matrix[i][j] = true;
                            break;
                        }
                    }
                    if(matrix[i][k]&& matrix[k+1][j]){ //two sub words
                        matrix[i][j] = true;
                        break;
                    }
                }
            }
        }
        return matrix[0][size - 1];
    }
    //Version 2, runtime at LeetCode OJ is 4ms.  Time complexity is O(n^2)
    //In the version 1, the "for" of the left boundary of the "s" is unnecessary.
    bool wordBreak_v2(string s, unordered_set<string> &dict){
        int size = s.size();
        vector<bool> table(size+1,false);
        table[0] = true;
        //table[0] = (dict.find(s.substr(0,1)) != dict.end());
        for(int i = 1; i<size+1; i++){
            for(int j = i-1; j>=0; j--){
                if(table[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    table[i] = true;
                    break;
                }
            }
        }
        return table[size];
    }
};

int main(){
    unordered_set<string> dict;
    dict.insert("a");
    dict.insert("bcd");
    dict.insert("bc");
    string s = "bcdb";

    Solution mySolution;
    bool result = mySolution.wordBreakv_2(s, dict);
    cout<<result;
    system("pause");
}