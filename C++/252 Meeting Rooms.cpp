/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval i1, Interval i2){
    if(i1.start == i2.start){
        return i1.end < i2.end;
    }else{
        return i1.start < i2.start;
    }
} 
 
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        //sort
        sort(intervals.begin(), intervals.end(), cmp);
        //judge
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i].end > intervals[i+1].start)
                return false;
        }
        
        return true;
    }
};


