class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        vector<int> record(length+1, 0);
        //pre
        for(vector<int> update : updates){
            int startIdx = update[0];
            int endIdx = update[1];
            int incValue = update[2];
            record[startIdx] += incValue;
            record[endIdx+1] -= incValue;
        }
        //do it
        int current = 0;
        for(int i=0; i<length;i++){
            current += record[i];
            result[i] = current;
        }
        return result;
    }
};
