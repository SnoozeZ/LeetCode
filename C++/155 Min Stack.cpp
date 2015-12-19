class MinStack {
public:
    void push(int x) {
        s.push(x);
        if(min.empty() || x<=min.top())
            min.push(x);
    }

    void pop() {
        if(min.top() == s.top())
            min.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
private:
    stack<int> s;
    stack<int> min;
};
