class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    // Adds a number into the data structure.
    void addNum(int num) {
        //push number
        if(max_heap.empty() || num < max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);
        //handle unbalanced situation
        if(max_heap.size() > 1 + min_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if(min_heap.size() > 1 + max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    // Returns the median of current data stream
    double findMedian() {
        if(min_heap.size() == max_heap.size())
            return (min_heap.top() + max_heap.top()) / 2.0;
        else
            return  min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
