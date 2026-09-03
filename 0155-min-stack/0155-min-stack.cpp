class MinStack {
private:
    stack<long long> s;
    long long mins;

public:
    MinStack() {}

    void push(int value) {
        if (s.empty()) {
            s.push(value);
            mins = value;
        } else if (mins > value) {
            s.push(2LL * value - mins);
            mins = value;
        } else
            s.push(value);
    }

    void pop() {
        if (s.top() < mins) {
            mins = 2 * mins - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < mins)
            return mins;
        else
            return s.top();
    }

    int getMin() { return mins; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */