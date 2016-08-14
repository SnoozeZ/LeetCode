// Very interesting problem.
// Use map to count the # of occurance of chars.
// When noticing that we have to choose the char that has the max #, use heap;
// The point is that! Pop the char that already used, cache it, and insert into heap later.

class Solution {
public:
    string rearrangeString(string str, int k) {
        // Record all chars.
        int len = str.size();
        unordered_map<char, int> charCount;
        for (char c: str) charCount[c]++;
        if(k==0) return str;

        // Construct the heap.
        priority_queue<pair<int, char>> heap;
        for (auto p : charCount) heap.push(make_pair(p.second, p.first));
        
        // Construct the new string
        string result = "";
        while(!heap.empty()) {
            vector<pair<int, char>> cache;
            int times = min(k, len);
            for(int i = 0; i < times; i++, len--) {
                if(heap.empty()) return "";     // At this point, we have to use chars in cache, it's invalid.
                pair<int, char> top = heap.top();
                heap.pop();
                result.push_back(top.second);
                cache.push_back(top);
            }
            for (auto p: cache) {
                if (--p.first > 0) heap.push(p);
            }
        }
        
        return result;
        
    }
};
