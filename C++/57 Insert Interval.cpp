/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> rlt;
        
        bool passOverlap = false;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].end < newInterval.start)//before newInterval
                rlt.push_back(intervals[i]);
            else if(intervals[i].start > newInterval.end){//after newInterval
                if(!passOverlap){
                    passOverlap = true;
                    rlt.push_back(newInterval);//first time come to here, add newInterval into rlt
                }
                rlt.push_back(intervals[i]);
            }
            else{
                //overlap with newInterval
                newInterval = merge(intervals[i], newInterval);
            }
        }
        
        if(!passOverlap){// no interval after newInterval
            rlt.push_back(newInterval);
        }
        return rlt;
        
    }
    
    Interval merge(Interval i1, Interval i2){
        int start = min(i1.start, i2.start);
        int end = max(i1.end, i2.end);
        return Interval(start, end);
    }
};
