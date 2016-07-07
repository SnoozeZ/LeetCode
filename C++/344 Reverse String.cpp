// class Solution {
// public:
//     string reverseString(string s) {
//         size_t length = s.size();
//         if(length < 2) return s;
//         for(int i = 0; i < length/2; i++){
//             swap(s[i], s[length-i-1]);
//         }
//         return s;
//     }
// };

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
