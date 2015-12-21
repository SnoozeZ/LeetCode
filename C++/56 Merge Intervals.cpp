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
    /*   
    //My solution
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals; 
        vector<Interval> rlt;
        sort(intervals.begin(), intervals.end(), cmp);
        
        Interval tmp = intervals[0];
        for(int i = 0; i < intervals.size()-1; i++){
            if(tmp.end >= intervals[i+1].start){
                tmp.end = max(tmp.end, intervals[i+1].end);
            }else{
                Interval newIt(tmp.start, tmp.end);
                rlt.push_back(newIt);
                tmp.start = intervals[i+1].start;
                tmp.end = intervals[i+1].end;
            }
        }
        rlt.push_back(tmp);
        return rlt;
    }*/
    
    //same idea, but more concise solution
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> rlt;
        sort(intervals.begin(), intervals.end(), cmp);
        for(Interval it : intervals){
            if(rlt.empty() || rlt.back().end < it.start)
                rlt.push_back(it);
            else
                rlt.back().end = max(rlt.back().end, it.end);
        }
        return rlt;
    }
    
    
    bool static cmp(Interval it1, Interval it2){
        if(it1.start != it2.start)
            return it1.start < it2.start;
        else
            return it1.end < it2.end;
    }
};
