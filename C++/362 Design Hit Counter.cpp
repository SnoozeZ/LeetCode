// This solution is not good enough when hit per sec is large. The queue will consumes lots of space.
// A good way to improve is to use a map<int, int> to record # of count of each timestamp in the queue,
// meanwhile use a totalHit to record how many hit has recorded, when pop, -= the count.

class HitCounter {
private:
    queue<int> hitRecorder;
    int threshold;

public:
    /** Initialize your data structure here. */
    HitCounter() {
        threshold = 300;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        
        hitRecorder.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!hitRecorder.empty() && timestamp - hitRecorder.front() >= threshold) {
            hitRecorder.pop();
        }
        return hitRecorder.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
