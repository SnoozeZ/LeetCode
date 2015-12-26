/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
//heap, greedy, sort: time O(nlogn)
//a new interval will 1.add one new room; OR 2.add no new room.
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for(Interval it : intervals){
            if(!min_heap.empty() && min_heap.top() <= it.start)
                min_heap.pop(); // will not overlap with this end time in the future, so pop it
            min_heap.push(it.end);
        }
        return min_heap.size();
    }
    
    bool static cmp(Interval i1, Interval i2){
        if(i1.start != i2.start)
            return i1.start < i2.start;
        else
            return i1.end < i2.end;
    }
};*/

//use tree map
//direct solution: a begin time -> add one room, a end time -> delete one room 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int rlt = 0;
        map<int, int> map;
        for(Interval it : intervals){
            map[it.start]++;
            map[it.end]--;
        }
        int tmpCount = 0;
        for(auto p : map){
            tmpCount += p.second;
            rlt = max(rlt, tmpCount);
        }
        return rlt;
    }
    
    bool static cmp(Interval i1, Interval i2){
        if(i1.start != i2.start)
            return i1.start < i2.start;
        else
            return i1.end < i2.end;
    }
};



