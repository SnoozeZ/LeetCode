#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Runtime at LeetCode OJ is 42 ms.
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        vector<bool> dpInfo = dp(s, wordDict);
        if(dpInfo[s.size()])//WTF!!
            wordBreak(dpInfo, result, "", s, wordDict, 0, s.size());
        return result;
    }
    //helperSlow time exceed.
    vector<string> helperSlow(vector<bool> dpInfo, string s, unordered_set<string>& wordDict, int begin, int end){
        vector<string> tmp;
        if(begin > end){
            tmp.push_back("");
            return tmp;
        }
        for(int i = 1; i <= end-begin+1; i++){
            string subString = s.substr(begin,i);
            if(dpInfo[begin+i] && wordDict.find(subString) != wordDict.end()){	//found it
                vector<string> tmp2 = helperSlow(dpInfo, s, wordDict, begin+i, end);
                for(size_t j = 0; j < tmp2.size(); j++){
                    if("" == tmp2[j])
                        tmp2[j] = subString;
                    else
                        tmp2[j] = subString + " " + tmp2[j];
                }
                tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
            }
        }
        return tmp;
    }
    void wordBreak(vector<bool> dpInfo,vector<string> &result, string tmpStr, string s, unordered_set<string> dict, size_t begin, size_t end){
        for(size_t length = 1; length < s.size() - begin + 1; length++){
            string subString = s.substr(begin, length);
            if(dpInfo[begin + length] && dict.find(subString) != dict.end()){
                if(begin + length == end){
                    result.push_back(tmpStr + subString);
                    //return;
                }else{
                    wordBreak(dpInfo, result, tmpStr + subString + " ", s, dict, begin + length, end);
                }
            }
        }
    }
    vector<bool> dp(string s, unordered_set<string> &dict) {
        vector<bool> dpInfo(s.size()+1,false);
        dpInfo[0] = true;
        for(size_t i = 0; i < s.size()+1; i++){
            for(size_t j = 1; j <= i; j++){
                if(dpInfo[i-j] && dict.end() != dict.find(s.substr(i-j,j)))
                    dpInfo[i] = true;
            }
        }
        return dpInfo;
    }
};

int main(){

    string s = "catsanddog";
    std::unordered_set<std::string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");
    Solution mySolution;
    vector<string> result = mySolution.wordBreak(s, dict);
    //cout<<result;
    system("pause");
}