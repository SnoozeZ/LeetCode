// Time O(1) and space O(k). 
// We have to use queue to record the necessary info (The vals that have been passed). 

class MovingAverage {
private:
    int windowSize;
    int totalVal;
    queue<int> nums;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        totalVal = 0;
        windowSize = size;
    }
    
    double next(int val) {
        totalVal += val;
        if (nums.size() >= windowSize) {
            totalVal -= nums.front();
            nums.pop();
        }
        nums.push(val);
        return (double) totalVal / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
