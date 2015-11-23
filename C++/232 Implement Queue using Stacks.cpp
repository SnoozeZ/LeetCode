//time complexity is O(n)
/*class Queue {
public:
    stack<int> s;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while(s.size() > 1){
            tmp.push(s.top());
            s.pop();
        }
        s.pop();
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return s.top();
        stack<int> tmp;
        int rlt;
        while(s.size() > 1){
            tmp.push(s.top());
            s.pop();
        }
        rlt = s.top();
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
        return rlt;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};*/

//time complexity is O(1)
class Queue {
public:
    stack<int> si;
    stack<int> so;// store the element that been reversed.
    // Push element x to the back of queue.
    void push(int x) {
        si.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(so.empty()){
            while(!si.empty()){
                so.push(si.top());
                si.pop();
            }
        }
        so.pop();
    }

    // Get the front element.
    int peek(void) {
        if(so.empty()){
            while(!si.empty()){
                so.push(si.top());
                si.pop();
            }
        }
        return so.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (si.size() + so.size()) == 0;
    }
};
